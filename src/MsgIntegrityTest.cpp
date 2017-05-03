//============================================================================
// Name        : MsgIntegrityTest.cpp
// Author      : bulldozer00.com
//============================================================================

#include "catch.hpp"
#include <iostream>
#include <string>
#include "Poco/Crypto/Crypto.h"
#include "Poco/RandomStream.h"
#include "Poco/DigestEngine.h"
#include "Poco/HMACEngine.h"
#include "Poco/SHA1Engine.h"
#include "Poco/DigestStream.h"
#include "Poco/MD5Engine.h"

#include "Sender.h"
#include "Recipient.h"
#include "ChannelMessage.h"
#define CATCH_CONFIG_COLOUR_NONE

void printTransactionResult(bool success);

TEST_CASE( "Integrity", "[Tl]" ) {

  namespace pc = Poco::Crypto;

  //Global-wide init the lib
  pc::initializeCrypto();

  //Create the sender-receiver participants
  //in the scenario
  Sender msgSender { };
  Recipient msgRecipient { };

  //Create the raw text msg
  std::string text = "I owe you $100";
  std::cout << "message to send = "
            << text << "\n\n";

  //Compute the fingerprint and then send the message + fingerprint
  //pair to the recipient
  bool success = msgSender.sendChannelMsg(text, msgRecipient);

  printTransactionResult(success);

  //Maliciously change the message content - without
  //touching the fingerprint computed on the original untampered
  //message
  text = "You owe me $10,000";
  success = msgSender.sendAlteredChannelMsg(text, msgRecipient);

  printTransactionResult(success);

  pc::uninitializeCrypto();

}

void printTransactionResult(bool success) {

  if(success) {
    std::cout << "\nRecipient Confirmed A Successful Transmission!\n\n";
  }
  else {
    std::cout << "\nRecipient Rejected The Transmission Due To Detected Message Alterations!\n\n";
  }

}


//============================================================================
// Name        : Sha1EngineTest.cpp
// Author      : bulldozer00.com
//============================================================================

#include "catch.hpp"
#include <iostream>
#include <string>
#include "Poco/Crypto/Cipher.h"
#include "Poco/SHA1Engine.h"
#define CATCH_CONFIG_COLOUR_NONE

TEST_CASE( "Sha1Engine", "[Tl]" ) {

  namespace pc = Poco::Crypto;
  //Program-wide init the lib
  pc::initializeCrypto();

  //Create the raw text msg
  std::string text = "I owe you $100";

  //Create the engine
  Poco::SHA1Engine sha1Engine{};

  //Give the engine our message
  sha1Engine.update(text);

  //Hash the message, and then convert the
  //result into a human-readable hex string!
  std::string fingerPrint =
      sha1Engine.digestToHex(sha1Engine.digest());

  std::cout << "Fingerprint (hex) == "
            << fingerPrint << "\n"
            << "Fingerprint size (bits) == "
            << fingerPrint.size() * 4 << "\n";

  //Program-wide uninit the lib before exit
  pc::uninitializeCrypto();

}


/*
 * Sender.cpp
 *
 *  Created on: Apr 28, 2017
 *      Author: bulldozer00
 */

#include "Sender.h"
#include "Recipient.h"
#include "ChannelMessage.h"

Sender::Sender() : _sha1Engine() /*,_digestEngine(nullptr)*/ {

}

void Sender::hashMsg(const std::string& msgToSend) {
  _sha1Engine.update(msgToSend);
}

std::string Sender::fingerPrintTheMessage() {
  std::string digest = _sha1Engine.digestToHex(_sha1Engine.digest());
  _msgFingerPrint = digest;
  return digest;
}

void Sender::setTheMessage(const std::string& msgToSend) {
  _msgTxt = msgToSend;
  _msgFingerPrint.clear();
}

bool Sender::sendChannelMsg(const ChannelMsg& cmsg, Recipient& receiver) {

  std::cout << "Sender Transmitted This Channel Msg:" ;
  cmsg.printContent();
  return receiver.acceptChannelMsg(cmsg);

}

bool Sender::sendChannelMsg(const std::string& msgToSend, Recipient& receiver) {
  _msgTxt = msgToSend;

  //Create the ChannelMsg
  ChannelMsg cmsg{_msgTxt};

  //Hash the message
  _sha1Engine.reset();
  _sha1Engine.update(msgToSend);
  _msgFingerPrint = _sha1Engine.digestToHex(_sha1Engine.digest());

  cmsg.setTheFingerPrint(_msgFingerPrint);
  return sendChannelMsg(cmsg, receiver);
}

bool Sender::sendAlteredChannelMsg(const std::string& msgToSend, Recipient& receiver) {

  _msgTxt = msgToSend;

  //Create the ChannelMsg
  ChannelMsg cmsg{_msgTxt};

  //Don't Hash it
  //_sha1Engine.reset();
  //_sha1Engine.update(_msgTxt);
  //_msgSig = _sha1Engine.digestToHex(_sha1Engine.digest());

  //Reuse the hash from the unaltered message - which won't match the altered message's
  //hash
  cmsg.setTheFingerPrint(_msgFingerPrint);

  //Tamper with the message so that the hash
  //no longer applies!
  //cmsg.setTheMessage(msgToSend);
  return sendChannelMsg(cmsg, receiver);
}



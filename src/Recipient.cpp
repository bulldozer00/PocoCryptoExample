/*
 * Recipient.cpp
 *
 *  Created on: Apr 28, 2017
 *      Author: bulldozer00
 */

#include <iostream>
#include "Recipient.h"

Recipient::Recipient() : _sha1Engine() {

}

bool Recipient::acceptChannelMsg(const ChannelMsg& cm) {

  std::cout << ".....\n.....\n.....\n.....\n"
            << "Receipient Received This Channel Msg:" ;

  cm.printContent();

  return verifyMessage(cm);

}

bool Recipient::verifyMessage(const ChannelMsg& cm) {

  //extract the ClearText msg
  std::string rawTextmsg = cm.getTheTextMessage();

  //extract the received signature
  std::string rxdSig = cm.getTheFingerPrint();

  //hash the message
  _sha1Engine.reset();
  _sha1Engine.update(rawTextmsg);
  _msgSig = _sha1Engine.digestToHex(_sha1Engine.digest());

  std::cout << "Locally Generated MsgFingerPrint (hex): "
            << _msgSig << "\n";

  //compute a local signature on the ClearText msg
  if(_msgSig == rxdSig)
    return true;
  else
    return false;

}

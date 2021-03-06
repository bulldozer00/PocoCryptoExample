/*
 * ChannelMsg.cpp
 *
 *  Created on: Apr 30, 2017
 *      Author: bulldozer00
 */

#include "ChannelMessage.h"

  ChannelMsg::ChannelMsg() {}

  ChannelMsg::ChannelMsg(const std::string& txtMsg) :
      _clearTxtMsg(txtMsg) {

  }

  ChannelMsg::ChannelMsg(const char* txtMsg) {
    const int32_t MAX_MSG_SIZE = 100; //cap the input char string
    std::string temp(txtMsg, MAX_MSG_SIZE);
    for(const auto ch : temp) {
      _clearTxtMsg.push_back(ch);
    }
  }

  void ChannelMsg::setTheFingerPrint(const std::string& fingerprint) {
    _msgFingerPrint = fingerprint;
  }

  std::string ChannelMsg::getTheFingerPrint() const {
    return _msgFingerPrint;
  }

  void ChannelMsg::setTheTextMessage(const std::string& msg,
      const std::string& fingerprint) {
    clear(); //clear out the old state
    _clearTxtMsg = msg;
    _msgFingerPrint = fingerprint;
  }

  std::string ChannelMsg::getTheTextMessage() const {
    return _clearTxtMsg;
  }

  void ChannelMsg::printContent() const {
    std::cout << "\nClearTextMsg: " << "\""
              << _clearTxtMsg << "\"" << "\n";
    std::cout << "MsgFingerprint (hex): "
              << _msgFingerPrint << "\n";
  }









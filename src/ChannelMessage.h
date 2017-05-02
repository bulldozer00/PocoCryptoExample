/*
 * ChannelMessage.h
 *
 *  Created on: Apr 29, 2017
 *      Author: bulldozer00
 */

#ifndef CHANNEL_MESSAGE_H_
#define CHANNEL_MESSAGE_H_

#include <cstdint>
#include <string>
#include <iostream>
#include "Poco/SHA1Engine.h"


//The sender populates, hashes,
//serializes, and then transmits a ChannelMsg object over an
//unsecured network to the recipient. ChannelMsg is simply a wrapper
//around the message + signature pair
class ChannelMsg {

public:

  ChannelMsg();
  explicit ChannelMsg(const std::string& txtMsg);
  explicit ChannelMsg(const char* txtMsg);

  void setTheFingerPrint(const std::string& sig);
  std::string getTheFingerPrint() const;

  void setTheTextMessage(const std::string& msg);
  std::string getTheTextMessage() const;

  void printContent() const;

private:

  std::string _clearTxtMsg { };
  std::string _msgFingerPrint { };

  void clear() {
    _clearTxtMsg.clear();
    _msgFingerPrint.clear();
  }

};

#endif /* CHANNEL_MESSAGE_H_ */

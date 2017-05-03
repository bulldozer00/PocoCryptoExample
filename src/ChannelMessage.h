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

//ChannelMsg is simply a wrapper
//around the text message + fingerprint pair
//The sender populates, hashes,
//and then transmits a ChannelMsg object over an
//unsecured network to the recipient.
class ChannelMsg {

public:

  //ctors
  ChannelMsg();
  explicit ChannelMsg(const std::string& txtMsg);
  explicit ChannelMsg(const char* txtMsg);

  //setters & getters
  void setTheFingerPrint(const std::string& sig);
  std::string getTheFingerPrint() const;

  void setTheTextMessage(const std::string& msg,
      const std::string& fingerprint);
  std::string getTheTextMessage() const;

  //dump the state to the console
  void printContent() const;

private:

  //The message and fingerprint
  //representations
  std::string _clearTxtMsg { };
  std::string _msgFingerPrint { };

  void clear() {
    _clearTxtMsg.clear();
    _msgFingerPrint.clear();
  }

};

#endif /* CHANNEL_MESSAGE_H_ */

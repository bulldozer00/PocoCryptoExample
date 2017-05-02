/*
 * Sender.h
 *
 *  Created on: Apr 28, 2017
 *      Author: bulldozer00
 */

#ifndef SENDER_H_
#define SENDER_H_

#include <string>
#include "Poco/SHA1Engine.h"
#include "ChannelMessage.h"

class Recipient;
class ChannelMsg;

class Sender {
public:

  Sender();

  void hashMsg(const std::string& msgToSend);

  std::string getHashAlgorithm() const;

  std::string signTheMessage();

  void setTheMessage(const std::string& msgToSend);

  bool sendChannelMsg(const std::string& msgToSend, Recipient& receiver);

  bool sendAlteredChannelMsg(const std::string& msgToSend, Recipient& receiver);

  bool sendChannelMsg(const ChannelMsg& cmsg, Recipient& receiver);

private:

  std::string _msgTxt { };
  std::string _msgFingerPrint { };
  Poco::SHA1Engine _sha1Engine { };

};

#endif /* SENDER_H_ */

/*
 * Recipient.h
 *
 *  Created on: Apr 28, 2017
 *      Author: bulldozer00
 */

#ifndef RECIPIENT_H_
#define RECIPIENT_H_

#include "Poco/SHA1Engine.h"
#include "ChannelMessage.h"

class Recipient {
public:
  Recipient();

  bool acceptChannelMsg(const ChannelMsg& cm);

private:
  std::string _msgSig { };
  Poco::SHA1Engine _sha1Engine;

  bool verifyMessage(const ChannelMsg& cm);
};

#endif /* RECIPIENT_H_ */

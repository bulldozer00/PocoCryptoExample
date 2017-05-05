/*
 * MyCipher.h
 *
 *  Created on: May 4, 2017
 *      Author: bulldozer00
 */

#ifndef MYCIPHER_H_
#define MYCIPHER_H_

#include "Poco/Crypto/Crypto.h"
#include "Poco/Crypto/CipherKey.h"
#include "Poco/Crypto/Cipher.h"
#include "Poco/Crypto/CipherFactory.h"
#include "Poco/Exception.h"

namespace pc = Poco::Crypto;

class MyCipher {

public:
  MyCipher();

  //Since we have owning raw ptrs, we need this for
  //leak-free RAII
  ~MyCipher();

  void encryptDecrypt();

  void ioStream();

private:

  //You can get the key types supported by
  //typing openssl -h in a terminal. There is a boatload of them
  const std::string KEY_TYPE{"aes-256-cbc"};

  pc::CipherKey _cKey{KEY_TYPE};
  pc::CipherFactory& _factory;
  pc::Cipher* _cipherBox{};

};

#endif /* MYCIPHER_H_ */

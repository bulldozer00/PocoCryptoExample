/*
 *  Crypto.h
 *
 *  Created on: Apr 22, 2017
 *      Author: adasi_000
 */

#ifndef CRYPTO_H_
#define CRYPTO_H_

#include <cstdint>
#include <string>
#include "Poco/Crypto/Crypto.h"
#include "Poco/Crypto/CipherFactory.h"
#include "Poco/Crypto/Cipher.h"
#include "Poco/Crypto/RSAKey.h"

namespace pc = Poco::Crypto;

class Crypto {

public:

  Crypto();
  virtual ~Crypto();

  pc::RSAKey& getRsaKey() {
   return _rsaKey;
  }

private:

  pc::CipherFactory& _factory;

  pc::Cipher* _pRSACipherBox{};
  pc::RSAKey _rsaKey;
};

class Encrypter : public Crypto {

public:

  Encrypter ();
  virtual ~Encrypter() {}

private:

};

class Decrypter : public Crypto {

public:

  Decrypter ();
  virtual ~Decrypter() {}

private:

};

#endif /* CRYPTO_H_ */


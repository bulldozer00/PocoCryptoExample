/*
 *  Crypto.cpp
 *
 *  Created on: Apr 22, 2017
 *      Author: adasi_000
 */

#include "Crypto.h"

Crypto::Crypto() :
  _factory(pc::CipherFactory::defaultFactory()),
  _rsaKey(pc::RSAKey::KL_1024, pc::RSAKey::EXP_SMALL) {

  _pRSACipherBox = _factory.createCipher(_rsaKey);

}

Crypto::~Crypto() {
  delete _pRSACipherBox;
}

Encrypter::Encrypter() : Crypto() {

}

Decrypter::Decrypter() : Crypto() {

}


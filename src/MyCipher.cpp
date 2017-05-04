/*
 * MyCipher.cpp
 *
 *  Created on: May 4, 2017
 *      Author: bulldozer00
 */

#include <iostream>
#include "MyCipher.h"

MyCipher::MyCipher() : _factory(pc::CipherFactory::defaultFactory()),
_cipherBox(_factory.createCipher(_cKey)) {

  //Global-wide lib init (inits openssl)
  pc::initializeCrypto();

  std::cout << "Key Name = " << _cKey.name() << "\n"
            << "Key Size = " << _cKey.keySize() * 8 << " bits\n";

}

MyCipher::~MyCipher() {

  delete _cipherBox;

  //Global-wide lib uninit (uninits openssl)
  pc::uninitializeCrypto();

}


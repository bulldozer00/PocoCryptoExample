/*
 * MyCipher.cpp
 *
 *  Created on: May 4, 2017
 *      Author: bulldozer00
 */

#include <iostream>
#include "MyCipher.h"
#include "Poco/Crypto/CryptoStream.h"
#include "Poco/FileStream.h"
#include "Poco/StreamCopier.h"

MyCipher::MyCipher() : _factory(pc::CipherFactory::defaultFactory()),
_cipherBox(_factory.createCipher(_cKey)) {

  //Global-wide lib init (inits openssl)
  pc::initializeCrypto();

  std::cout << "Key Name = " << _cKey.name() << "\n"
            << "Key Size = " << _cKey.keySize() * 8 << " bits\n";
}

void MyCipher::ioStream() {

  // Create an output stream that will encrypt all data going through it
  // and write pass it to the underlying file stream.
  Poco::FileOutputStream sink("InOutTestFiles/Encrypted.txt");
  pc::CryptoOutputStream encryptor(sink, _cipherBox->createEncryptor());

  std::cout << "sink status = " <<  sink.good() << "\n";

  Poco::FileInputStream source("InOutTestFiles/ClearTxt.txt");

  std::cout << "source status = " <<  source.good() << "\n";

  Poco::StreamCopier::copyStream(source, encryptor);

  // Always close output streams to flush all internal buffers
  encryptor.close();
  sink.close();

}

void MyCipher::encryptDecrypt() {

  std::string plainText = "This is my secret information";
  std::string encrypted =
      _cipherBox->encryptString(plainText, pc::Cipher::ENC_BASE64);
  std::string decrypted =
      _cipherBox->decryptString(encrypted, pc::Cipher::ENC_BASE64);

  std::cout << (plainText == decrypted) << "\n";

}

MyCipher::~MyCipher() {

  delete _cipherBox;

  //Global-wide lib uninit (uninits openssl)
  pc::uninitializeCrypto();

}


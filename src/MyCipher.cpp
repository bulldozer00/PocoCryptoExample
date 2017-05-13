/*
 * MyCipher.cpp
 *
 *  Created on: May 4, 2017
 *      Author: bulldozer00
 */

#include <iostream>
#include <sstream>
#include <iomanip>
#include "MyCipher.h"
#include "Poco/Crypto/CryptoStream.h"
#include "Poco/Crypto/CipherKeyImpl.h"
#include "Poco/FileStream.h"
#include "Poco/StreamCopier.h"

MyCipher::MyCipher() : _factory(pc::CipherFactory::defaultFactory()),
_cipherBox(_factory.createCipher(_cKey)) {

  //Global-wide lib init (inits openssl)
  pc::initializeCrypto();

  std::cout << "Key Name = " << _cKey.name() << "\n"
            << "Key Size = " << _cKey.keySize() * 8 << " bits\n";

  const pc::CipherKeyImpl::ByteVec& byteVec = _cKey.getKey();

  //Convert each char to a hex byte
  std::ostringstream oss{"Key "}; 
  for(char ch : byteVec) {

    uint16_t hexByte =
        static_cast<uint16_t>(ch) & 0xFF;

    oss << std::hex << hexByte;

  }

  oss << "\n";

  std::cout << oss.str();

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


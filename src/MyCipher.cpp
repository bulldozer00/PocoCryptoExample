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
#include "Poco/Crypto/CryptoTransform.h"
#include "Poco/FileStream.h"
#include "Poco/StreamCopier.h"

MyCipher::MyCipher() : _factory(pc::CipherFactory::defaultFactory()),
_cKey(KEY_TYPE), _cipherBox(_factory.createCipher(_cKey)) {

  //Global-wide lib init (inits openssl library)
  pc::initializeCrypto();

  std::cout << "Key Name = " << _cKey.name() << "\n"
            << "Key Size = " << _cKey.keySize() * 8 << " bits\n";

  const pc::CipherKeyImpl::ByteVec& byteVec = _cKey.getKey();

  //Convert each char to a hex byte
  std::ostringstream oss{"Cipher Key "};

  for(char ch : byteVec) {

    //Cast each char to a uint16_t
    //so that we can print it out
    //as a series of readable hex digits
    //Note: Casting to uint8_t won't work
    uint16_t hexByte =
        static_cast<uint16_t>(ch) & 0xFF;

    oss << std::hex << hexByte;

  }

  oss << "\n";

  std::cout << oss.str();

}

void MyCipher::encryptFile() {

  // Create an output stream that will encrypt all data going through it
  // and write pass it to the underlying file stream.
  Poco::FileOutputStream sink("InOutTestFiles/CipherTxt.txt");

  pc::CryptoTransform* xformer = _cipherBox->createEncryptor();

  pc::CryptoOutputStream encryptor(sink, xformer);

  Poco::FileInputStream source("InOutTestFiles/ClearTxt.txt");

  Poco::StreamCopier::copyStream(source, encryptor);

  // Always close output streams to flush all internal buffers
  encryptor.close();
  sink.close();

  //Note: CryptoOutputStream takes ownership
  //of the dynamically allocated CryptoTransform object. Thus,
  //the following line of code will cause a double delete seg fault
  //delete xformer;

}

void MyCipher::decryptFile() {

  // Create an output stream that will decrypt all data going through it
  // and pass it to the underlying file stream.
  Poco::FileOutputStream sink("InOutTestFiles/ClearTxt.txt");

  pc::CryptoTransform* xformer = _cipherBox->createDecryptor();

  pc::CryptoOutputStream decryptor(sink, xformer);

  Poco::FileInputStream source("InOutTestFiles/CipherTxt.txt");

  Poco::StreamCopier::copyStream(source, decryptor);

  // Always close output streams to flush all internal buffers
  decryptor.close();
  sink.close();

  //Note: CryptoOutputStream takes ownership
  //of the dynamically allocated CryptoTransform object. Thus,
  //the following line of code will cause a double delete seg fault
  //delete xformer;

}

//Encrypt a ClearText message. Returns the
//CipherText version of the message
std::string MyCipher::encryptClearTextMsg(const std::string& msg) {

  return _cipherBox->encryptString(msg, pc::Cipher::ENC_BASE64);

}

//Decrypt a CipherText message. Returns the
//ClearText version of the message
std::string MyCipher::decryptCipherTextMsg(const std::string& msg) {

  return _cipherBox->decryptString(msg, pc::Cipher::ENC_BASE64);

}


MyCipher::~MyCipher() {

  delete _cipherBox;

  //Global-wide lib uninit (uninits openssl)
  pc::uninitializeCrypto();

}


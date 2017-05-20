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

  //Since we have owning raw ptrs in objects of this class,
  //we need the ctor for leak-free RAII
  ~MyCipher();

  //Encrypt a human-readable, ClearText message. Returns the
  //CipherText version of the message
  std::string encryptClearTextMsg(const std::string& msg);

  //Decrypt a CipherText message. Returns the
  //ClearText version of the message
  std::string decryptCipherTextMsg(const std::string& msg);

  //Encrypt a whole input file. The input file is *assumed*
  //to be located at InOutTestFiles/ClearText.txt. The output
  //data is witten to InOutTestFiles/CipherText.txt
  void encryptFile();

  //Decrypt a whole input file. The input file is *assumed*
  //to be located at InOutTestFiles/CipherText.txt. The output
  //data is witten to InOutTestFiles/ClearText.txt
  void decryptFile();

private:

  //Since Poco.Crypto is a layer
  //on top of the openssl library,
  //you can get all the key types supported by
  //entering "openssl -h" in a terminal.
  //There are quite a few of them
  const std::string KEY_TYPE{"des-ede"/*"aes-256-cbc"*/};

  //With Poco.Crypto we first need a factory
  //that produces a Cipher we can use
  pc::CipherFactory& _factory;

  //Every Cipher requires a Key to encrypt/decrypt data
  pc::CipherKey _cKey;

  //A handle to our factory-generated Cipher
  pc::Cipher* _cipherBox{};

};

#endif /* MYCIPHER_H_ */

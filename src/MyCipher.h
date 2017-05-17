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

  void encryptDecryptMsg(const std::string& clearText);

  //Encrypt a human-readable, ClearText message. Returns the
  //CipherText version of the message
  std::string encryptClearTextMsg(const std::string& msg);

  //Decrypt a CipherText message. Returns the
  //ClearText version of the message
  std::string decryptCipherTextMsg(const std::string& msg);

  //Encrypt a whole input file. The input file is *assumed*
  //to be located at InOutTestFiles/ClearText.txt
  void encryptFile();

  //Encrypt a whole input file. The input file is *assumed*
  //to be located at InOutTestFiles/ClearText.txt. The output
  //data is witten to InOutTestFiles/ClearText.txt
  void decryptFile();

private:

  //You can get the key types supported by
  //typing "openssl -h" in a terminal. There is a boatload of them
  const std::string KEY_TYPE{"aes-256-cbc"};

  pc::CipherFactory& _factory;
  //Every Cipher requires a Key
  pc::CipherKey _cKey;
  pc::Cipher* _cipherBox{};

};

#endif /* MYCIPHER_H_ */

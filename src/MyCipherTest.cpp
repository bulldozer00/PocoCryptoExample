/*
 * MyCipherTest.cpp
 *
 *  Created on: May 4, 2017
 *      Author: bulldozer00
 */

#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"

#include "MyCipher.h"
#include <iostream>
#include <string>

TEST_CASE( "MyCipherTest1", "MCT1" ) {

  MyCipher cipher{};

  const std::string clearText{"This is my secret information"};

  std::string encryptedMsg{cipher.encryptClearTextMsg(clearText)};

  std::string decryptedMsg{cipher.decryptCipherTextMsg(encryptedMsg)};

  REQUIRE(decryptedMsg == clearText);

  cipher.encryptFile();

  cipher.decryptFile();

}

TEST_CASE( "MyCipherTest2", "MCT2" ) {

  MyCipher cipher{};

  const std::string clearText{"This is my secret information"};

  std:: cout << "Unencrypted ClearText Message: "
             << clearText << "\n";

  std::string encryptedMsg{cipher.encryptClearTextMsg(clearText)};

  std:: cout << "Encrypted ClearText Message: "
             << encryptedMsg << "\n";

  std::string decryptedMsg{cipher.decryptCipherTextMsg(encryptedMsg)};

  std:: cout << "UnEncrypted CipherText Message: "
             << decryptedMsg << "\n";

  REQUIRE(decryptedMsg == clearText);

}


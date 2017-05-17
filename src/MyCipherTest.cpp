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

TEST_CASE( "MyCipherTest", "MCT1" ) {

  MyCipher cipher{};

  const std::string clearText{"This is my secret information"};

  std::string encryptedMsg{cipher.encryptClearTextMsg(clearText)};

  std::string decryptedMsg{cipher.decryptCipherTextMsg(encryptedMsg)};

  REQUIRE(decryptedMsg == clearText);

  cipher.encryptFile();

  cipher.decryptFile();

}


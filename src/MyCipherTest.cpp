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

  cipher.encryptDecrypt();

  cipher.ioStream();

}


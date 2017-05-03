//============================================================================
// Name        : MainCryptoTest.cpp
// Author      : bulldozer00.com
//============================================================================
// This tells Catch to provide a main() -
// only do this in one cpp file
#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include <iostream>
#include "catch.hpp"
#include "Poco/Crypto/Crypto.h"
#include "Poco/Crypto/CipherKey.h"
#include "Poco/Crypto/Cipher.h"
#include "Poco/Crypto/CipherFactory.h"
#include "Poco/Exception.h"

TEST_CASE( "Crypto", "[Top]" ) {

  namespace pc = Poco::Crypto;

  //Global-wide lib init (inits openssl)
  pc::initializeCrypto();

  //Get a handle to the default factory
  pc::CipherFactory& factory
    = pc::CipherFactory::defaultFactory();

  //Create  a key for the cypherbox
  //we will be creating
  pc::CipherKey* cypherKey{};
  try {
    pc::CipherKey cKey{"aes-256"};
    cypherKey = &cKey;
  }
  catch(Poco::Exception& e) {
    std::cerr << "Caught an exception during "
              << "CipherKey construction: "
              << e.displayText() << "\n";
  }

  //Create the Cipher device
  pc::Cipher* cipherBox{};
  if(cypherKey)
    cipherBox = factory.createCipher(*cypherKey);

  delete cipherBox;
  delete cypherKey;

  pc::uninitializeCrypto();

}

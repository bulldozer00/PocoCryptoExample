//============================================================================
// Name        : MainCryptoTest.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "catch.hpp"
#include <iostream>
#include <string>
#include "Crypto.h"
#include "Poco/RandomStream.h"
#include "Poco/DigestEngine.h"
#include "Poco/HMACEngine.h"
#include "Poco/SHA1Engine.h"
#include "Poco/DigestStream.h"
#include "Poco/MD5Engine.h"
#define CATCH_CONFIG_COLOUR_NONE

TEST_CASE( "Random", "[Tl]" ) {

  Poco::RandomInputStream ris{};

  int32_t rnum1;
  ris >> rnum1;
  int32_t rnum2;
  ris >> rnum2;
}

TEST_CASE( "Hash", "[Tl]" ) {

  using Poco::DigestEngine;
  using Poco::HMACEngine;
  using Poco::SHA1Engine;

  std::string message1("This is a top-secret message.");
  std::string message2("Don't tell anyone!");
  std::string passphrase("s3cr3t"); // HMAC needs a passphrase

  HMACEngine<SHA1Engine> hmac(passphrase); // we'll compute a HMAC-SHA1
  hmac.update(message1);
  hmac.update(message2);
  const DigestEngine::Digest& digest = hmac.digest();
  // finish HMAC computation and obtain digest
  std::string digestString(DigestEngine::digestToHex(digest));

 // REQUIRE( dp.first == 0.0);

}

TEST_CASE( "Digest", "[Tl]" ) {

  using Poco::DigestOutputStream;
  using Poco::DigestEngine;
  using Poco::MD5Engine;

  MD5Engine md5;
  DigestOutputStream ostr(md5);
  ostr << "This is some text";
  ostr.flush(); // Ensure everything gets passed to the digest engine
  const DigestEngine::Digest& digest = md5.digest(); // obtain result
  std::string result = DigestEngine::digestToHex(digest);

 // REQUIRE( dp.first == 0.0);

}

// Implementation of the Chiper class.
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <iostream>
#include <nacl/crypto_box_curve25519xsalsa20poly1305.h>
#include <nacl/randombytes.h>

#include "base32.h"
#include "Cipher.h"
#include "CipherException.h"

using namespace std;

namespace odns {
    namespace internal {

	static const char hextable[] = "0123456789abcdef";

        Cipher::Cipher() {
	   uint8_t pub[32], pri[32];
	   crypto_box_curve25519xsalsa20poly1305_keypair(pub, pri);

	   uint8_t p[64];
	   unsigned plen = sizeof(p) - 3;
	   memcpy(p, "uz5", 3);
	   if (!base32_encode(p + 3, &plen, pub, 32)) {
		throw CipherException("base32_encoder");
	   }

	   p[54] = 0;
	   char hexpublic[65];
	   for (unsigned i = 0; i < 32; ++i) {
		hexpublic[i*2    ] = hextable[pub[i] >> 4];
		hexpublic[i*2 + 1] = hextable[pub[i] & 15];
	   }
           hexpublic[64] = 0;

	   char hexprivate[65];
	   for (unsigned i = 0; i < 32; ++i) {
		hexprivate[i*2    ] = hextable[pri[i] >> 4];
		hexprivate[i*2 + 1] = hextable[pri[i] & 15];
	   }
	   hexprivate[64] = 0;
   
           memset(public_key, 0, 32); 
	   memset(secret_key, 0, 32);

	   memcpy(public_key, hexpublic , sizeof(hexpublic));
	   memcpy(secret_key, hexprivate, sizeof(hexprivate));
        };

        Cipher::Cipher(uint8_t* pk, uint8_t* sk) {
	   memcpy(public_key, pk, 32);
	   memcpy(secret_key, sk, 32);
        };

        Cipher::~Cipher() {
        };

	void
	Cipher::encrypt(uint8_t* public_key, uint8_t* plaintext, uint8_t* encrypted) {

	   uint8_t nonce[24];
           randombytes(nonce, 12);
           memset(nonce + 12, 0, 12);

	   memset(encrypted, 0, 32);
	   memcpy(encrypted, "R6fnvWJ8", 8); 
	   memcpy(encrypted, nonce, 24); 

	   crypto_box_curve25519xsalsa20poly1305(encrypted, plaintext, sizeof(plaintext), nonce, public_key, secret_key);

        };

	void
	Cipher::decrypt(uint8_t* public_key,uint8_t* encrypted, uint8_t* plaintext) {
        };

    } // namespace internal
} // namespace odns


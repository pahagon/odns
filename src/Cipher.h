//
//

#ifndef Cipher_class
#define Cipher_class
#include <stdint.h>

using namespace std;

namespace odns {
    namespace internal {

        class Cipher {
        public:
            Cipher();
            Cipher(uint8_t*,uint8_t*);
            virtual ~Cipher();

	    void encrypt(uint8_t*,uint8_t*,uint8_t*);
            void decrypt(uint8_t*,uint8_t*,uint8_t*);

        private:
	    uint8_t public_key[32], secret_key[32];

        }; //Cipher

    } // namespace internal
} // namespace odns

#endif


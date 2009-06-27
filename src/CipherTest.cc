#include <iostream>
#include "Cipher.h"

using namespace std;
using namespace odns::internal;

int 
main(int argc, char **argv) {

  Cipher c;
  uint8_t plaintext[]  = "\xab\xcd\x01\x00\x00\x01\x00\x00\x00\x00\x00\x00\x03www\x06google\x03org\x00\x00\x02\x00\x01";
  uint8_t encrypted[]  = "";
  uint8_t public_key[] = "";
  c.encrypt( public_key, plaintext, encrypted );
  cout << "encrypted[" << encrypted << "]\n";

}


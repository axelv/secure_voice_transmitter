#include <stdio.h>
#include <stdlib.h>
#include "aes.h"

int main()
{
aes_key key;
unsigned char output[16];

  aes_set_encrypt_key(&key, "\x2b\x7e\x15\x16\x28\xae\xd2\xa6\xab\xf7\x15\x88\x09\xcf\x4f\x3c", 128);
  
  aes_encrypt(&key, "\x6b\xc1\xbe\xe2\x2e\x40\x9f\x96\xe9\x3d\x7e\x11\x73\x93\x17\x2a", output);
  
  if (memcmp(output, "\x3a\xd7\x7b\xb4\x0d\x7a\x36\x60\xa8\x9e\xca\xf3\x24\x66\xef\x97", 16) != 0) {
    fprintf(stderr, "Encryption failed\n");
    abort();
  }

  aes_set_decrypt_key(&key, "\x2b\x7e\x15\x16\x28\xae\xd2\xa6\xab\xf7\x15\x88\x09\xcf\x4f\x3c", 128);
  
  aes_decrypt(&key, "\x3a\xd7\x7b\xb4\x0d\x7a\x36\x60\xa8\x9e\xca\xf3\x24\x66\xef\x97", output);

  if (memcmp(output, "\x6b\xc1\xbe\xe2\x2e\x40\x9f\x96\xe9\x3d\x7e\x11\x73\x93\x17\x2a", 16) != 0) {
    fprintf(stderr, "Decryption failed\n");
    abort();
  }
  
  return 0;
}

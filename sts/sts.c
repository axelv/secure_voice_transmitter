#include "sts.h"
// Variables and functions needed by both master & slave STS

//PUBLIC KEYS
const static unsigned char master_public_exponent[3] =	"\x01\x00\x01";
const static unsigned char slave_public_exponent[3] =	"\x01\x00\x01";

//RSA-modulus
const unsigned char slave_modulus[157] =
	"\x00\xa2\x79\xf4\x8f\xe4\x08\x9d\x96\x13\x09\x66\x31\x6f\x56"
	"\x48\x78\x2c\xaa\xba\x8d\x01\x05\x6f\x41\xb2\xba\x63\x6a\x7a"
	"\x8c\x1f\x54\x33\x31\xc3\x0f\xa0\xe7\x30\x35\x36\x09\x51\x6f"
	"\x6d\xdd\xaf\xe5\x35\xc9\xb9\x6e\x16\x73\xa6\x30\x15\xff\xad"
	"\x86\xaf\xc3\xf4\x6c\x8d\x4a\x76\xe5\xb6\x4e\xe4\x8f\x60\x12"
	"\x46\xc0\xcd\x42\x65\x04\x58\x08\xf1\x3a\xa3\xe2\xc9\x1a\xc3"
	"\x3c\x71\x81\xe9\x20\xff\x7a\xc0\xff\x8e\x24\x44\x34\x6e\x5a"
	"\x8f\xfc\x13\x94\xf6\x09\x19\x57\x94\x0a\xec\xcf\xe7\x19\x11"
	"\x96\x1d\x00\xff\x44\x63\xb7\x40\x3c\xa9\xe4\xd2\x51\x42\x0a"
	"\xd4\xc7\x09\xc5\xea\x72\xdb\x6a\xf8\x3b\x0c\x06\x5f\x4f\x67"
	"\xeb\x2b\x53\x07\xa4\x86\xf7";
const unsigned char master_modulus[157] =
	"\x00\xb2\x20\x91\x91\x03\xe9\x2f\x99\x59\xa3\x65\x80\x2c\xb5"
	"\x25\x03\x03\xaf\xe9\x3c\x42\x13\x07\xc2\x5e\x15\x1b\x21\x09"
	"\x9e\x31\xcb\xef\xaf\x19\xa7\xda\x52\xfc\x8c\x01\x2b\x53\x4e"
	"\xee\x53\x2d\x31\xa6\xe5\x3c\x26\xbc\x61\x9e\x38\x86\x74\xc1"
	"\x44\xf9\xb1\x9c\x87\x18\x9f\x58\x3d\x0c\x00\x58\x83\xaa\x5c"
	"\x77\xe1\xd2\x5d\x04\x8c\x00\xb6\x24\x91\x66\x15\x6a\xd9\xc1"
	"\xaa\x3e\x02\x99\xb5\x11\xad\xf6\xb4\x73\x77\x91\xda\x4a\xb2"
	"\xb6\xa5\x3c\xda\xcd\x2f\xaa\xc9\x47\x51\x20\xf2\x87\xe3\xbe"
	"\x3b\xf5\x8f\x15\x63\xb4\xc1\xb0\xb0\x22\x51\xf0\x4b\xd4\x1c"
	"\x50\x91\xa8\x5b\x8f\x09\x55\x5d\x46\x65\x41\xa7\x4e\xab\x5f"
	"\x4c\xf1\x86\x05\x55\xdf\x83";

void get_master_pubkey(uint8_t *pubkey_in_LE){ // for conversion to little endian
	signed int i;
	for(i=2;i>=0;i--){
	pubkey_in_LE[2-i] = master_public_exponent[i];
	}
}

void get_master_modulus(uint8_t *modulus_in_LE){ // for conversion to little endian
	signed int i;
	for(i=156;i>=0;i--){
	modulus_in_LE[156-i] = master_modulus[i];
	}
}

void get_slave_modulus(uint8_t *modulus_in_LE){ // for conversion to little endian
	signed int i;
	for(i=156;i>=0;i--){
	modulus_in_LE[156-i] = slave_modulus[i];
	}
}

void get_slave_pubkey(uint8_t *pubkey_in_LE){ // for conversion to little endian
	signed int i;
	for(i=2;i>=0;i--){
	pubkey_in_LE[2-i] = slave_public_exponent[i];
	}
}
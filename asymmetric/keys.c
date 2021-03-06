#include <stdint.h>

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
	// These are the rmodn's for the 156 byte modulus for the MASTER RSA Signatures
	uint8_t rmodn_master[156] = {0x7D,0x20,0xAA,0xFA,0x79,0x0E,0xB3,0xA0,0x54,0xB1,0x58,0xBE,0x9A,0xB9,0xA2,0xAA,0xF6,0x70,0xA4,0x57,0x6E,0xAF,0xE3,0x2B,0xB4,0x0F,0xAE,0xDD,0x4F,0x4F,0x3E,0x4B,0x9C,0xEA,0x70,0x0A,0xC4,0x41,0x1C,0x78,0x0D,0xDF,0xAE,0xB8,0x36,0x55,0xD0,0x32,0x25,0xC3,0x5A,0x49,0x4D,0xB5,0x25,0x6E,0x88,0x8C,0x4B,0x09,0x52,0xEE,0x4A,0x66,0xFD,0xC1,0x55,0x3E,0x26,0x95,0xEA,0x99,0x6E,0xDB,0x49,0xFF,0x73,0xFB,0xA2,0x2D,0x1E,0x88,0xA3,0x55,0x7C,0xA7,0xFF,0xF3,0xC2,0xA7,0x60,0xE7,0x78,0x63,0x4E,0x06,0xBB,0x3E,0x8B,0x79,0xC7,0x61,0x9E,0x43,0xD9,0xC3,0x1A,0x59,0xCE,0xD2,0xAC,0x11,0xB1,0xAC,0xD4,0xFE,0x73,0x03,0xAD,0x25,0x58,0xE6,0x50,0x10,0x34,0xCE,0x61,0xF6,0xDE,0xE4,0xEA,0xA1,0x3D,0xF8,0xEC,0xBD,0xC3,0x16,0x50,0xFC,0xFC,0xDA,0x4A,0xD3,0x7F,0x9A,0x5C,0xA6,0x66,0xD0,0x16,0xFC,0x6E,0x6E,0xDF,0x4D};
	uint8_t r2modn_master[156]= {0x63,0x93,0xBE,0x6C,0x04,0xE5,0xD6,0xE4,0x27,0xB7,0x53,0x91,0xFA,0x16,0xAA,0x75,0x8A,0x3C,0x2E,0xA9,0xEE,0x91,0x70,0x90,0xBD,0xF8,0xA3,0x2B,0x30,0x83,0xED,0xAE,0xA8,0x6C,0x99,0x16,0xC8,0x9B,0x13,0x13,0xD1,0x57,0xB3,0x6A,0x8F,0x0D,0x7E,0x3C,0xC9,0xE4,0x7F,0x3D,0x46,0x51,0x76,0x09,0x82,0x3B,0xE7,0x08,0x1F,0x54,0x9E,0xA0,0xE5,0xBA,0x8B,0x1E,0x64,0x0A,0x60,0x30,0xBB,0xE7,0xB8,0x91,0xCB,0xF4,0x53,0xA1,0x8D,0x48,0xCC,0x0B,0xC3,0x47,0xC4,0x0A,0x5E,0x7A,0xD3,0xC4,0xE8,0xFA,0x36,0x62,0x33,0x0D,0x86,0x24,0x61,0xE7,0xF3,0xB4,0xFD,0xDC,0x87,0x3E,0x9C,0xDF,0xCC,0x55,0x77,0x08,0xC0,0xBF,0xF4,0x5D,0x9C,0xA1,0xFB,0x1B,0xF0,0x66,0xF6,0xEF,0x4C,0x3D,0x07,0x36,0x50,0xCC,0xB6,0xB7,0x57,0x76,0x22,0x71,0x55,0x54,0xBA,0xA4,0x1D,0x0C,0xFA,0x00,0x00,0x82,0x95,0x35,0xAB,0x4D,0x06,0x0C,0xB0,0x9E};
	
	
void get_master_modulus(uint8_t *modulus_in_LE){ // for conversion to little endian
	signed int i;
	for(i=156;i>=0;i--){
	modulus_in_LE[156-i] = master_modulus[i];
	}
}
const unsigned char master_public_exponent[3] =
	"\x01\x00\x01";
void get_master_pubkey(uint8_t *pubkey_in_LE){ // for conversion to little endian
	signed int i;
	for(i=2;i>=0;i--){
	pubkey_in_LE[2-i] = master_public_exponent[i];
	}
}
	
const unsigned char master_private_exponent[156] =
	"\x3c\x13\xf0\x04\xd1\x24\xdd\x01\x03\xd2\xb0\x71\x42\xa2\xf6"
	"\x10\xc6\x35\x96\x9c\xd4\x4c\x46\xd9\xaf\x91\xbe\xcc\xad\xc9"
	"\xc5\x51\xdb\x4d\x5b\x81\xd9\x89\x13\xd4\xc4\xb0\x30\x30\xf7"
	"\x00\xe6\xc5\x50\x5d\x10\xa4\x9f\xf4\xec\xc0\x73\xd8\xfd\x36"
	"\x9e\x60\xe1\x42\x4f\x73\xae\xf7\x28\x0d\x15\xcd\x92\xb0\x0d"
	"\x5f\x04\xeb\xf9\xd0\xc0\xe7\x38\xff\x9e\xc3\x2c\xab\x22\xcd"
	"\x4b\xda\xcb\xc7\xbd\x24\xd4\x51\x71\xe5\x99\x01\xcb\xcb\x78"
	"\xc0\xbd\x3f\xc2\xc5\xd9\x02\x46\x68\xa9\xbc\xfd\x11\x3f\xc5"
	"\xdc\xc3\x6a\x55\xad\x3f\x5f\xfb\x08\xad\x01\x5a\xac\x02\xbc"
	"\xa1\xaa\xb7\x88\x01\x2b\xbd\x60\x97\x41\xbf\x5b\x6e\x06\x55"
	"\xf9\x03\xb5\xd1\xd3\xc1";
	
void get_master_privkey(uint8_t *privkey_in_LE){
	signed int i;
	for(i=155;i>=0;i--){
          privkey_in_LE[155-i] = master_private_exponent[i];
	}
}
	
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
	
	// These are the rmodn's for the 156 byte modulus for the SLAVE RSA Signatures
	uint8_t rmodn_slave[156] = {0x09,0x79,0x5B,0xF8,0xAC,0xD4,0x14,0x98,0xB0,0xA0,0xF9,0xF3,0xC4,0x07,0x95,0x24,0x8D,0x15,0x3A,0xF6,0x38,0x2B,0xF5,0xBD,0xAE,0x2D,0x1B,0x56,0xC3,0xBF,0x48,0x9C,0xBB,0x00,0xFF,0xE2,0x69,0xEE,0xE6,0x18,0x30,0x13,0xF5,0x6B,0xA8,0xE6,0xF6,0x09,0x6B,0xEC,0x03,0x70,0xA5,0x91,0xCB,0xBB,0xDB,0x71,0x00,0x3F,0x85,0x00,0xDF,0x16,0x7E,0x8E,0xC3,0x3C,0xE5,0x36,0x1D,0x5C,0xC5,0x0E,0xF7,0xA7,0xFB,0x9A,0xBD,0x32,0x3F,0xB9,0xED,0x9F,0x70,0x1B,0xB1,0x49,0x1A,0x89,0xB5,0x72,0x93,0x0B,0x3C,0x50,0x79,0x52,0x00,0xEA,0xCF,0x59,0x8C,0xE9,0x91,0x46,0x36,0xCA,0x1A,0x50,0x22,0x92,0x90,0xAE,0xF6,0xC9,0xCA,0xCF,0x18,0x5F,0xF0,0x3C,0xCE,0xCC,0xAB,0xE0,0x73,0x85,0x95,0x9C,0x45,0x4D,0xBE,0x90,0xFA,0xFE,0x72,0x45,0x55,0xD3,0x87,0xB7,0xA9,0x90,0xCE,0x99,0xF6,0xEC,0x69,0x62,0xF7,0x1B,0x70,0x0B,0x86,0x5D};
	uint8_t r2modn_slave[156]= {0x0A,0xD4,0x11,0xA8,0xA6,0x4B,0x97,0xA8,0x54,0x3D,0xB8,0xDC,0x54,0x23,0x5B,0xAB,0x84,0x05,0x54,0x63,0x9D,0x85,0xD9,0x52,0x4C,0x7B,0xA4,0xBA,0x24,0xDF,0x05,0xF0,0xC3,0x04,0x50,0xC2,0x83,0x03,0x55,0x43,0xBF,0x92,0x09,0x14,0x3E,0x7C,0xE8,0x99,0xCE,0x3A,0x83,0x5C,0x6B,0x3C,0x8C,0xA8,0x21,0xA1,0xC9,0xB2,0x0A,0x78,0x21,0x00,0xFE,0x4A,0x84,0xFE,0x8A,0x18,0xE7,0x72,0xCE,0x86,0x85,0x90,0x4E,0x6D,0xB0,0xF4,0xDB,0xE4,0x31,0xD0,0xD4,0xB8,0x71,0xA1,0x64,0xDE,0x81,0xDC,0x52,0x52,0xFE,0x4D,0x15,0xCB,0x91,0x30,0x1B,0x42,0x6E,0x7F,0xC7,0x44,0xAE,0xA4,0x67,0x3E,0xD1,0x18,0x65,0x55,0x93,0xA7,0x0C,0xE8,0x4F,0x12,0xEA,0xAA,0x1E,0xF4,0x96,0xA3,0x3F,0x48,0x7C,0x14,0xF6,0xDD,0x10,0xB5,0xA6,0x5B,0x4B,0x18,0x28,0x0B,0xBE,0x48,0x2C,0x15,0x39,0xAA,0xB8,0xB4,0x26,0x55,0xB3,0x37,0x10,0x18,0x8F,0x3B};
	
	
void get_slave_modulus(uint8_t *modulus_in_LE){ // for conversion to little endian
	signed int i;
	for(i=156;i>=0;i--){
	modulus_in_LE[156-i] = slave_modulus[i];
	}
}

const unsigned char slave_public_exponent[3] =
	"\x01\x00\x01";
void get_slave_pubkey(uint8_t *pubkey_in_LE){ // for conversion to little endian
	signed int i;
	for(i=2;i>=0;i--){
	pubkey_in_LE[2-i] = slave_public_exponent[i];
	}
}

const unsigned char slave_private_exponent[156] =
	"\x07\x8e\x74\x79\x5c\xb9\xa9\xda\x98\xf8\x0e\xf0\xad\xa4\xed"
	"\xa9\xe9\x29\xe7\x93\x37\x40\xf1\x73\xb4\xc4\x46\x6b\x65\x57"
	"\xae\xfd\x53\x84\x34\xf6\x3d\x1d\x83\x78\x76\x12\xe8\xde\xad"
	"\xd5\x69\xa0\xd7\x67\x92\x60\x34\x5b\x1c\x97\x8f\xee\x5c\x3b"
	"\xaf\x61\x05\xb5\x26\xbd\x17\xda\x87\x28\x14\x29\x36\xe6\xa2"
	"\xb3\xc4\xd8\x06\xaf\x49\xc0\x5e\x4b\x8a\xea\xb5\x50\x58\xa1"
	"\x93\x1a\x34\xb7\xb1\x1b\x4f\xf9\x6c\xc0\xed\xad\xdf\xa1\xa0"
	"\xe3\x9e\x87\x28\x65\x3f\xf2\x6f\x40\xa4\x0c\xe6\x13\x63\xd9"
	"\x59\x1f\x7c\x31\x31\x73\xfc\xf7\xda\x68\xc8\x23\xff\xc3\x19"
	"\x4f\x85\x17\x63\xce\xf1\x7a\xe6\xb1\xde\xb0\xb9\x65\xfd\x2a"
	"\x83\xeb\x6d\xf6\x5a\x41";
void get_slave_privkey(uint8_t *privkey_in_LE){
	signed int i;
	for(i=155;i>=0;i--){
		privkey_in_LE[155-i] = slave_private_exponent[i];
	}
}

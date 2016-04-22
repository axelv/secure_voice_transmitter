#include <stdint.h>
#include <string.h>

#include "../asymmetric/monexp.h"
#include "../ocb/ocb.h"
#include "../bbs/bbs.h"
#include "../constants.h"
#include "../asymmetric/signatures.h"
#include "../ciphers/sha2/sha2_wrapper.h"

static uint8_t rmodn_dh[156] = {0xBD,0x53,0x67,0x38,0xFC,0x94,0xC0,0x63,0x1C,0x54,0x51,0x76,0x15,0x2D,0x03,0x56,0x94,0xE3,0x24,0x5A,0xD5,0xAE,0xE7,0x34,0x54,0xF1,0x56,0x86,0xB7,0x2F,0x33,0x6F,0xFA,0x3E,0x17,0x43,0xFC,0xC1,0x7F,0x89,0x49,0xB8,0xB9,0x55,0x50,0x16,0x80,0x1A,0x53,0xBD,0x1F,0xA3,0x55,0x7D,0xAE,0x3A,0x60,0x3E,0xE9,0x55,0xE8,0x82,0xFF,0xDB,0x6F,0xF8,0xBF,0x16,0xDF,0x0C,0x21,0x1E,0x79,0xA0,0xD8,0xBB,0xD7,0x19,0x03,0xB1,0x60,0x48,0x6E,0xAA,0x30,0x8B,0x87,0x6A,0x33,0xC0,0x5E,0x6A,0x11,0xE0,0x12,0x08,0x39,0xED,0x6F,0xED,0xB2,0x04,0xD4,0x1B,0x15,0xB7,0x8E,0x33,0x05,0x73,0x34,0xDF,0xA9,0xAD,0xAB,0x08,0x34,0xDE,0x52,0x24,0xC4,0x10,0xAE,0xBC,0x39,0xB9,0xCD,0x5C,0xED,0x08,0xCA,0x96,0xB2,0x86,0xF6,0x75,0x64,0x91,0xBE,0x20,0x47,0x99,0x33,0xDB,0x6D,0xCB,0x06,0xEF,0xC2,0xA0,0x5C,0xFB,0x7F,0x8C,0x57,0x2F};
static uint8_t r2modn_dh[156] ={0x1A,0x1C,0x3E,0xFD,0x47,0xBE,0x7F,0x6E,0x0C,0xC4,0x25,0xCE,0xEA,0x24,0x25,0x72,0xC5,0x68,0x14,0x23,0x08,0x93,0x2C,0x0C,0x9A,0x84,0x61,0xC0,0x18,0x16,0x27,0x64,0xF0,0x66,0xF7,0x1E,0x23,0xC2,0xEF,0xD3,0x87,0x66,0xB1,0x98,0x82,0x58,0x0C,0x46,0xCB,0x87,0xA7,0x40,0x92,0x94,0x0F,0x76,0x0F,0xA9,0xC6,0x70,0x3B,0x48,0x2B,0x27,0xE6,0xBB,0xA7,0x8E,0xD8,0x5E,0xC2,0x36,0x19,0x3E,0xDF,0x42,0x50,0x78,0x2C,0x2A,0x20,0x27,0x4E,0x60,0x6E,0x9C,0xF9,0x11,0x5E,0xD9,0x1B,0x83,0x56,0x46,0xE4,0x1D,0x93,0xE6,0x5B,0x0C,0xCE,0x4A,0x2B,0xC5,0xAA,0x0F,0xC0,0xED,0x30,0x58,0x77,0xD3,0x45,0xEC,0x71,0xC1,0x32,0xF4,0xEF,0x13,0xD3,0xB6,0x00,0x26,0xE5,0x71,0x4C,0x7D,0x76,0xBB,0x1F,0x0D,0xC6,0x45,0x2F,0x7E,0x07,0xA8,0x49,0xC2,0x20,0x35,0x3B,0x52,0xE7,0xE8,0x51,0x47,0x7A,0xDA,0x1B,0xFB,0xA8,0xE8,0x7C,0x14};
static uint8_t rmodn_master[156] = {0x7D,0x20,0xAA,0xFA,0x79,0x0E,0xB3,0xA0,0x54,0xB1,0x58,0xBE,0x9A,0xB9,0xA2,0xAA,0xF6,0x70,0xA4,0x57,0x6E,0xAF,0xE3,0x2B,0xB4,0x0F,0xAE,0xDD,0x4F,0x4F,0x3E,0x4B,0x9C,0xEA,0x70,0x0A,0xC4,0x41,0x1C,0x78,0x0D,0xDF,0xAE,0xB8,0x36,0x55,0xD0,0x32,0x25,0xC3,0x5A,0x49,0x4D,0xB5,0x25,0x6E,0x88,0x8C,0x4B,0x09,0x52,0xEE,0x4A,0x66,0xFD,0xC1,0x55,0x3E,0x26,0x95,0xEA,0x99,0x6E,0xDB,0x49,0xFF,0x73,0xFB,0xA2,0x2D,0x1E,0x88,0xA3,0x55,0x7C,0xA7,0xFF,0xF3,0xC2,0xA7,0x60,0xE7,0x78,0x63,0x4E,0x06,0xBB,0x3E,0x8B,0x79,0xC7,0x61,0x9E,0x43,0xD9,0xC3,0x1A,0x59,0xCE,0xD2,0xAC,0x11,0xB1,0xAC,0xD4,0xFE,0x73,0x03,0xAD,0x25,0x58,0xE6,0x50,0x10,0x34,0xCE,0x61,0xF6,0xDE,0xE4,0xEA,0xA1,0x3D,0xF8,0xEC,0xBD,0xC3,0x16,0x50,0xFC,0xFC,0xDA,0x4A,0xD3,0x7F,0x9A,0x5C,0xA6,0x66,0xD0,0x16,0xFC,0x6E,0x6E,0xDF,0x4D};
static uint8_t r2modn_master[156]= {0x63,0x93,0xBE,0x6C,0x04,0xE5,0xD6,0xE4,0x27,0xB7,0x53,0x91,0xFA,0x16,0xAA,0x75,0x8A,0x3C,0x2E,0xA9,0xEE,0x91,0x70,0x90,0xBD,0xF8,0xA3,0x2B,0x30,0x83,0xED,0xAE,0xA8,0x6C,0x99,0x16,0xC8,0x9B,0x13,0x13,0xD1,0x57,0xB3,0x6A,0x8F,0x0D,0x7E,0x3C,0xC9,0xE4,0x7F,0x3D,0x46,0x51,0x76,0x09,0x82,0x3B,0xE7,0x08,0x1F,0x54,0x9E,0xA0,0xE5,0xBA,0x8B,0x1E,0x64,0x0A,0x60,0x30,0xBB,0xE7,0xB8,0x91,0xCB,0xF4,0x53,0xA1,0x8D,0x48,0xCC,0x0B,0xC3,0x47,0xC4,0x0A,0x5E,0x7A,0xD3,0xC4,0xE8,0xFA,0x36,0x62,0x33,0x0D,0x86,0x24,0x61,0xE7,0xF3,0xB4,0xFD,0xDC,0x87,0x3E,0x9C,0xDF,0xCC,0x55,0x77,0x08,0xC0,0xBF,0xF4,0x5D,0x9C,0xA1,0xFB,0x1B,0xF0,0x66,0xF6,0xEF,0x4C,0x3D,0x07,0x36,0x50,0xCC,0xB6,0xB7,0x57,0x76,0x22,0x71,0x55,0x54,0xBA,0xA4,0x1D,0x0C,0xFA,0x00,0x00,0x82,0x95,0x35,0xAB,0x4D,0x06,0x0C,0xB0,0x9E};
static uint8_t rmodn_slave[156] = {0x09,0x79,0x5B,0xF8,0xAC,0xD4,0x14,0x98,0xB0,0xA0,0xF9,0xF3,0xC4,0x07,0x95,0x24,0x8D,0x15,0x3A,0xF6,0x38,0x2B,0xF5,0xBD,0xAE,0x2D,0x1B,0x56,0xC3,0xBF,0x48,0x9C,0xBB,0x00,0xFF,0xE2,0x69,0xEE,0xE6,0x18,0x30,0x13,0xF5,0x6B,0xA8,0xE6,0xF6,0x09,0x6B,0xEC,0x03,0x70,0xA5,0x91,0xCB,0xBB,0xDB,0x71,0x00,0x3F,0x85,0x00,0xDF,0x16,0x7E,0x8E,0xC3,0x3C,0xE5,0x36,0x1D,0x5C,0xC5,0x0E,0xF7,0xA7,0xFB,0x9A,0xBD,0x32,0x3F,0xB9,0xED,0x9F,0x70,0x1B,0xB1,0x49,0x1A,0x89,0xB5,0x72,0x93,0x0B,0x3C,0x50,0x79,0x52,0x00,0xEA,0xCF,0x59,0x8C,0xE9,0x91,0x46,0x36,0xCA,0x1A,0x50,0x22,0x92,0x90,0xAE,0xF6,0xC9,0xCA,0xCF,0x18,0x5F,0xF0,0x3C,0xCE,0xCC,0xAB,0xE0,0x73,0x85,0x95,0x9C,0x45,0x4D,0xBE,0x90,0xFA,0xFE,0x72,0x45,0x55,0xD3,0x87,0xB7,0xA9,0x90,0xCE,0x99,0xF6,0xEC,0x69,0x62,0xF7,0x1B,0x70,0x0B,0x86,0x5D};
static uint8_t r2modn_slave[156]= {0x0A,0xD4,0x11,0xA8,0xA6,0x4B,0x97,0xA8,0x54,0x3D,0xB8,0xDC,0x54,0x23,0x5B,0xAB,0x84,0x05,0x54,0x63,0x9D,0x85,0xD9,0x52,0x4C,0x7B,0xA4,0xBA,0x24,0xDF,0x05,0xF0,0xC3,0x04,0x50,0xC2,0x83,0x03,0x55,0x43,0xBF,0x92,0x09,0x14,0x3E,0x7C,0xE8,0x99,0xCE,0x3A,0x83,0x5C,0x6B,0x3C,0x8C,0xA8,0x21,0xA1,0xC9,0xB2,0x0A,0x78,0x21,0x00,0xFE,0x4A,0x84,0xFE,0x8A,0x18,0xE7,0x72,0xCE,0x86,0x85,0x90,0x4E,0x6D,0xB0,0xF4,0xDB,0xE4,0x31,0xD0,0xD4,0xB8,0x71,0xA1,0x64,0xDE,0x81,0xDC,0x52,0x52,0xFE,0x4D,0x15,0xCB,0x91,0x30,0x1B,0x42,0x6E,0x7F,0xC7,0x44,0xAE,0xA4,0x67,0x3E,0xD1,0x18,0x65,0x55,0x93,0xA7,0x0C,0xE8,0x4F,0x12,0xEA,0xAA,0x1E,0xF4,0x96,0xA3,0x3F,0x48,0x7C,0x14,0xF6,0xDD,0x10,0xB5,0xA6,0x5B,0x4B,0x18,0x28,0x0B,0xBE,0x48,0x2C,0x15,0x39,0xAA,0xB8,0xB4,0x26,0x55,0xB3,0x37,0x10,0x18,0x8F,0x3B};


// Variables needed by both master & slave STS
//PUBLIC KEYS
static uint8_t master_public_exponent[3] =	{0x01,0x00,0x01};
static uint8_t slave_public_exponent[3] =	{0x01,0x00,0x01};

//RSA-modulus
static uint8_t slave_modulus[157] = {0xF7,0x86,0xA4,0x07,0x53,0x2B,0xEB,0x67,0x4F,0x5F,0x06,0x0C,0x3B,0xF8,0x6A,0xDB,0x72,0xEA,0xC5,0x09,0xC7,0xD4,0x0A,0x42,0x51,0xD2,0xE4,0xA9,0x3C,0x40,0xB7,0x63,0x44,0xFF,0x00,0x1D,0x96,0x11,0x19,0xE7,0xCF,0xEC,0x0A,0x94,0x57,0x19,0x09,0xF6,0x94,0x13,0xFC,0x8F,0x5A,0x6E,0x34,0x44,0x24,0x8E,0xFF,0xC0,0x7A,0xFF,0x20,0xE9,0x81,0x71,0x3C,0xC3,0x1A,0xC9,0xE2,0xA3,0x3A,0xF1,0x08,0x58,0x04,0x65,0x42,0xCD,0xC0,0x46,0x12,0x60,0x8F,0xE4,0x4E,0xB6,0xE5,0x76,0x4A,0x8D,0x6C,0xF4,0xC3,0xAF,0x86,0xAD,0xFF,0x15,0x30,0xA6,0x73,0x16,0x6E,0xB9,0xC9,0x35,0xE5,0xAF,0xDD,0x6D,0x6F,0x51,0x09,0x36,0x35,0x30,0xE7,0xA0,0x0F,0xC3,0x31,0x33,0x54,0x1F,0x8C,0x7A,0x6A,0x63,0xBA,0xB2,0x41,0x6F,0x05,0x01,0x8D,0xBA,0xAA,0x2C,0x78,0x48,0x56,0x6F,0x31,0x66,0x09,0x13,0x96,0x9D,0x08,0xE4,0x8F,0xF4,0x79,0xA2};
static uint8_t master_modulus[157] = {0x83,0xDF,0x55,0x05,0x86,0xF1,0x4C,0x5F,0xAB,0x4E,0xA7,0x41,0x65,0x46,0x5D,0x55,0x09,0x8F,0x5B,0xA8,0x91,0x50,0x1C,0xD4,0x4B,0xF0,0x51,0x22,0xB0,0xB0,0xC1,0xB4,0x63,0x15,0x8F,0xF5,0x3B,0xBE,0xE3,0x87,0xF2,0x20,0x51,0x47,0xC9,0xAA,0x2F,0xCD,0xDA,0x3C,0xA5,0xB6,0xB2,0x4A,0xDA,0x91,0x77,0x73,0xB4,0xF6,0xAD,0x11,0xB5,0x99,0x02,0x3E,0xAA,0xC1,0xD9,0x6A,0x15,0x66,0x91,0x24,0xB6,0x00,0x8C,0x04,0x5D,0xD2,0xE1,0x77,0x5C,0xAA,0x83,0x58,0x00,0x0C,0x3D,0x58,0x9F,0x18,0x87,0x9C,0xB1,0xF9,0x44,0xC1,0x74,0x86,0x38,0x9E,0x61,0xBC,0x26,0x3C,0xE5,0xA6,0x31,0x2D,0x53,0xEE,0x4E,0x53,0x2B,0x01,0x8C,0xFC,0x52,0xDA,0xA7,0x19,0xAF,0xEF,0xCB,0x31,0x9E,0x09,0x21,0x1B,0x15,0x5E,0xC2,0x07,0x13,0x42,0x3C,0xE9,0xAF,0x03,0x03,0x25,0xB5,0x2C,0x80,0x65,0xA3,0x59,0x99,0x2F,0xE9,0x03,0x91,0x91,0x20,0xB2};

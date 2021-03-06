/***********************************************************************
* FILENAME :        signature_test.c       VERSION: 1.0
*
* DESCRIPTION :
*       Testing of Signature Generation and Validation
*
*
* NOTES : 
* 
* AUTHOR :    mraes 
*
*
*****/

#include <stdio.h>
#include <stdint.h>
#include "signatures.h"
#include "monmult.h"

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// YOU NEED TO CHANGE SIZE PARAM IN monmult.h to 128 FOR THIS TO WORK!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

void main(){
	// these are the rmodn's for 128 byte modulus (Dit is voor met de vectoren ooit gegeven in DDP (MAGMA))
	uint8_t rmodn[SIZE] =  {0xCF, 0x90, 0x85, 0x19, 0x1A, 0x43, 0x88, 0x59, 0x07, 0x99, 0x61, 0xC4, 0xFD, 0x0B, 0x20, 0xCD, 0x37, 0x58, 0x46, 0xD5, 0xE1, 0x43, 0xF7, 0x41, 0x79, 0xEE, 0x21, 0xD5, 0x30, 0x17, 0x77, 0x71, 0xC4, 0xA3, 0x95, 0x8E, 0xB8, 0xC3, 0xBA, 0xFA, 0xB9, 0x1B, 0x52, 0x6C, 0xBD, 0xE0, 0x88, 0x23, 0xDA, 0x68, 0x8F, 0x1E, 0x4A, 0x14, 0x76, 0x80, 0x56, 0xE1, 0xAF, 0xE2, 0xCC, 0x66, 0xC3, 0xF6, 0x97, 0x1B, 0xE5, 0x30, 0x4F, 0xE1, 0x45, 0xA9, 0xDB, 0x83, 0x71, 0xCA, 0x7B, 0x1F, 0x55, 0xD2, 0x13, 0xA7, 0x5F, 0xB2, 0x76, 0x75, 0xFD, 0xD8, 0xC7, 0xAB, 0xD1, 0xB0, 0x4D, 0x69, 0x54, 0xD6, 0xFE, 0xDE, 0xF8, 0x06, 0x7A, 0xFE, 0x66, 0x18, 0x01, 0x07, 0x65, 0xE6, 0x92, 0x6D, 0x78, 0x97, 0xF1, 0xBA, 0x4F, 0x30, 0x26, 0xC2, 0x5A, 0xC9, 0xD3, 0x67, 0x2C, 0xF1, 0x29, 0x4B, 0x2C, 0x2E};
	uint8_t r2modn[SIZE] = {0xC8, 0xF6, 0x32, 0x9D, 0xE1, 0x61, 0xBD, 0x2F, 0xDA, 0xA1, 0x1F, 0x69, 0xC7, 0x0B, 0x56, 0x7E, 0x26, 0x8B, 0x2D, 0xB8, 0xF3, 0x71, 0xBE, 0xDE, 0x22, 0x34, 0x38, 0x6B, 0x8B, 0xB5, 0x71, 0x69, 0x39, 0x08, 0x03, 0x05, 0x94, 0xB2, 0x91, 0x3F, 0x96, 0xC7, 0xB3, 0xE4, 0x48, 0x25, 0xF5, 0xF7, 0xB5, 0xD5, 0xD1, 0xF5, 0x1A, 0x06, 0x13, 0xE5, 0x9A, 0x81, 0xD6, 0xAD, 0x4C, 0xD4, 0x6D, 0x2C, 0x71, 0x1B, 0x4E, 0x5D, 0x4F, 0xE0, 0x7D, 0xEA, 0xE9, 0x63, 0x06, 0x34, 0x4C, 0xA6, 0xA9, 0xA9, 0x2A, 0x3F, 0x66, 0x1B, 0x51, 0x3B, 0x73, 0x44, 0x18, 0xFF, 0xFE, 0x30, 0x8B, 0xEF, 0x94, 0x4A, 0x7D, 0x3F, 0x92, 0x8F, 0x23, 0x3D, 0x22, 0xCF, 0x07, 0x1A, 0x85, 0xB7, 0x76, 0x5F, 0x03, 0xBA, 0x4B, 0x56, 0xA1, 0x42, 0x29, 0x21, 0x50, 0x98, 0xC9, 0xED, 0xD9, 0xEA, 0x25, 0x35, 0xAF, 0x24};


	uint8_t msg[] = {0x61,0x62,0x63};
	unsigned int msg_length = sizeof(msg);
	uint8_t msg_signature[SIZE];
	uint8_t public_key[2]= {0x01,0x01}; // exponent, length 2
	uint8_t private_key[SIZE] =      {0x01, 0x0F, 0xEC, 0x4A, 0xDD, 0x26, 0x57, 0x7D, 0x77, 0x31, 0x93, 0xE1, 0xCF, 0x05, 0xC5, 0x06, 0xE4, 0x0F, 0x04, 0xF9, 0x08, 0x57, 0x0C, 0x73, 0x21, 0xA9, 0x73, 0xFB, 0xA8, 0x3F, 0x53, 0x43, 0x1F, 0x7F, 0x4C, 0xC7, 0xD8, 0xB2, 0xFE, 0x6E, 0xC1, 0x72, 0x40, 0xF5, 0x6C, 0xA8, 0x68, 0x13, 0x87, 0x8B, 0x36, 0x21, 0x74, 0x59, 0x44, 0x66, 0xBF, 0xC7, 0x49, 0x24, 0x96, 0xC4, 0xFA, 0x0C, 0x8A, 0xF3, 0x84, 0xCE, 0xDC, 0xD0, 0x5C, 0x61, 0x9B, 0x2E, 0x9C, 0x51, 0xE9, 0x5D, 0xFA, 0x84, 0x65, 0x77, 0x4D, 0xF1, 0x90, 0x02, 0x21, 0x01, 0x11, 0x8A, 0xFE, 0x55, 0x6A, 0xD3, 0x8E, 0xB8, 0x57, 0x76, 0xED, 0xB0, 0xA2, 0x72, 0xEB, 0xBE, 0x31, 0x6C, 0x0D, 0x59, 0x9E, 0x63, 0x06, 0xB1, 0x18, 0xAE, 0xF5, 0x65, 0x83, 0xDE, 0x2A, 0xD2, 0x98, 0xB9, 0xD8, 0xF6, 0xBD, 0x25, 0x6E, 0x0B};
	uint8_t n[SIZE] =      {0x31, 0x6F, 0x7A, 0xE6, 0xE5, 0xBC, 0x77, 0xA6, 0xF8, 0x66, 0x9E, 0x3B, 0x02, 0xF4, 0xDF, 0x32, 0xC8, 0xA7, 0xB9, 0x2A, 0x1E, 0xBC, 0x08, 0xBE, 0x86, 0x11, 0xDE, 0x2A, 0xCF, 0xE8, 0x88, 0x8E, 0x3B, 0x5C, 0x6A, 0x71, 0x47, 0x3C, 0x45, 0x05, 0x46, 0xE4, 0xAD, 0x93, 0x42, 0x1F, 0x77, 0xDC, 0x25, 0x97, 0x70, 0xE1, 0xB5, 0xEB, 0x89, 0x7F, 0xA9, 0x1E, 0x50, 0x1D, 0x33, 0x99, 0x3C, 0x09, 0x68, 0xE4, 0x1A, 0xCF, 0xB0, 0x1E, 0xBA, 0x56, 0x24, 0x7C, 0x8E, 0x35, 0x84, 0xE0, 0xAA, 0x2D, 0xEC, 0x58, 0xA0, 0x4D, 0x89, 0x8A, 0x02, 0x27, 0x38, 0x54, 0x2E, 0x4F, 0xB2, 0x96, 0xAB, 0x29, 0x01, 0x21, 0x07, 0xF9, 0x85, 0x01, 0x99, 0xE7, 0xFE, 0xF8, 0x9A, 0x19, 0x6D, 0x92, 0x87, 0x68, 0x0E, 0x45, 0xB0, 0xCF, 0xD9, 0x3D, 0xA5, 0x36, 0x2C, 0x98, 0xD3, 0x0E, 0xD6, 0xB4, 0xD3, 0xD1}; // modulus
	RSASSA_PKCS1_V1_5_SIGN(msg_signature,private_key,SIZE,n,rmodn,r2modn, msg, msg_length);
	uint8_t sigValid = RSASSA_PKCS1V1_5_VERIFY(msg, msg_length, msg_signature,public_key, 2,n,rmodn,r2modn);
	printf("\nSignature Valid: %d\n",sigValid);
}

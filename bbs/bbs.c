/*
 * bbs.c
 *
 * @version 0.1 (March 2016)
 *
 * Implementation of the Blum-Blum-Shub algorithm to generate cryptographicly safe pseudorandom bits
 *
 * @author Axel Vanraes <axel.vanraes@student.kuleuven.be>
 * @author Micha묠Raes <michael.raes@student.kuleuven.be>
 */
#include <stdint.h>
#include <string.h>

#include "bbs.h"
#include "../constants.h"


/* Choose two primes p & q so that each congruent to 3 mod 4, then n = p*q. */
	uint32_t n = 1049*1061; // = 1 112 989
/* ------------------------------------------------------------------------- */

void random_byte(uint8_t *byte, uint32_t *seed){
	uint8_t i;
	for (i=0; i<8;i++){
		*seed = (*seed)*(*seed) % n; // the new seed: s(n) = s(n-1)² mod n
		*byte +=((*seed & 1) << i); // Select the LSB of seed en put in the bit with index i
	}
}

/* ------------------------------------------------------------------------- */

void generate_number(uint8_t *result, uint8_t len_bits, uint32_t seed) {
	
	uint16_t l = MAX_l; //Number of random bytes needed
	if(memcmp(&l, &len_bits,2)<0){
		l = len_bits;
	}

	uint16_t i; //max 256!!
	// The 'seed' has to be a value between 1 & n-1 such that gcd(s,n) = 1
	// TODO: check when the seed = n-2
	seed = (seed % n-1)+1;	
	
	for(i=0; i < l/8; i++){
		random_byte(result+i,&seed);
	}	
}




#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include <algorithm>

int main( int argc, char * argv[] ){
	int power, care_percent;
	unsigned long seed;
	mpz_t res, counter, care_num;
	gmp_randstate_t randstate;

	mpz_init( res );
	mpz_init( counter  );
	mpz_init( care_num );
	power = 1;
	care_percent = 100;
	if( argc>1 ) power = atoi(argv[1]);
	if( argc>2 ) care_percent = atoi(argv[2]);
	
	gmp_randinit_mt( randstate );
	gmp_randseed_ui( randstate, seed );
	mpz_set_ui( counter, 0 );
	for( int i=0;i<10; i++ ){
		mpz_urandomb( res, randstate, power );
		gmp_printf("%Zd\n",res);
	}
	gmp_randclear( randstate );
	mpz_clear( counter  );
	mpz_clear( care_num );
	mpz_clear( res );
}



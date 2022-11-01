
#include "f1.h"
#include "stdio.h"

static int isPrime(long long number) {

	if (number == 0 || number == 1 || (number % 2 == 0 && number > 2)) {
		return 0;
	}

	else {
		for (long long i=3; i <= number/2; i++) {
			if (number % i == 0) {
				return 0;
			}
		}
		return 1;
	}
}


void f1_solve(long long number) {
    unsigned int count = 0;

    for (long long i = number; i ; --i)
    {
        if(isPrime(i) == 1) {
            count ++;
        }
    }
    
    printf("%d\r\n", count);
}
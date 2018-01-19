/*
Problem:
The arithmetic sequence, 1487, 4817, 8147, in which each of the terms increases by 3330, is unusual in two ways: (i) each of the three terms are prime, and, (ii) each of the 4-digit numbers are permutations of one another.

There are no arithmetic sequences made up of three 1-, 2-, or 3-digit primes, exhibiting this property, but there is one other 4-digit increasing sequence.

What 12-digit number do you form by concatenating the three terms in this sequence?

Notes:
Any such sequence has to increment by a multiple of 6, or one of the values will be divisible by 2 or 3
*/

#include <stdio.h>

int is_prime(int n){
	int i;
	
	if(n % 2 == 0)
		return 0;
	
	//only check odd divisors to save time
	for(i = 3; i * i <= n; i+=2)
		if(n % i == 0)
			return 0;

	return 1;
}

int are_prime(int a, int b, int c){
	return is_prime(a) && is_prime(b) && is_prime(c);
}

int are_perms(int a, int b, int c){
	int dig1, dig2, dig3, amod = 0, bmod = 0, cmod = 0;
	while(a > 0 || b > 0 || c > 0){

		//get a digit
		dig1 = a%10;
		dig2 = b%10;
		dig3 = c%10;

		a /= 10;
		b /= 10;
		c /= 10;

		amod += 1<<dig1;
		bmod += 1<<dig2;
		cmod += 1<<dig3;
	}
	return amod == bmod && bmod == cmod;
}



int main(){
	int first, diff;
	for(first = 1001; first < 10000; first++)
		for(diff = 6; first + 2*diff < 10000; diff+=6)
			if(are_perms(first, first + diff, first + 2*diff) && are_prime(first, first + diff, first + 2*diff) && (first != 1487 || diff != 3330))
				printf("%d%d%d\n", first, first + diff, first + 2*diff);

}
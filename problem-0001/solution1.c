/*
Problem:
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
Find the sum of all the multiples of 3 or 5 below 1000.

Notes:
This will work for a given input value instead of 1000. Will look at values strictly below the input value.
*/

#include <stdio.h>

int main(){
	unsigned long n, sum = 0;
	scanf("%lu", &n);
	for(int i = 1; i < n; i++)
		if(i % 3 == 0 || i % 5 == 0)
			sum+=i;

	printf("%lu\n", sum);
}
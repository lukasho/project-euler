/*
Problem:
It can be seen that the number, 125874, and its double, 251748, contain exactly the same digits, but in a different order.

Find the smallest positive integer, x, such that 2x, 3x, 4x, 5x, and 6x, contain the same digits.

*/

#include <stdio.h>

int are_perms(int a, int b){
	int i;
	int diffs[10] = {0};
	while(a > 0 || b > 0){

		diffs[a%10]++;
		diffs[b%10]--;

		a /= 10;
		b /= 10;
	}

	for(i = 0; i < 10; i++)
		if(diffs[i])
			return 0;

	return 1;
}

int check(x){
	int mult;
	for(mult = 2; mult <= 6; mult++)
		if(!are_perms(x, mult*x))
			return 0;
	return 1;
}

int main(){
	int x = 0;
	
	while(!check(++x));

	printf("%d\n", x);

}
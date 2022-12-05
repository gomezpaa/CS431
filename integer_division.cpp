/*
=================================================================
= Program that performs integer division using global variables =
= Written by Paolo Gomez					=
= 06 September 2022						=
= Language: C++ (gcc target)					=
=================================================================
*/

#include <iostream>
using namespace std;

int N, 
    D, 
    Q, R,
    N_COPY;

void INTDIV();

/* Main Function: Asks user for a numerator, denominator and calls the function INTDIV() */
int main() {
	cout << "Welcome!" << endl;
	cout << "Enter a positive integer for the numerator: ";
	cin >> N;
	N_COPY = N;
	cout << "Enter another positive integer for the denominator: ";
	cin >> D;
	INTDIV();
	cout << "N is: " << N_COPY << endl;
	cout << "D is: " << D << endl;
	cout << "Q is: " << Q << endl;
	cout << "R is: " << R << endl;
	return 0;

}

/* INTDIV Function: Function performs integer division by subtracting the numerator by the 
 * denominator while the numerator is greater than or equal to denominator. */
void INTDIV() {
	Q = 0;
	while ( N>=D ) {
		N = N - D;
		Q += 1;
	}
	R = N;
}



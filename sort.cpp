/*
================================================================
= Program that performs a sort using global variables. In this =
= revised version, the scoping of the variables now match the  =
= the flow chart.					       =
= Written by Paolo Gomez			               =
= Version 1.1 (Revised)				               =
= 27 September 2022 (Updated: 17 October 2022)		       =
= Language: C++ (g++ target)			               =
================================================================
*/

#include <iostream>
using namespace std;

/* Functions */
void sort();
void move();
void Findkay();

/* Global Variables */
int n,
    a[99];

/*
=====================================================
= Main function that queries user for size of array =
= and asks user to fill array which will be sorted  =
= Written by Paolo				    =
= 27 September 2022				    =
= Language: C++ (g++ target)			    =
=====================================================
*/
int main() {
	cout << "Welcome! This program will fill and sort numbers in an array." << endl;
	cout << "Please enter how many numbers you want to sort (<99): ";
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cout << "Enter a positive integer for a[" << i <<"]: ";
		cin >> a[i];
	}
	sort();
	cout << "Sort complete! Final Result:" << endl;
	for (int i = 1; i <= n; i++) {
		cout << "a["<< i <<"]: " << a[i] << endl;
	}
}

/* Global variable in sort */
int j;

/* 
===================================
= Function that performs the sort =
= Written by Paolo		  =
= 27 September 2022		  =
= Language: C++ (g++ target)      =
===================================
*/

void sort() {
	for (j = 1; j <= (n-1); j++) {
		if ( a[j] > a[j+1] ) {
			move(); 
		}
	}
}

/* Global variables for move */
int temp,
    k;

/*
================================================
= Function that moves the numbers in the array =
= Written by Paolo			       =
= 27 September 2022			       =
= Language: C++ (g++ target)		       =
================================================
*/

void move() {
	temp = a[j+1];
	a[j+1] = a[j];
	Findkay();
	a[k] = temp;
}

/* Global variable for Findkay */
int sw;

/*
=======================================
= Function that assigns a value for k =
= Written by Paolo		      =
= 27 September 2022		      =
= Language: C++ (g++ target)	      =
=======================================
*/

void Findkay() {
	k = j;
	sw = 0;
	while ((k > 1) && (sw == 0)) {
		if (a[k-1] > temp) {
			a[k] = a[k-1];
			k = k - 1;
		}
		else {
			sw = 1;
		}
	}
}

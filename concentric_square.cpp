/*
 ============================================================
 = Program accepts a sequence of k characters from the user =
 = and use the characters to produce a k concentric square. =
 = This program uses recursion to complete the task.		=
 = Written by Paolo Gomez									=
 = 28 October 2022											=
 = Language: C++ (g++ compiler)								=
 ============================================================
 */

#include <iostream>
using namespace std;

/* Functions */
void con_square(char* a, int k, int index);

/* 
 =====================================================================
 = This main function asks the user for the number of characters, k, =
 = and the characters to make the concentric square.				 =
 = Written by Paolo Gomez											 =
 = 28 October 2022													 =
 = Language: C++ (g++ target)										 =
 =====================================================================
*/
int main() {
	int k;
	cout << "Welcome! This program will create a concentric" << endl;
	cout << "using the characters that you will input." << endl;
	cout << "Enter the number of characters: ";
	cin >> k;
	char a[k + 1];

	cout << "Enter " << k << " characters to make the concentric square:" << endl;
	
	for (int i = 1; i <= k; i++){
		cout << "a[" << i << "] = ";
		cin >> a[i];
	}
	con_square(a, k, k);
}
/* 
 ====================================================================
 = The con_square function creates the concentric square using the  =
 = characters that the user entered. The first part of the function =
 = creates the top half of the concentric square. The second half	=
 = of the function, after calling con_square, creates the second	=
 = half of the square.												=
 = Written by Paolo Gomez								  			=
 = 28 October 2022										  			=
 = Language: C++ (g++ target)							  			=
 ====================================================================
*/
void con_square(char* a, int k, int index){
	if (index < 1) { 
		return; 
	}
	for (int i = k + 1; i > index; i--){
		cout << a[i] <<" ";
	}
	for (int i = 1; i < 2*index-1; i++) {
		cout << a[index] << " ";
	}
	for (int i = index; i <= k; i++){
		cout << a[i] <<" ";
	}
	cout << endl;
	con_square(a, k, index-1);
	if (index == 1){ 
		return;
	}
	for (int i = k + 1; i > index; i--) {
		cout << a[i]<<" ";
	}
	for(int i = 1; i < 2*index-1; i++) {
		cout << a[index] <<" ";
	}
	for(int i = index; i <= k; i++){
		cout << a[i] <<" ";
	}
	cout << endl;
}

		
	
	

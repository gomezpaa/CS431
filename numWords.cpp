/*
====================================================================================================
= Program queries the user for the name of a .txt file, opens the file, and creates/maintains      =
= two lists. The first list has words that begins with the letter "D" or "d". The second list      =
= contains words that begin with any other letter. Each list is in alphabetical order and contains =
= the number of times the word appears.                                                            =
= Written by Paolo Gomez                                                                           =
= 18 November 2022                                                                                 =
= Language: C++ (g++ compiler)                                                                     =
====================================================================================================
*/

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <tuple>
#include <iomanip>
using namespace std;

int main() {
    list <tuple<string, int>> DList, OList;
    list <tuple<string,int>> :: iterator ptr;
    list <tuple<string,int>> :: iterator ptr1;
    string file, word;
    fstream inFile;

    cout << "\n";    
    cout << "======================================================================================" << endl;
    cout << "= Welcome! This program will read in a file and display a two lists of words.        =" << endl;
    cout << "= The lists are alphabetized and display the number of times the word appears.       =" << endl;
    cout << "= One list holds words with the letter d or D. The other list holds the other words. =" << endl;
    cout << "======================================================================================" << endl;
    cout << "\n";     
    cout << "Enter the name of the file you want to use: ";
    cin >> file;
    inFile.open(file);

    while (inFile >> word) {
        word[0] = tolower(word[0]);
        if (word[0] == 'd') {
            DList.push_front(make_tuple(word, 0));
        }
        else {
            OList.push_front(make_tuple(word, 0));
        }
    }

    for (ptr = DList.begin(); ptr != DList.end(); ptr++) {
        for (ptr1 = DList.begin(); ptr1 != DList.end(); ptr1++) {
            if (get<0>(*ptr) == get<0>(*ptr1)) {
                get<1>(*ptr)++;
            }
        }
    }

    for (ptr = OList.begin(); ptr != OList.end(); ptr++) {
        for (ptr1 = OList.begin(); ptr1 != OList.end(); ptr1++) {
            if (get<0>(*ptr) == get<0>(*ptr1)) {
                get<1>(*ptr)++;
            }
        }
    }

    DList.sort();
    DList.unique();

    cout << "\n";
    cout << "Now printing words that begin with the letter D: " << endl;
    for (ptr = DList.begin(); ptr != DList.end(); ptr++) {
        cout << setw(10) << get<0>(*ptr) << " "<< get<1>(*ptr) << endl;
    }

    OList.sort();
    OList.unique();

    cout << "\n";
    cout << "Now printing the remaining words: " << endl;
    for (ptr = OList.begin(); ptr != OList.end(); ptr++) {
        cout << setw(10) << get<0>(*ptr) << " "<< get<1>(*ptr) << endl;
    }
    
}

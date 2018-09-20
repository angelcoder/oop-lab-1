//
//  main.cpp
//  oop-lab-1
//
//  Created by Anhelina Lohvina on 06.09.2018.
//  Copyright © 2018 Anhelina Lohvina. All rights reserved.
//

#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>
#include "functions.hpp"
#include <cmath>
using namespace std;

const string m1 = "linear congruencs method";
const string m2 = "qudratic congruence method";
const string m3 = "fibonacci method";
const string m4 = "moodular inverse method";
const string m5 = "unification method";
const string m6 = "3Sigma method";
const string m7 = "polar coordinates method";
const string m8 = "relations method";
const string m9 = "log method";
const string m10 = "Arens method";

const string chose = "you chose ";

void methodsInfo(){
    cout << "1 - " << m1 << endl;
    cout << "2 - " << m2 << endl;
    cout << "3 - " << m3 << endl;
    cout << "4 - " << m4 << endl;
    cout << "5 - " << m5 << endl;
    cout << "6 - " << m6 << endl;
    cout << "7 - " << m7 << endl;
    cout << "8 - " << m8 << endl;
    cout << "9 - " << m9 << endl;
    cout << "0 - " << m10 << endl;
}
int main() {
    srand((uint)time(nullptr));
    int quantity = 10;
    char method = 'c';
    methodsInfo();
    //vector <double (*) ()> randFunctions = {rand1, rand2, rand3, rand4, rand5, rand6, rand7, rand8, rand9, rand10};
    try{
        do{
            cout << "Please, enter the number of method you would like to use:" << endl;
            cin >> method;
            switch(method){
                case '1': cout << chose << m1 << '\n'; printNumbers(quantity, method); break;
                case '2': cout << chose << m2 << '\n'; printNumbers(quantity, method); break;
                case '3': cout << chose << m3 << '\n'; printNumbers(quantity, method); break;
                case '4': cout << chose << m4 << '\n'; printNumbers(quantity, method); break;
                case '5': cout << chose << m5 << '\n'; printNumbers(quantity, method); break;
                case '6': cout << chose << m6 << '\n'; printNumbers(quantity, method); break;
                case '7': cout << chose << m7 << '\n'; printNumbers(quantity, method); break;
                case '8': cout << chose << m8 << '\n'; printNumbers(quantity, method); break;
                case '9': cout << chose << m9 << '\n'; printNumbers(quantity, method); break;
                case '0': cout << chose << m10 << '\n'; printNumbers(quantity, method); break;
                case 'E': break;
                default: cout << "Enter the number from 0 to 9\n\n";
            }
            cin.ignore(std::numeric_limits<int>::max(),'\n');
        } while (method != 'E');
    }
    catch (const invalid_argument &ex){ cout << ex.what();}
    catch (...) { cout << "ERROR! Someting is wrong\n";}
    system("pause");
    return 0;
}


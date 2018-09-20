//
//  functions.hpp
//  oop-lab-1
//
//  Created by Anhelina Lohvina on 06.09.2018.
//  Copyright © 2018 Anhelina Lohvina. All rights reserved.
//

#ifndef functions_hpp
#define functions_hpp

#include <stdio.h>
#include <iostream>
#include <iomanip>

typedef unsigned int uint;
typedef long long ll;

void srand(uint seedNum);

double rand1();
double rand2();
double rand3();

uint modInv(ll A, ll n);
double rand4();

double rand5();
double rand6();
double rand7();
double rand8();
double rand9();
double rand10();

void plusFreq(std::vector<int>& frequency, double N, double low, double high, int quantity);
void printNumbers(std::string methodName, int quantity, double(*function)(), double low, double high);

#endif /* functions_hpp */

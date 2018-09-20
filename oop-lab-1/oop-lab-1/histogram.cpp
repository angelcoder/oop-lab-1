//
//  histogram.cpp
//  oop-lab-1
//
//  Created by Anhelina Lohvina on 19.09.2018.
//  Copyright © 2018 Anhelina Lohvina. All rights reserved.
//

#include "functions.hpp"

#define For for (int i = 0; i < nNum; ++i)

const int defaultValue = 0;
const uint nNum= 100000;

void plusFreq(std::vector<int>& frequency, double N, double low, double high, int quantity){
    ++frequency[(N - low) / (high - low) * quantity];
}

void printNumbers(int quantity, int method){
    double low = 0, high = 1;
    std::vector<int> frequqency(quantity, defaultValue);
    switch(method){
        case '1': For{ double N = rand1(); plusFreq(frequqency, N, low, high, quantity);} break;
        case '2': For{ double N = rand2(); plusFreq(frequqency, N, low, high, quantity);} break;
        case '3': For{ double N = rand3(); plusFreq(frequqency, N, low, high, quantity);} break;
        case '4': For{ double N = rand4(); plusFreq(frequqency, N, low, high, quantity);} break;
        case '5': For{ double N = rand5(); plusFreq(frequqency, N, low, high, quantity);} break;
        case '6': For{ double N = rand6(); low = -3; high = 3; plusFreq(frequqency, N, low, high, quantity);} break;
        case '7': For{ double N = rand7(); low = -3; high = 3; plusFreq(frequqency, N, low, high, quantity);} break;
        case '8': For{ double N = rand8(); low = -3; high = 3; plusFreq(frequqency, N, low, high, quantity);} break;
        case '9': For{ double N = rand9(); low = 0; high = 100; plusFreq(frequqency, N, low, high, quantity);} break;
        case '0': For{ double N = rand10(); low = 0; high = 100; plusFreq(frequqency, N, low, high, quantity);} break;
    }
    for (int i = 0; i < quantity; ++i){
        cout << setprecision(1) << fixed << "[";
        cout << low + ((high - low) / quantity) * i;
        cout << ", ";
        double high_ = low + ((high - low) / quantity) * (i + 1);
        cout << high_;
        high_ == 1 ? cout << "]  " : cout << ")  ";
        cout << setprecision(5) << fixed << '\t';
        cout << (double)frequqency[i] / nNum << endl;
    }
}

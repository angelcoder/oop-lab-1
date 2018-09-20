//
//  functions.cpp
//  oop-lab-1
//
//  Created by Anhelina Lohvina on 06.09.2018.
//  Copyright © 2018 Anhelina Lohvina. All rights reserved.
//

#include "functions.hpp"
#include <cmath>
#include <vector>

const uint a = 1103515245;
const uint c = 12345;
const uint m = 4294967291; // 2^32-5
const uint d = 3;
const uint nNum= 100000;

const ll p = (ll)1 << 32;
const int defaultValue = 0;
const int med = 0;
const int sigma = 1;
const int miu = 9;
const int a9 = 10;
const int a4 = 17;
const int c4 = 2;

uint num1 = 1;
uint num2 = 1;
uint num3_1 = 1; uint num3_2 = 1;
uint num4 = 1;

void srand(uint seedNum) { num1 = seedNum; num2 = seedNum; }
double rand1() {
    num1 = (a * num1 + c) % m;
    return (double)(num1) / m;;
}

double rand2() {
    num2 = (d * num2 * num2 + a * num2 + c) % m;
    return (double)(num2) / m;
}

double rand3() {
    num3_2 = (num3_1 + num3_2) % m;
    num3_1 = (num3_2 - num3_1 + m) % m;
    return (double)(num3_1) / m;
}

uint modInv(ll A, ll n) {
    ll b0 = n, t, q;
    ll x0 = 0, x1 = 1;
    if (n == 1) return 1;
    while (A > 1) {
        q = A / n;
        t = n; n = A % n; A = t;
        t = x0; x0 = x1 - q * x0; x1 = t;
    }
    if (x1 < 0) x1 += b0;
    return (uint)x1;
}

double rand4() {
    num4 = (a4 * modInv(num4, p) + c4) % p;
    return (double)(num4) / m;
}

double rand5(){
    double x = rand1(), y = rand1();
    double a = 1.0;
    a= (x >= y) ? (x - y) : (x - y + 1);
    return a;
}

double rand6() {
    double sum = 0;
    for (int i = 0; i < 12; ++i) sum += rand1();
    return (med + (sum - 6) * sigma);
}

double rand7() {
    double u1, u2, v1, v2, s;
    do{
        u1 = rand1();
        u2 = rand1();
        v1 = 2 * u1 - 1;
        v2 = 2 * u2 - 1;
        s = v1 * v1 + v2 * v2;
    } while (s >= 1);
    double x1 = v1 * sqrt(-2 * log(s) / s);
    double x2 = v2 * sqrt(-2 * log(s) / s);
    return (rand1() > 0.5) ? x1 : x2;
}

double rand8() {
    double u = rand1(), v, x;
    do{
        do{ v = rand1();} while (v == 0);
        x = sqrt(8.0 / M_E) * (v - 0.5) / u;
    } while(x * x > - 4 * log(u));
    return x;
}

double rand9() {
    double x = 1.0;
    double U = rand1();
    if (U != 0) x = -miu * log(U);
    return x;
}

double rand10() {
    double U, x, y, V;
    do{
        do{
            U = rand1();
            y = tan(M_PI * U);
            x = sqrt(2 * a9 - 1) * y + a9 - 1;
        } while(x <= 0);
        V = rand1();
    } while((V > (1 + y * y) * exp((a9 - 1) * log(x / (a9 - 1)) - sqrt(2 * a9 - 1) * y)));
    return x;
}

void plusFreq(std::vector<int>& frequency, double N, double low, double high, int quantity) {
    ++frequency[(N - low) / (high - low) * quantity];
}

void printNumbers(std::string methodName, int quantity, double(*function)(), double low, double high) {
    std::cout << "you chose " << methodName << std::endl;
    std::vector<int> frequqency(quantity, defaultValue);
    double sum = 0.0;
    for (int i = 0; i < nNum; ++i) {
        double N = function();
        plusFreq(frequqency, N, low, high, quantity);
    }
    for (int i = 0; i < quantity; ++i) {
        std::cout << std::setprecision(1) << std::fixed << "[";
        std::cout << low + ((high - low) / quantity) * i;
        std::cout << ", ";
        double high_ = low + ((high - low) / quantity) * (i + 1);
        std::cout << high_;
        high_ == 1 ? std::cout << "]  " : std::cout << ")  ";
        std::cout << std::setprecision(5) << std::fixed << '\t';
        std::cout << (double)frequqency[i] / nNum << std::endl;
        sum+=(double)frequqency[i] / nNum ;
    }
    std::cout << sum << std::endl << std::endl;
}

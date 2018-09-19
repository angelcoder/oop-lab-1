//
//  main.cpp
//  Lab-1 OOP
//
//  Created by Anhelina Lohvina on 06.09.2018.
//  Copyright © 2018 Anhelina Lohvina. All rights reserved.
//

#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>
#include <cmath>
using namespace std;

typedef unsigned int uint;
typedef long long ll;
#define For for (int i = 0; i < nNum; ++i)

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

const uint a = 1103515245;
const uint c = 12345;
const uint m = 4294967291; //2^32-5
const uint d = 3;          //just do it
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
void srand(uint seedNum){ num1 = seedNum; num2 = seedNum;}
double rand1(){                   //Лінійний конгруентний метод
    num1 = (a * num1 + c) % m;
    return (double)(num1) / m;;
}

double rand2() {                  //Квадратичний конгруентний метод
    num2 = (d * num2 * num2 + a * num2 + c) % m;
    return (double)(num2) / m;
}

double rand3() {                  //Числа Фібоначчі
    num3_2 = (num3_1 + num3_2) % m;
    num3_1 = (num3_2 - num3_1 + m) % m;
    return (double)(num3_1) / m;
}

uint modInv(ll A, ll n){
     ll b0 = n, t, q;
     ll x0 = 0, x1 = 1;
     if (n == 1) return 1;
     while (A > 1){
         q = A / n;
         t = n; n = A % n; A = t;
         t = x0; x0 = x1 - q * x0; x1 = t;
     }
 if (x1 < 0) x1 += b0;
 return (uint)x1;
 }

double rand4(){                   //Обернена конгруентна послідовність
    num4 = (a4 * modInv(num4, p) + c4) % p;
    return (double)(num4) / m;
}

double rand5(){                   //Метод об'єднання
    double x = rand1(), y = rand1();
    double a = 1.0;
    a= (x >= y) ? (x - y) : (x - y + 1);
    cout<<a<<' ';
    return a;
}

double rand6(){                   //Правило “3 сігма”
    double sum = 0;
    for (int i = 1; i <= 12; ++i) sum += rand1();
    return (med + (sum - 6) * sigma);
}

double rand7(){                   //Метод полярних координат
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

double rand8(){                  //Метод співвідношень
    double u = rand1(), v, x;
    do{
       do{ v = rand1();} while (v == 0);
          x = sqrt(8.0 / M_E) * (v - 0.5) / u;
    } while(x * x > - 4 * log(u));
    return x;
}

double rand9(){                   //Метод логарифму для генерування показового розподілу
    double x = 1.0;
    double U = rand1();
    if (U != 0) x = -miu * log(U);
    return x;
}

double rand10(){                  //Метод Аренса для генерування гамма-розподілу порядку a > 1
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

void plusFreq(vector<int>& frequency, double N, double low, double high, int quantity){
    ++frequency[(N - low) / (high - low) * quantity];
}

void printNumbers(int quantity, int method){
    double low = 0, high = 1;
    vector<int> frequqency(quantity, defaultValue);
    switch(method){
        case '1': For{ double N = rand1(); /*if (i==5) N5=N; if(N!=N1) count1++;*/ plusFreq(frequqency, N, low, high, quantity);} break;
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

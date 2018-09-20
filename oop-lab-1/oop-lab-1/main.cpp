//
//  main.cpp
//  oop-lab-1
//
//  Created by Anhelina Lohvina on 06.09.2018.
//  Copyright © 2018 Anhelina Lohvina. All rights reserved.
//

#include <iostream>
#include <vector>
#include <limits>
#include <cmath>
#include "functions.hpp"

const std::string m1 = "linear congruencs method";
const std::string m2 = "qudratic congruence method";
const std::string m3 = "fibonacci method";
const std::string m4 = "moodular inverse method";
const std::string m5 = "unification method";
const std::string m6 = "3Sigma method";
const std::string m7 = "polar coordinates method";
const std::string m8 = "relations method";
const std::string m9 = "log method";
const std::string m10 = "Arens method";

void methodsInfo() {
    std::cout << "1 - " << m1 << std::endl;
    std::cout << "2 - " << m2 << std::endl;
    std::cout << "3 - " << m3 << std::endl;
    std::cout << "4 - " << m4 << std::endl;
    std::cout << "5 - " << m5 << std::endl;
    std::cout << "6 - " << m6 << std::endl;
    std::cout << "7 - " << m7 << std::endl;
    std::cout << "8 - " << m8 << std::endl;
    std::cout << "9 - " << m9 << std::endl;
    std::cout << "0 - " << m10 << std::endl;
}

int main() {
    srand((uint)time(nullptr));
    int quantity = 10;
    uint method = 0;
    methodsInfo();
    std::vector <double (*) (void)> randFunctions = {rand10, rand1, rand2, rand3, rand4, rand5, rand6, rand7, rand8, rand9};
    std::string methodName[10] = {m10, m1, m2, m3, m4, m5, m6, m7, m8, m9};
    try{
        std::cout << "Please, enter the number of method you would like to use:" << std::endl;
        std::cout << "Press anything except numbers to finish"<<std::endl;;
        while (method <= 10 && std::cin >> method) {
            double low = 0.0;
            double high = 0.0;
            low = (method >= 6 && method <= 8) ? -3.0 : 0.0;
            high = (method == 0 || method == 9) ? 100.0 : ((method <= 5) ? 1.0 : 3.0);
            printNumbers(methodName[method], quantity, randFunctions[method], low, high);
        }
        while (method > 10) std::cout<<"Wrong number of method\n";
        std::cin.ignore(std::numeric_limits<int>::max(),'\n');
    }
    catch (const std::invalid_argument &ex){ std::cout << ex.what(); }
    catch (...) {std::cout << "ERROR! Someting is wrong\n"; }
    system("pause");
    return 0;
}



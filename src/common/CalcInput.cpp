//========================================================================
// InputParser.cpp
//========================================================================
// Implements parsing inputs and calling correct math functions.

#include <iostream>
#include <string>
#include <CalcInput.h>
#include <CalculatorFunctions.h>
#include <vector>
using namespace std;

// True if the string is a valid number, otherwise false.
// TODO: negative numbers, decimals
bool check_number(string num) {
    for (size_t i = 0; i < num.length(); i++) {
        if (!isdigit(num[i])) {
            return false;
        }
    }
    return true;
}

int bop(vector<string> bop_vec) {
    // Handles binary operations and prints output accordingly, or returns nothing when bad input occurs.
    int inp1 = stoi(bop_vec.at(0));
    int inp2 = stoi(bop_vec.at(2));
    string op = bop_vec.at(1);
    int res = 0;
    if (op == "+") {
        res = inp1 + inp2;
    }
    else if (op == "-") {
        res = inp1 - inp2;
    }
    else if (op == "*") {
        res = inp1 * inp2;
    }
    else if (op == "/") {
        res = inp1 / inp2;
    }
    else {
        throw invalid_argument("Bad input");
    }
    return res;
}


string calculateInput(string input) {
    int pos = input.find(" ");
    string delim = " ";
    vector<string> input_vec;

    // put token in array
    while ((pos = input.find(" ")) != string::npos) {
        string token = input.substr(0, pos);
        input_vec.push_back(token);
        input.erase(0, pos + delim.length());
    }
    input_vec.push_back(input);

    if (input_vec.size() == 3) {
        // bop 
        return to_string(bop(input_vec));
    } 
    else if (input_vec.at(0) == "sqrt") {
        double num = stoi(input_vec.at(1)) * 1.0;
        return to_string(findSqrt(num));
    }

}
    

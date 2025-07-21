//You are given an array of strings tokens that represents a valid arithmetic expression in Reverse Polish Notation.
//
//Return the integer that represents the evaluation of the expression.
//
//The operands may be integers or the results of other operations.
//The operators include '+', '-', '*', and '/'.
//Assume that division between integers always truncates toward zero.
//Example 1:
//
//Input: tokens = ["1", "2", "+", "3", "*", "4", "-"]
//
//Output : 5
//
//Explanation : ((1 + 2) * 3) - 4 = 5

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> stk;

        for (const string& token : tokens) {
            if (token != "+" && token != "-" && token != "*" && token != "/") {
                stk.push_back(stoi(token));
            }
            else {
                int b = stk.back(); stk.pop_back();
                int a = stk.back(); stk.pop_back();

                if (token == "+") { stk.push_back(a+b); }
                if (token == "-") { stk.push_back(a - b); }
                if (token == "*") { stk.push_back(a * b); }
                if (token == "/") { stk.push_back(a / b); }
            }
        }
        return stk.back();
    }
};
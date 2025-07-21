//You are given an integer n.Return all well - formed parentheses strings that you can generate with n pairs of parentheses.
//
//	Example 1:
//
//Input: n = 1
//
//Output : ["()"]
//	
//	Example 2 :
//
//Input : n = 3
//
//Output : ["((()))", "(()())", "(())()", "()(())", "()()()"]
//You may return the answer in any order.

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <stack>

using namespace std;

struct State {
    string s;
    int open = 0;
    int close = 0;
};

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        stack<State> stk;
        vector<string> result;

        stk.push({ "", 0, 0 });

        while (!stk.empty()) {
            State current = stk.top();
            stk.pop();

            if (current.s.length() == 2 * n) {
                result.push_back(current.s);
                return;
            }

            if (current.open < n) {
                stk.push({ current.s + "(", current.open + 1, current.close });
            }

            if (current.close < current.open) {
                stk.push({ current.s + ")", current.open, current.close + 1 });
            }
        }

        return result;
    }
};
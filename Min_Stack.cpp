#include <iostream>
#include <vector>
using namespace std;

class MinStack {
private:
    vector<vector<int>> stk;
public:
    MinStack() {}

    void push(int val) {
        int min_val = getMin();
        if (stk.empty() || min_val > val) {
            min_val = val;
        }
        stk.push_back({ val, min_val});
    }

    void pop() {
        stk.pop_back();
    }

    int top() {
        return stk.empty() ? -1 : stk.back()[0];
    }

    int getMin() {
        return stk.empty() ? -1 : stk.back()[1];
    }
};
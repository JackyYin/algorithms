#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;

        for (string tok : tokens) {
            if (tok[0] == '+') {
                int rightVal = stk.top();
                stk.pop();
                int leftVal = stk.top();
                stk.pop();
                stk.push(leftVal + rightVal);
            } else if (tok[0] == '-' && tok.length() == 1) {
                int rightVal = stk.top();
                stk.pop();
                int leftVal = stk.top();
                stk.pop();
                stk.push(leftVal - rightVal);
            } else if (tok[0] == '*') {
                int rightVal = stk.top();
                stk.pop();
                int leftVal = stk.top();
                stk.pop();
                stk.push(leftVal * rightVal);
            } else if (tok[0] == '/') {
                int rightVal = stk.top();
                stk.pop();
                int leftVal = stk.top();
                stk.pop();
                stk.push(leftVal / rightVal);
            } else {
                stk.push(stoi(tok));
            }
        }

        return stk.top();
    }
};

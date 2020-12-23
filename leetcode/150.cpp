#include <vector>
#include <stack>
#include <algorithm>
#include <string>
#include <ctype.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;

        for_each(tokens.begin(), tokens.end(), [&](string t) {
            if (isdigit(t[0]) || (t.size() > 1 && t[0] == '-' && isdigit(t[1]))) {
                s.push(stoi(t));
            } else {
                int operand2 = s.top();
                s.pop();
                int operand1 = s.top();
                s.pop();

                switch (t[0]) {
                    case '+':
                        s.push(operand1 + operand2);
                        break;
                    case '-':
                        s.push(operand1 - operand2);
                        break;
                    case '*':
                        s.push(operand1 * operand2);
                        break;
                    case '/':
                        s.push(operand1 / operand2);
                        break;
                }
            }
        });

        return s.top();
    }
};

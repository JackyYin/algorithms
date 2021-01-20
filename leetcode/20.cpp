#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stack;

        for (int i = 0; i < (int) s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                stack.push(s[i]);
            } else if (s[i] == ')') {
                if (stack.empty() || stack.top() != '(') return false;
                stack.pop();
            } else if (s[i] == ']') {
                if (stack.empty() || stack.top() != '[') return false;
                stack.pop();
            } else if (s[i] == '}') {
                if (stack.empty() || stack.top() != '{') return false;
                stack.pop();
            }
        }

        return stack.empty();
    }
};

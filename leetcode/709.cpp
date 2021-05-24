#include <unordered_map>
#include <string>
using namespace std;

class Solution {
private:
    unordered_map<char, char> m = {
        {'A', 'a'},
        {'B', 'b'},
        {'C', 'c'},
        {'D', 'd'},
        {'E', 'e'},
        {'F', 'f'},
        {'G', 'g'},
        {'H', 'h'},
        {'I', 'i'},
        {'J', 'j'},
        {'K', 'k'},
        {'L', 'l'},
        {'M', 'm'},
        {'N', 'n'},
        {'O', 'o'},
        {'P', 'p'},
        {'Q', 'q'},
        {'R', 'r'},
        {'S', 's'},
        {'T', 't'},
        {'U', 'u'},
        {'V', 'v'},
        {'W', 'w'},
        {'X', 'x'},
        {'Y', 'y'},
        {'Z', 'z'}
    };
public:
    string toLowerCase(string s) {
        for (int i = 0; i < s.length(); i++) {
            if (m.count(s[i]) > 0) {
                s[i] = m[s[i]];
            }
        }
        
        return s;
    }
};

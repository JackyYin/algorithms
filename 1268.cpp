#include <string>
#include <vector>
using namespace std;

class TrieNode {
public:
    TrieNode(string s, bool stp);
    TrieNode* dictionary[26];
    string    str;
    bool      stop;
};

TrieNode::TrieNode(string s, bool stp)
{
    str = s;
    stop = stp;
    for (int i = 0; i < 26; i++) {
        dictionary[i] = nullptr;
    }
}

void search (TrieNode *node, vector<string>& tmp)
{
    if (tmp.size() == 3) return;
    if (node->stop) tmp.push_back(node->str);

    for (int i = 0; i < 26; i++) {
        if (tmp.size() == 3) break;

        if (node->dictionary[i]) {
            search(node->dictionary[i], tmp);
        }
    } 
}

class Solution {
public:
    vector< vector<string> > suggestedProducts(vector<string>& products, string searchWord) {
        TrieNode *root = new TrieNode("", false);
        for (string product : products) {
            TrieNode *cur = root;

            for (int i = 0; i < (int) product.size(); i++) {
                if (!cur->dictionary[product[i] - 'a']) {
                    TrieNode *node = new TrieNode(cur->str + product[i], false);
                    cur->dictionary[product[i] - 'a'] = node;                    
                } 
                cur = cur->dictionary[product[i] - 'a'];
            }

            cur->stop = true;
        }

        bool terminated = false;
        vector< vector<string> > res;
        TrieNode *cur = root;
        for (int i = 0; i < (int) searchWord.size(); i++) {
            vector<string> cres;
            if (terminated) {
                res.push_back(cres);
                continue;
            } 
            if (!cur->dictionary[searchWord[i] - 'a']) {
                terminated = true;
                res.push_back(cres);
                continue;
            }

            cur = cur->dictionary[searchWord[i] - 'a'];
            search(cur, cres);
            res.push_back(cres);
        } 
        return res;
    }
};

class Solution {
private:
    static string toCountStr(string str) {
        int freq[26];
        for (auto c : str)
            freq[c - 'a']++;
        
        string cnt;
        for (int i = 0; i < 26; i++) {
            //cnt += to_string(freq[i]) + (char)('a' + i) + ',';
            cnt += to_string(freq[i]);
            cnt += (char)('a'+i);
            cnt += ',';
        }
        //cnt = cnt.substr(0, cnt.size()-1);
        //cout << cnt << endl;
        printf("0x%x, 0x%x, 0x%x\n", cnt[0], cnt[1], cnt[2]);
        return cnt;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;

        for (auto str : strs) {
            string cnt = toCountStr(str);
            m[cnt].push_back(str);
        }

        vector<vector<string>> ans;
        for (const auto& [key, value] : m) {
            ans.push_back(value);
        }
        return ans;
    }
};

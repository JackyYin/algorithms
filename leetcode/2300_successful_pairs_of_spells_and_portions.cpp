class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int m = spells.size();
        int n = potions.size();

        vector<pair<int, int>> sortedSpells;
        for (int i = 0; i < m; i++)
            sortedSpells.push_back({spells[i], i});

        // O(mlogm) + O(nlogn)
        sort(sortedSpells.begin(), sortedSpells.end());
        sort(potions.begin(), potions.end());

        vector<int> ans(m, 0);
        int potionIdx = n-1;
        for (const auto& [spell, index] : sortedSpells) {
            //printf("%d, %d\n", spell, index);
            while (potionIdx >= 0 && (long long)potions[potionIdx] * spell >= success) {
                potionIdx--;
            }
            ans[index] = (n-potionIdx-1);
        }
        return ans;
    }
};

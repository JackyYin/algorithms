class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int idx = digits.size() - 1;

        while (idx >= 0) {
            if (digits[idx] < 9) {
                digits[idx]++;
                return digits;
            }
            digits[idx--] = 0;
        }

        digits[0] = 1;
        digits.push_back(0);
        return digits;
    }
};

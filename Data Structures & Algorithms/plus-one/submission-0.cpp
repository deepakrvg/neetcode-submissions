class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int cy = 1;
        for (int i = n - 1; i >= 0; i--) {
            int sum = digits[i] + cy;
            cy = sum / 10;
            int rem = sum % 10;
            digits[i] = rem;
        }
        if (cy) {
            digits.insert(digits.begin(), cy);
        }
        return digits;
    }
};

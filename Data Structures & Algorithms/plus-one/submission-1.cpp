class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        // int n = digits.size();
        // int cy = 1;
        // for (int i = n - 1; i >= 0; i--) {
        //     int sum = digits[i] + cy;
        //     cy = sum / 10;
        //     int rem = sum % 10;
        //     digits[i] = rem;
        // }
        // if (cy) {
        //     digits.insert(digits.begin(), cy);
        // }
        // return digits;

        int n = digits.size();
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }
        digits[0] = 1;
        digits.push_back(0);
        return digits;
    }
};

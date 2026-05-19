class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        string ans = "";
        int n = num1.size();
        int m = num2.size();
        vector<int> result(n + m, 0);
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int d1 = num1[i] - '0';
                int d2 = num2[j] - '0';
                int sum = (d1 * d2) + result[i + j + 1];
                result[i + j + 1] = sum % 10;
                result[i + j] += sum / 10;
            }
        }
        
        int start = 0;
        while (start < result.size() && result[start] == 0) {
            start++;
        }

        while (start < result.size()) {
            ans.push_back(result[start] + '0');
            start++;
        }
        
        return ans;
    }
};

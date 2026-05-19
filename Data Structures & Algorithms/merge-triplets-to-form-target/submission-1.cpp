class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int a = INT_MIN, b = INT_MIN, c = INT_MIN;
        for (auto v : triplets) {
            if (v[0] > target[0] || v[1] > target[1] || v[2] > target[2]) {
                continue;
            } 
            a = max(a, v[0]);
            b = max(b, v[1]);
            c = max(c, v[2]);
            
            if (target[0] == a && target[1] == b && target[2] == c) {
                return true;
            }
        }

        return false;
    }
};

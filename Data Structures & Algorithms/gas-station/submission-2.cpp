class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_gas = 0;
        int total_cost = 0;
        int total = 0;
        int start = 0;
        int n = gas.size();
        for (int i = 0; i < n; i++) {
            total_gas += gas[i];
            total_cost += cost[i];
            total += gas[i] - cost[i];
            if (total < 0) {
                start = i + 1;
                total = 0;
            }
        }
        if (total_gas < total_cost) {
            return -1;
        }
        return start;
    }
};

class Solution {
public:
    double myPow(double x, int n) {
        long long power = n;
        if (power < 0) {
            power = -power;
            x = 1.0 / x;
        }

        double res = 1.0;
        while (power > 0) {
            if (power % 2 == 1) {
                res = res * x;
                power--;
            }
            x = x * x;
            power = power / 2;
        }
        return res;
    }
};

class Solution {
public:
    int getNext(int n) {
        int total = 0;
        while (n > 0) {
            int digit = n % 10;
            n = n / 10;
            total += digit * digit;
        }
        return total;
    }

    bool isHappy(int n) {
        int slow = n;
        int fast = getNext(n);
        while (slow != fast) {
            slow = getNext(slow);
            fast = getNext(getNext(fast));
        }
        if (slow == 1 && fast == 1) {
            return true;
        }
        return false;
    }
};

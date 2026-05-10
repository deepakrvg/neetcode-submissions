class MedianFinder {
public:
    multiset<int> mt;
    multiset<int>::iterator mid;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        mt.insert(num);
        if (mt.size() == 1) {
            mid = mt.begin();
            return;
        }
        if (num < *mid) {
            if (mt.size() % 2 == 0) {
                mid--;
            }
        }
        else {
            if (mt.size() % 2 == 1) {
                mid++;
            }
        }
    }
    
    double findMedian() {
        if (mt.size() % 2 == 1) {
            return *mid;
        }
        else {
            multiset<int>::iterator next = mid;
            next++;
            return (*mid + *next) / 2.0;
        }
    }
};

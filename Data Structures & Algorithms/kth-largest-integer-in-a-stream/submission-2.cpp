class PriorityQueue {
private:
    // get left child index
    int left(int i) {
        return ((2 * i) + 1);
    }

    // get right child index
    int right(int i) {
        return ((2 * i) + 2);
    }

    // get parent index
    int parent(int i) {
        return ((i - 1) / 2);
    }

public:
    vector<int> heap;
    PriorityQueue() {
    }

    // get top element
    int top() {
        return heap[0];
    }

    // get heap size
    int size() {
        return heap.size();
    }

    // is heap empty
    bool empty() {
        return (heap.size() == 0);
    }

    // push element in heap
    void push(int num) {
        heap.push_back(num);
        bubbleUp();
    }

    // pop element in heap
    int pop() {
        int topElement = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) bubbleDown();
        return topElement;
    }

    void bubbleDown() {
        int i = 0;
        int n = heap.size();
        while (true) {
            int smallest = i;
            int l = left(i);
            int r = right(i);
            if (l < n && heap[l] < heap[smallest]) {
                smallest = l;
            }
            if (r < n && heap[r] < heap[smallest]) {
                smallest = r;
            }
            if (smallest == i) {
                break;
            }

            swap(heap[i], heap[smallest]);
            i = smallest;
        }
    }

    void bubbleUp() {
        int i = heap.size() - 1;
        while (i > 0 && heap[i] < heap[parent(i)]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }
};

class KthLargest {
public:
    PriorityQueue* pq = new PriorityQueue();
    int k;

    KthLargest(int kt, vector<int>& nums) {
        k = kt;
        for (int num : nums) {
            pq->push(num);
            if (pq->size() > k) {
                pq->pop();
            }
        }
    }

    int add(int val) {
        pq->push(val);
        if (pq->size() > k) {
            pq->pop();
        }
        return pq->top();
    }
};

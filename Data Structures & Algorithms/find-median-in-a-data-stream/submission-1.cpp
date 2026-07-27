class MedianFinder {
   public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    MedianFinder() {}

    void addNum(int num) {  // T.C. - O(log n) , S.C. - O(n)
        maxHeap.push(num);
        minHeap.push(maxHeap.top());
        maxHeap.pop();
        if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian() {  // T.C. - O(1) , S.C. - O(1)
        if (maxHeap.size() == minHeap.size()) {
            return ((maxHeap.top() + minHeap.top()) / 2.0);
        }
        return maxHeap.top();
    }
};
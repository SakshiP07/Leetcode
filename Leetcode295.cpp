#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

class MedianFinder {
private:
    priority_queue<int> leftMaxHeap;
    priority_queue<int, vector<int>, greater<int>> rightMinHeap;

public:
    MedianFinder() {}

    void addNum(int num) {
        leftMaxHeap.push(num);

        rightMinHeap.push(leftMaxHeap.top());
        leftMaxHeap.pop();

        if (rightMinHeap.size() > leftMaxHeap.size()) {
            leftMaxHeap.push(rightMinHeap.top());
            rightMinHeap.pop();
        }
    }

    double findMedian() {
        if (leftMaxHeap.size() > rightMinHeap.size()) {
            return leftMaxHeap.top();
        }

        return (leftMaxHeap.top() + rightMinHeap.top()) / 2.0;
    }
};

int main() {
    MedianFinder mf;

    mf.addNum(1);
    mf.addNum(2);
    cout << "Median: " << mf.findMedian() << endl;

    mf.addNum(3);
    cout << "Median: " << mf.findMedian() << endl;

    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

class NumArray {
private:
    vector<int> bit;
    vector<int> nums;
    int n;

    void updateBIT(int index, int delta) {
        index++;

        while (index <= n) {
            bit[index] += delta;
            index += index & (-index);
        }
    }

    int getSum(int index) {
        index++;
        int sum = 0;

        while (index > 0) {
            sum += bit[index];
            index -= index & (-index);
        }

        return sum;
    }

public:
    NumArray(vector<int>& nums) {
        this->nums = nums;
        n = nums.size();
        bit.resize(n + 1, 0);

        for (int i = 0; i < n; i++) {
            updateBIT(i, nums[i]);
        }
    }

    void update(int index, int val) {
        int delta = val - nums[index];
        nums[index] = val;
        updateBIT(index, delta);
    }

    int sumRange(int left, int right) {
        return getSum(right) - getSum(left - 1);
    }
};

int main() {
    vector<int> nums = {1, 3, 5};

    NumArray numArray(nums);

    cout << numArray.sumRange(0, 2) << endl; // 9

    numArray.update(1, 2);

    cout << numArray.sumRange(0, 2) << endl; // 8

    return 0;
}
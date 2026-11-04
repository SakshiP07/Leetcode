#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int i = 0;
    for (int j = 1; j < nums.size(); j++) {
        if (nums[i] != nums[j]) {
            i++;
            nums[i] = nums[j];
        }
    }
    return i + 1;
}

int main() {
    vector<int> nums = {1, 1, 2, 2, 3, 4, 4};
    int k = removeDuplicates(nums);

    cout << k << endl;

    for (int i = 0; i < k; i++)
        cout << nums[i] << " ";

    return 0;
}
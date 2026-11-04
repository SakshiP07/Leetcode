#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0;
        int maxLength = 0;

        for (int i = 0; i < s.size(); i++) {
            expand(s, i, i, start, maxLength);
            expand(s, i, i + 1, start, maxLength);
        }

        return s.substr(start, maxLength);
    }

private:
    void expand(string& s, int left, int right, int& start, int& maxLength) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            int length = right - left + 1;

            if (length > maxLength) {
                start = left;
                maxLength = length;
            }

            left--;
            right++;
        }
    }
};

int main() {
    Solution solution;

    string s = "babad";

    cout << solution.longestPalindrome(s) << endl;

    return 0;
}
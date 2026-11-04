#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> words(wordDict.begin(), wordDict.end());
    int n = s.length();
    vector<bool> dp(n + 1, false);

    dp[0] = true;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            string currentWord = s.substr(j, i - j);

            if (dp[j] && words.count(currentWord)) {
                dp[i] = true;
                break;
            }
        }
    }

    return dp[n];
}

int main() {
    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};

    bool result = wordBreak(s, wordDict);

    if (result)
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}
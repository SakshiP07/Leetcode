#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);

        for (auto& pre : prerequisites) {
            int course = pre[0];
            int prerequisite = pre[1];

            graph[prerequisite].push_back(course);
            indegree[course]++;
        }

        queue<int> q;

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int completed = 0;

        while (!q.empty()) {
            int current = q.front();
            q.pop();
            completed++;

            for (int next : graph[current]) {
                indegree[next]--;

                if (indegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        return completed == numCourses;
    }
};

int main() {
    Solution solution;

    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1, 0}};

    cout << solution.canFinish(numCourses, prerequisites) << endl;

    return 0;
}
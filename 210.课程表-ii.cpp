/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II
 */

// @lc code=start

// 拓扑排序（广度优先搜索）

class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> graph(numCourses, vector<int>()); // 邻接矩阵
        vector<int> inDegree(numCourses, 0);                  // 入度数组
        vector<int> ans;
        // 初始化邻接矩阵和入度数组
        for (const auto &prerequisite : prerequisites)
        {
            graph[prerequisite[1]].push_back(prerequisite[0]);
            inDegree[prerequisite[0]]++;
        }
        queue<int> q;
        // 把入度为0的节点（即没有前置课程要求）放在队列中
        for (int i = 0; i < inDegree.size(); i++)
            if (inDegree[i] == 0)
                q.push(i);

        while (!q.empty())
        {
            // 每次从队列中获得节点，我们将该节点放在排序的末尾，并且把它指向的课程的入度各减1
            int u = q.front();
            q.pop();
            ans.push_back(u);
            for (auto &v : graph[u])
            {
                inDegree[v]--;
                // 有课程的所有前置必修课都已修完（即入度为0），我们把这个节点加入队列中
                if (inDegree[v] == 0)
                    q.push(v);
            }
        }
        // 当队列的节点都被处理完时，说明所有的节点都已排好序，或因图中存在循环而无法上完所有课程
        for (int &in : inDegree)
            if (in != 0)
                return vector<int>(); // 不可能完成所有课程，返回一个空数组
        return ans;
    }
};
// @lc code=end

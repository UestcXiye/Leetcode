/*
 * @lc app=leetcode.cn id=1462 lang=cpp
 *
 * [1462] 课程表 IV
 */

// @lc code=start

// 拓扑排序（广度优先搜索）

class Solution
{
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>> &prerequisites, vector<vector<int>> &queries)
    {
        // 邻接矩阵
        vector<vector<int>> graph(numCourses, vector<int>());
        // 入度数组
        vector<int> inDegree(numCourses, 0);
        vector<vector<bool>> isPre(numCourses, vector<bool>(numCourses, false));

        // 初始化邻接矩阵和入度数组
        for (vector<int> &p : prerequisites)
        {
            int from = p[0], to = p[1];
            graph[from].push_back(to);
            inDegree[to]++;
        }

        queue<int> q;
        // 把入度为 0 的节点（即没有前置课程要求）放在队列中
        for (int i = 0; i < inDegree.size(); i++)
            if (inDegree[i] == 0)
                q.push(i);

        while (!q.empty())
        {
            // 每次从队列中获得节点，我们将该节点放在排序的末尾，
            // 并且把它指向的课程的入度各减 1
            int u = q.front();
            q.pop();

            for (auto &v : graph[u])
            {
                // 存在一条 u->v 边
                isPre[u][v] = true;
                // 更新所有 i->u->v 的路径
                for (int i = 0; i < numCourses; i++)
                    isPre[i][v] = isPre[i][v] | isPre[i][u];

                inDegree[v]--;
                // 有课程的所有前置必修课都已修完（即入度为 0），
                // 我们把这个节点加入队列中
                if (inDegree[v] == 0)
                    q.push(v);
            }
        }

        vector<bool> ans;
        for (auto &query : queries)
        {
            int from = query[0], to = query[1];
            ans.push_back(isPre[from][to]);
        }

        return ans;
    }
};
// @lc code=end

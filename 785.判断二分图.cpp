/*
 * @lc app=leetcode.cn id=785 lang=cpp
 *
 * [785] 判断二分图
 */

// @lc code=start

// 广度优先搜索

class Solution
{
public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        if (graph.empty())
            return true;
        int n = graph.size();
        // 节点颜色数组
        vector<int> color(n, 0);
        // 0 表示未检查的节点，用 1 和 2 表示两种不同的颜色
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (color[i] == 0)
            {
                q.push(i);
                color[i] = 1;
            }
            while (!q.empty())
            {
                int index = q.front();
                q.pop();
                for (int &j : graph[index])
                {
                    if (color[j] == 0)
                    {
                        q.push(j);
                        color[j] = color[index] == 1 ? 2 : 1;
                    }
                    else if (color[index] == color[j])
                        return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end

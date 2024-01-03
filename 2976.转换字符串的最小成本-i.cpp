/*
 * @lc app=leetcode.cn id=2976 lang=cpp
 *
 * [2976] 转换字符串的最小成本 I
 */

// @lc code=start
class Solution
{
public:
    long long minimumCost(string source, string target, vector<char> &original, vector<char> &changed, vector<int> &cost)
    {
        // 邻接矩阵
        vector<vector<long long>> edge(26, vector<long long>(26, INT_MAX / 2));
        // 初始化
        for (int i = 0; i < 26; i++)
            edge[i][i] = 0;
        // 建图
        for (int i = 0; i < original.size(); i++)
        {
            int x = original[i] - 'a', y = changed[i] - 'a';
            edge[x][y] = min(edge[x][y], (long long)cost[i]);
        }
        // Floyd 算法求最短路
        for (int k = 0; k < 26; k++)
            for (int i = 0; i < 26; i++)
            {
                if (edge[i][k] == INT_MAX / 2) // 加上这句话，巨大优化！
                    continue;
                for (int j = 0; j < 26; j++)
                    edge[i][j] = min(edge[i][j], edge[i][k] + edge[k][j]);
            }
        // 计算最小成本
        long long minCost = 0;
        for (int i = 0; i < source.size(); i++)
        {
            int x = source[i] - 'a', y = target[i] - 'a';
            if (x != y)
            {
                // x 不能变成 y，无解
                if (edge[x][y] >= INT_MAX / 2)
                    return -1;
                // 否则答案增加把 x 改成 y 的最小代价
                minCost += edge[x][y];
            }
        }
        return minCost;
    }
};
// @lc code=end

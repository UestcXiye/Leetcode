/*
 * @lc app=leetcode.cn id=2850 lang=cpp
 *
 * [2850] 将石头分散到网格图的最少移动次数
 */

// @lc code=start
class Solution
{
public:
    int minimumMoves(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = m ? grid[0].size() : 0; // m = n = 3
        // 所有移走的石子个数 = 所有移入的石子个数（grid[i][j] = 0）
        vector<pair<int, int>> from; // 移走石子坐标数组
        vector<pair<int, int>> to;   // 移入石子坐标数组
        // 构建 from 和 to 数组
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
            {
                if (grid[i][j] > 1)
                {
                    // 有 grid[i][j] - 1 个可以移走的石子
                    for (int k = 0; k < grid[i][j] - 1; k++)
                        from.push_back(make_pair(i, j));
                }
                else if (grid[i][j] == 0)
                    to.push_back(make_pair(i, j));
            }
        // 枚举 from 的全部排列可能，与 to 匹配，求 from[i] 和 to[i] 的曼哈顿距离之和，最小值即为答案
        int minCount = __INT_MAX__; // 最少移动次数
        // 使用 next_permutation 枚举全排列必须先对数组进行排序
        sort(from.begin(), from.end());
        do
        {
            int count = 0;
            for (int i = 0; i < from.size(); i++)
            {
                // 计算曼哈顿距离
                count += abs(from[i].first - to[i].first) + abs(from[i].second - to[i].second);
            }
            minCount = min(minCount, count); // 更新答案
        } while (next_permutation(from.begin(), from.end()));
        return minCount;
    }
};
// @lc code=end

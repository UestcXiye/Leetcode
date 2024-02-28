/*
 * @lc app=leetcode.cn id=2673 lang=cpp
 *
 * [2673] 使二叉树所有路径值相等的最小代价
 */

// @lc code=start
// class Solution
// {
// public:
//     int minIncrements(int n, vector<int> &cost)
//     {
//         int min_increase = 0;
//         // 从最后一个非叶节点开始算
//         for (int i = n / 2; i > 0; i--)
//         {
//             int leftSonVal = cost[2 * i - 1];
//             int rightSonVal = cost[2 * i];
//             // 两个子节点变成一样的，值为较大者
//             min_increase += abs(leftSonVal - rightSonVal);
//             // 累加路径和
//             cost[i - 1] += max(leftSonVal, rightSonVal);
//         }
//         return min_increase;
//     }
// };

// 递归

class Solution
{
public:
    int minIncrements(int n, vector<int> &cost)
    {
        int min_increase = 0;

        function<int(int)> dfs = [&](int index) -> int
        {
            if (2 * index > n)
                return cost[index - 1];
            int leftSonVal = dfs(2 * index);
            int rightSonVal = dfs(2 * index + 1);
            min_increase += abs(leftSonVal - rightSonVal);
            return max(leftSonVal, rightSonVal) + cost[index - 1];
        };

        dfs(1);
        return min_increase;
    }
};
// @lc code=end

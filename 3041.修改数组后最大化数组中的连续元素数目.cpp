/*
 * @lc app=leetcode.cn id=3041 lang=cpp
 *
 * [3041] 修改数组后最大化数组中的连续元素数目
 */

// @lc code=start

// 子序列 DP

class Solution
{
public:
    int maxSelectedElements(vector<int> &nums)
    {
        if (nums.empty())
            return 0;

        // dp[i]: 以 i 结尾的连续递增序列的最大长度
        vector<int> dp(1e6 + 1, 0);

        sort(nums.begin(), nums.end());
        // 状态转移
        for (int &x : nums)
        {
            dp[x + 1] = dp[x] + 1;
            dp[x] = dp[x - 1] + 1;
        }

        return *max_element(dp.begin(), dp.end());
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=2028 lang=cpp
 *
 * [2028] 找出缺失的观测数据
 */

// @lc code=start
class Solution
{
public:
    vector<int> missingRolls(vector<int> &rolls, int mean, int n)
    {
        int m = rolls.size();
        int curSum = accumulate(rolls.begin(), rolls.end(), 0);
        int total = (m + n) * mean;

        if (total - curSum > 6 * n || total - curSum < 1 * n)
            return {};

        vector<int> ans(n, (total - curSum) / n);
        for (int i = 0; i < (total - curSum) % n; i++)
            ans[i]++;

        return ans;
    }
};
// @lc code=end

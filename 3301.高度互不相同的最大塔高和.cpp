/*
 * @lc app=leetcode.cn id=3301 lang=cpp
 *
 * [3301] 高度互不相同的最大塔高和
 */

// @lc code=start
class Solution
{
public:
    long long maximumTotalSum(vector<int> &maximumHeight)
    {
        sort(maximumHeight.begin(), maximumHeight.end(), greater<>());
        int mx = maximumHeight[0];
        for (int i = 1; i < maximumHeight.size(); i++)
        {
            if (maximumHeight[i] >= mx)
                maximumHeight[i] = mx - 1;
            mx = maximumHeight[i];
            if (mx <= 0)
                return -1;
        }
        return accumulate(maximumHeight.begin(), maximumHeight.end(), 0LL);
    }
};
// @lc code=end

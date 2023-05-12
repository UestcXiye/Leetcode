/*
 * @lc app=leetcode.cn id=2335 lang=cpp
 *
 * [2335] 装满杯子需要的最短总时长
 */

// @lc code=start
class Solution
{
public:
    int fillCups(vector<int> &amount)
    {
        sort(amount.begin(), amount.end());
        int ans = 0;
        while (amount[0] > 0 && amount[1] > 0 && amount[2] > 0)
        {
            if (amount[1] > 0 && amount[2] > 0)
            {
                amount[1]--;
                amount[2]--;
                ans++;
            }
            sort(amount.begin(), amount.end());
        }
        ans += amount[2];
        return ans;
    }
};
// @lc code=end

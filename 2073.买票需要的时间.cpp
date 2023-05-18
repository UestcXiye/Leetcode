/*
 * @lc app=leetcode.cn id=2073 lang=cpp
 *
 * [2073] 买票需要的时间
 */

// @lc code=start
class Solution
{
public:
    int timeRequiredToBuy(vector<int> &tickets, int k)
    {
        int n = tickets.size();
        int ans = 0;
        int index = 0;
        while (tickets[k] > 0)
        {
            if (tickets[index] > 0)
            {
                tickets[index]--;
                ans++;
            }
            index = (index + 1) % n;
        }
        return ans;
    }
};
// @lc code=end

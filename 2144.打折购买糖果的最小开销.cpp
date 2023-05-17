/*
 * @lc app=leetcode.cn id=2144 lang=cpp
 *
 * [2144] 打折购买糖果的最小开销
 */

// @lc code=start
class Solution
{
public:
    int minimumCost(vector<int> &cost)
    {
        int n = cost.size();
        sort(cost.begin(), cost.end(), greater<int>());
        int sum = 0, count = 0;
        for (int i = 0; i < n; i++)
        {
            sum += cost[i];
            count++;
            if (count == 3)
            {
                count = 0;
                sum -= cost[i];
            }
        }
        return sum;
    }
};
// @lc code=end

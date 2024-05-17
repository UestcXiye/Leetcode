/*
 * @lc app=leetcode.cn id=3147 lang=cpp
 *
 * [3147] 从魔法师身上吸取的最大能量
 */

// @lc code=start
class Solution
{
public:
    int maximumEnergy(vector<int> &energy, int k)
    {
        int n = energy.size();
        int ans = INT_MIN;
        for (int i = n - k; i < n; i++)
        {
            int sum = 0;
            for (int j = i; j >= 0; j -= k)
            {
                sum += energy[j];
                ans = max(ans, sum);
            }
        }
        return ans;
    }
};
// @lc code=end

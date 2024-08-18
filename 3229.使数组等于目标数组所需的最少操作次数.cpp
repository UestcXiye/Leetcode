/*
 * @lc app=leetcode.cn id=3229 lang=cpp
 *
 * [3229] 使数组等于目标数组所需的最少操作次数
 */

// @lc code=start
class Solution
{
public:
    long long minimumOperations(vector<int> &nums, vector<int> &target)
    {
        long long s = target[0] - nums[0];
        long long ans = abs(s);
        for (int i = 1; i < nums.size(); i++)
        {
            int k = (target[i] - target[i - 1]) - (nums[i] - nums[i - 1]);
            if (k > 0)
                ans += s >= 0 ? k : max(k + s, 0LL);
            else
                ans -= s <= 0 ? k : min(k + s, 0LL);
            s += k;
        }
        return ans;
    }
};
// @lc code=end

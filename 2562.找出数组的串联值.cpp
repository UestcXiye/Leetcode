/*
 * @lc app=leetcode.cn id=2562 lang=cpp
 *
 * [2562] 找出数组的串联值
 */

// @lc code=start
class Solution
{
public:
    long long findTheArrayConcVal(vector<int> &nums)
    {
        long long ans = 0;
        for (int i = 0, j = nums.size() - 1; i <= j; i++, j--)
        {
            if (i < j)
                ans += stol(to_string(nums[i]) + to_string(nums[j]));
            else
                ans += nums[i];
        }
        return ans;
    }
};
// @lc code=end

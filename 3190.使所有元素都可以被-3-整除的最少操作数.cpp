/*
 * @lc app=leetcode.cn id=3190 lang=cpp
 *
 * [3190] 使所有元素都可以被 3 整除的最少操作数
 */

// @lc code=start
class Solution
{
public:
    int minimumOperations(vector<int> &nums)
    {
        int ans = 0;
        for (int &num : nums)
            ans += min(num % 3, 3 - num % 3);
        return ans;
    }
};
// @lc code=end

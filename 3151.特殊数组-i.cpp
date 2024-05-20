/*
 * @lc app=leetcode.cn id=3151 lang=cpp
 *
 * [3151] 特殊数组 I
 */

// @lc code=start
class Solution
{
public:
    bool isArraySpecial(vector<int> &nums)
    {
        if (nums.size() == 1)
            return true;
        int n = nums.size();
        for (int i = 0; i < n - 1; i++)
            if (!different(nums[i], nums[i + 1]))
                return false;
        return true;
    }
    bool different(int a, int b) { return abs(a - b) % 2; }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=2980 lang=cpp
 *
 * [2980] 检查按位或是否存在尾随零
 */

// @lc code=start
class Solution
{
public:
    bool hasTrailingZeros(vector<int> &nums)
    {
        int count = 0;
        for (int &num : nums)
            if (num % 2 == 0)
                count++;
        return count >= 2;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=3201 lang=cpp
 *
 * [3201] 找出有效子序列的最大长度 I
 */

// @lc code=start
class Solution
{
public:
    int maximumLength(vector<int> &nums)
    {
        // 分三种情况：全奇、全偶、奇偶交替
        int odd = 0, even = 0;
        for (int &num : nums)
        {
            if (num % 2)
                odd++;
            else
                even++;
        }
        int interlaced = 1, tag = nums[0];
        for (int i = 1; i < nums.size(); i++)
            if ((nums[i] & 1) ^ (tag & 1))
            {
                interlaced++;
                tag = nums[i];
            }
        return max(interlaced, max(odd, even));
    }
};
// @lc code=end

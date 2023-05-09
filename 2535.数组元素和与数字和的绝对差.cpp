/*
 * @lc app=leetcode.cn id=2535 lang=cpp
 *
 * [2535] 数组元素和与数字和的绝对差
 */

// @lc code=start
class Solution
{
public:
    int differenceOfSum(vector<int> &nums)
    {
        int elemSum = 0;
        int digitSum = 0;
        for (int num : nums)
        {
            elemSum += num;
            while (num)
            {
                digitSum += num % 10;
                num /= 10;
            }
        }
        return abs(elemSum - digitSum);
    }
};
// @lc code=end

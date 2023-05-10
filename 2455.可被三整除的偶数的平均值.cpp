/*
 * @lc app=leetcode.cn id=2455 lang=cpp
 *
 * [2455] 可被三整除的偶数的平均值
 */

// @lc code=start
class Solution
{
public:
    int averageValue(vector<int> &nums)
    {
        int sum = 0;
        int count = 0;
        for (int num : nums)
        {
            if (num % 2 == 0 && num % 3 == 0)
            {
                sum += num;
                count++;
            }
        }
        if (count == 0)
            return 0;
        return sum / count;
    }
};
// @lc code=end

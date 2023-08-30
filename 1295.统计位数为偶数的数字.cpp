/*
 * @lc app=leetcode.cn id=1295 lang=cpp
 *
 * [1295] 统计位数为偶数的数字
 */

// @lc code=start
class Solution
{
public:
    int findNumbers(vector<int> &nums)
    {
        int count = 0;
        for (int &num : nums)
        {
            int wei = 0;
            while (num)
            {
                num /= 10;
                wei++;
            }
            if (wei % 2 == 0)
                count++;
        }
        return count;
    }
};
// @lc code=end

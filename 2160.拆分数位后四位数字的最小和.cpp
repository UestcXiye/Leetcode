/*
 * @lc app=leetcode.cn id=2160 lang=cpp
 *
 * [2160] 拆分数位后四位数字的最小和
 */

// @lc code=start
class Solution
{
public:
    int minimumSum(int num)
    {
        vector<int> bits;
        while (num)
        {
            bits.push_back(num % 10);
            num /= 10;
        }
        sort(bits.begin(), bits.end());
        int new1 = 10 * bits[0] + bits[2];
        int new2 = 10 * bits[1] + bits[3];
        return new1 + new2;
    }
};
// @lc code=end

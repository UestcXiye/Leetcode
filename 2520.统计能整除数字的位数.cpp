/*
 * @lc app=leetcode.cn id=2520 lang=cpp
 *
 * [2520] 统计能整除数字的位数
 */

// @lc code=start
class Solution
{
public:
    int countDigits(int num)
    {
        vector<int> digits;
        int n = num;
        int ans = 0;
        while (n)
        {
            digits.push_back(n % 10);
            n /= 10;
        }
        for (int digit : digits)
        {
            if (num % digit == 0)
                ans++;
        }
        return ans;
    }
};
// @lc code=end

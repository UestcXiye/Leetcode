/*
 * @lc app=leetcode.cn id=1281 lang=cpp
 *
 * [1281] 整数的各位积和之差
 */

// @lc code=start
class Solution
{
public:
    int subtractProductAndSum(int n)
    {
        vector<int> digits;
        while (n)
        {
            digits.push_back(n % 10);
            n /= 10;
        }
        int sum = 1;
        for (int &digit : digits)
            sum *= digit;
        return sum - accumulate(digits.begin(), digits.end(), 0);
    }
};
// @lc code=end

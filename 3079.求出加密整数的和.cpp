/*
 * @lc app=leetcode.cn id=3079 lang=cpp
 *
 * [3079] 求出加密整数的和
 */

// @lc code=start
class Solution
{
public:
    int sumOfEncryptedInt(vector<int> &nums)
    {
        int sum = 0;
        for (int &num : nums)
            sum += encrypt(num);
        return sum;
    }
    // 加密函数
    int encrypt(int x)
    {
        string s = to_string(x);
        int maxDigit = 0;
        for (char &c : s)
            maxDigit = max(maxDigit, c - '0');
        int res = 0;
        for (int i = 0; i < s.length(); i++)
        {
            res *= 10;
            res += maxDigit;
        }
        return res;
    }
};
// @lc code=end

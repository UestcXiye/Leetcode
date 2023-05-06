/*
 * @lc app=leetcode.cn id=405 lang=cpp
 *
 * [405] 数字转换为十六进制数
 */

// @lc code=start
class Solution
{
public:
    string toHex(int num)
    {
        if (num == 0)
            return "0";
        vector<char> alpha;
        for (int i = 0; i < 16; i++)
        {
            if (i < 10)
                alpha.push_back('0' + i);
            else
                alpha.push_back('a' + i - 10);
        }
        string ans = "";
        long n = num;
        if (n < 0)
            n += pow(2, 32);
        while (n)
        {
            ans += alpha[n % 16];
            n /= 16;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end

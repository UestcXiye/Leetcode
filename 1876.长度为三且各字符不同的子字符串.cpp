/*
 * @lc app=leetcode.cn id=1876 lang=cpp
 *
 * [1876] 长度为三且各字符不同的子字符串
 */

// @lc code=start
class Solution
{
public:
    int countGoodSubstrings(string s)
    {
        int n = s.size();
        int ans = 0;
        for (int i = 0; i <= n - 3; i++)
        {
            string temp = s.substr(i, 3);
            if (temp[0] != temp[1] && temp[1] != temp[2] && temp[0] != temp[2])
                ans++;
        }
        return ans;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=3084 lang=cpp
 *
 * [3084] 统计以给定字符开头和结尾的子字符串总数
 */

// @lc code=start
class Solution
{
public:
    long long countSubstrings(string s, char c)
    {
        long long count = 0;
        for (char &ch : s)
            if (ch == c)
                count++;
        // long long ans = 0;
        // for (int i = 1; i <= count; i++)
        //     ans += i;
        // return ans;
        return count * (count + 1) / 2;
    }
};
// @lc code=end

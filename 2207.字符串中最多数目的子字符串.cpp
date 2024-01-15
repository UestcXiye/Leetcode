/*
 * @lc app=leetcode.cn id=2207 lang=cpp
 *
 * [2207] 字符串中最多数目的子字符串
 */

// @lc code=start
class Solution
{
public:
    long long maximumSubsequenceCount(string text, string pattern)
    {
        char x = pattern[0], y = pattern[1];
        if (x == y)
        {
            long long cnt = count(text.begin(), text.end(), x);
            return cnt * (cnt + 1) / 2;
        }

        long long ans = 0;
        int cnt_x = 0, cnt_y = 0;
        for (char &c : text)
        {
            if (c == x)
                cnt_x++;
            else if (c == y)
            {
                cnt_y++;
                // 每遇到一个 y，就累加左边 x 的个数
                ans += cnt_x;
            }
        }
        return ans + max(cnt_x, cnt_y);
    }
};
// @lc code=end

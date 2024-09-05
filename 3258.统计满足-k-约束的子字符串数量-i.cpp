/*
 * @lc app=leetcode.cn id=3258 lang=cpp
 *
 * [3258] 统计满足 K 约束的子字符串数量 I
 */

// @lc code=start
class Solution
{
public:
    int countKConstraintSubstrings(string s, int k)
    {
        int n = s.length();

        function<bool(string)> check = [&](string s) -> bool
        {
            int cnt0 = 0, cnt1 = 0;
            for (char &c : s)
            {
                if (c == '0')
                    cnt0++;
                else
                    cnt1++;
                if (cnt0 > k && cnt1 > k)
                    return false;
            }
            return true;
        };

        int cnt = 0;
        for (int i = 0; i < n; i++)
            for (int j = i; j < n; j++)
            {
                string temp = s.substr(i, j - i + 1);
                if (check(temp))
                    cnt++;
            }
        return cnt;
    }
};
// @lc code=end

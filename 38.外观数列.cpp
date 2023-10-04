/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 外观数列
 */

// @lc code=start

// 模拟

class Solution
{
public:
    string countAndSay(int n)
    {
        string prev = "1";
        for (int i = 2; i <= n; i++)
        {
            string cur = "";
            int start = 0, pos = 0;
            while (pos < prev.size())
            {
                int count = 0;
                while (pos < prev.size() && prev[pos] == prev[start])
                {
                    pos++;
                    count++;
                }
                cur += to_string(count) + prev[start];
                count = 0;
                start = pos;
            }
            prev = cur;
        }
        return prev;
    }
};
// @lc code=end

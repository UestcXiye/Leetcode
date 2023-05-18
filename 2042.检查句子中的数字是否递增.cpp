/*
 * @lc app=leetcode.cn id=2042 lang=cpp
 *
 * [2042] 检查句子中的数字是否递增
 */

// @lc code=start
class Solution
{
public:
    bool areNumbersAscending(string s)
    {
        int pre = 0;
        istringstream is(s);
        string t;
        while (is >> t)
        {
            if (isdigit(t[0]))
            {
                int cur = stoi(t);
                if (pre >= cur)
                    return false;
                pre = cur;
            }
        }
        return true;
    }
};
// @lc code=end

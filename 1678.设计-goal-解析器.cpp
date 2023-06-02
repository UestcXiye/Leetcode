/*
 * @lc app=leetcode.cn id=1678 lang=cpp
 *
 * [1678] 设计 Goal 解析器
 */

// @lc code=start
class Solution
{
public:
    string interpret(string command)
    {
        // command 由 "G"、"()" 和/或 "(al)" 按某种顺序组成
        string ans;
        int n = command.size(), pt = 0;
        while (pt < n)
        {
            if (command[pt] == 'G')
            {
                ans += 'G';
                pt += 1;
            }
            else if (command[pt] == '(')
            {
                if (command[pt + 1] == ')')
                {
                    ans += 'o';
                    pt += 2;
                }
                else
                {
                    ans += "al";
                    pt += 4;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

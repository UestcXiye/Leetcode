/*
 * @lc app=leetcode.cn id=657 lang=cpp
 *
 * [657] 机器人能否返回原点
 */

// @lc code=start
class Solution
{
public:
    bool judgeCircle(string moves)
    {
        int upright = 0, level = 0;
        for (char &c : moves)
        {
            switch (c)
            {
            case 'U':
                upright++;
                break;
            case 'D':
                upright--;
                break;
            case 'R':
                level++;
                break;
            case 'L':
                level--;
                break;
            }
        }
        return upright == 0 && level == 0;
    }
};
// @lc code=end

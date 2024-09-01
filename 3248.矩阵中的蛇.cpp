/*
 * @lc app=leetcode.cn id=3248 lang=cpp
 *
 * [3248] 矩阵中的蛇
 */

// @lc code=start
class Solution
{
public:
    int finalPositionOfSnake(int n, vector<string> &commands)
    {
        int i = 0, j = 0;
        for (string &cmd : commands)
        {
            switch (cmd[0])
            {
            case 'U':
                i--;
                break;
            case 'R':
                j++;
                break;
            case 'D':
                i++;
                break;
            case 'L':
                j--;
                break;
            default:
                break;
            }
        }
        return (i * n) + j;
    }
};
// @lc code=end

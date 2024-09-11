/*
 * @lc app=leetcode.cn id=3274 lang=cpp
 *
 * [3274] 检查棋盘方格颜色是否相同
 */

// @lc code=start
class Solution
{
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2)
    {
        return (coordinate1[0] + coordinate1[1]) % 2 == (coordinate2[0] + coordinate2[1]) % 2;
    }
};
// @lc code=end

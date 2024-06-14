/*
 * @lc app=leetcode.cn id=419 lang=cpp
 *
 * [419] 甲板上的战舰
 */

// @lc code=start
class Solution
{
public:
    int countBattleships(vector<vector<char>> &board)
    {
        int m = board.size(), n = m ? board[0].size() : 0;
        int count = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 'X')
                {
                    if ((j == 0 || board[i][j - 1] != 'X') && (i == 0 || board[i - 1][j] != 'X'))
                        count++;
                }
            }
        return count;
    }
};
// @lc code=end

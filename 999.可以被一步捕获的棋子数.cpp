/*
 * @lc app=leetcode.cn id=999 lang=cpp
 *
 * [999] 可以被一步捕获的棋子数
 */

// @lc code=start
class Solution
{
private:
    static const int ROW = 8;
    static const int COL = 8;

public:
    int numRookCaptures(vector<vector<char>> &board)
    {
        int x = 0, y = 0;
        for (int i = 0; i < ROW; i++)
            for (int j = 0; j < COL; j++)
                if (board[i][j] == 'R')
                    x = i, y = j;
        int catch_pawn = 0;
        // 向上
        for (int i = x - 1; i >= 0; i--)
        {
            if (board[i][y] == 'p')
            {
                catch_pawn++;
                break;
            }
            else if (board[i][y] == 'B')
                break;
        }
        // 向下
        for (int i = x + 1; i < ROW; i++)
        {
            if (board[i][y] == 'p')
            {
                catch_pawn++;
                break;
            }
            else if (board[i][y] == 'B')
                break;
        }
        // 向左
        for (int j = y - 1; j >= 0; j--)
        {
            if (board[x][j] == 'p')
            {
                catch_pawn++;
                break;
            }
            else if (board[x][j] == 'B')
                break;
        }
        // 向右
        for (int j = y + 1; j < COL; j++)
        {
            if (board[x][j] == 'p')
            {
                catch_pawn++;
                break;
            }
            else if (board[x][j] == 'B')
                break;
        }
        return catch_pawn;
    }
};
// @lc code=end

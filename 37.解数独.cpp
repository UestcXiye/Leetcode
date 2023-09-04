/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */

// @lc code=start
class Solution
{
private:
    bool line[9][9];
    bool column[9][9];
    bool block[3][3][9];
    bool valid;
    vector<pair<int, int>> spaces;

public:
    // 主函数
    void solveSudoku(vector<vector<char>> &board)
    {
        // vector<vector<bool>> line(9, vector<bool>(9, false));
        // vector<vector<bool>> column(9, vector<bool>(9, false));
        // vector<vector<vector<bool>>> block(3, vector<bool>(3,vector<bool>(9,false)));
        memset(line, false, sizeof(line));
        memset(column, false, sizeof(column));
        memset(block, false, sizeof(block));
        valid = false;
        // 初始化
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                if (board[i][j] == '.')
                {
                    spaces.push_back(pair<int, int>{i, j});
                }
                else
                {
                    int digit = board[i][j] - '0' - 1;
                    line[i][digit] = column[j][digit] = block[i / 3][j / 3][digit] = true;
                }
            }
        }
        dfs(board, 0);
    }
    // 辅函数
    void dfs(vector<vector<char>> &board, int pos)
    {
        if (pos == spaces.size())
        {
            valid = true;
            return;
        }
        auto [i, j] = spaces[pos];
        for (int digit = 0; digit < 9 && valid == false; digit++)
        {
            if (!line[i][digit] && !column[j][digit] && !block[i / 3][j / 3][digit])
            {
                // 修改当前节点状态
                line[i][digit] = column[j][digit] = block[i / 3][j / 3][digit] = true;
                board[i][j] = digit + '0' + 1;
                // 递归子节点
                dfs(board, pos + 1);
                // 回改当前节点状态
                line[i][digit] = column[j][digit] = block[i / 3][j / 3][digit] = false;
            }
        }
    }
};
// @lc code=end

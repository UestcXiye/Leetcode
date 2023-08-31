/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
class Solution
{
public:
    vector<vector<string>> ans;
    // 主函数
    vector<vector<string>> solveNQueens(int n)
    {
        if (n == 0)
            return ans;
        // 初始化棋局
        vector<string> board(n, string(n, '.'));
        // 每行每行放置皇后
        backtrack(0, board, n);
        return ans;
    }
    // 判断函数
    bool check(vector<string> &board, int row, int col, int n)
    {
        // 因为我们是每行每行的放置，因此当前行数一下都没有放置皇后所以扫描当前行数以上的就行了
        for (int i = 0; i < row; i++)
        {
            if (board[i][col] == 'Q')
                return false;
        }
        // 同理扫描当前位置斜上方有没有放置皇后就行了(左上，右上)
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        {
            if (board[i][j] == 'Q')
                return false;
        }
        for (int i = row, j = col; i >= 0 && j <= n; i--, j++)
        {
            if (board[i][j] == 'Q')
                return false;
        }
        return true;
    }
    // 回溯函数
    void backtrack(int row, vector<string> &board, int n)
    {
        if (row == n)
        {
            ans.push_back(board);
            return;
        }
        for (int col = 0; col < n; col++)
        {
            // 发现皇后有冲突，跳过后续摆法
            if (check(board, row, col, n) == false)
                continue;
            board[row][col] = 'Q';        // 修改当前节点状态
            backtrack(row + 1, board, n); // 递归子节点
            board[row][col] = '.';        // 回改当前节点状态
        }
    }
};
// @lc code=end

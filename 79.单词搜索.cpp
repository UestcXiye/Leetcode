/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
class Solution
{
public:
    // 主函数
    bool exist(vector<vector<char>> &board, string word)
    {
        if (board.empty())
            return false;
        int m = board.size(), n = m ? board[0].size() : 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        bool find = false;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                backtrack(i, j, board, word, find, visited, 0);
        return find;
    }
    // 辅函数（注意传引用，否则TLE）
    void backtrack(int i, int j, vector<vector<char>> &board, string &word, bool &find, vector<vector<bool>> &visited, int pos)
    {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
            return;
        if (visited[i][j] || find || board[i][j] != word[pos])
            return;
        if (pos == word.size() - 1)
        {
            find = true;
            return;
        }
        visited[i][j] = true; // 修改当前节点状态
        // 递归子节点
        backtrack(i + 1, j, board, word, find, visited, pos + 1);
        backtrack(i - 1, j, board, word, find, visited, pos + 1);
        backtrack(i, j + 1, board, word, find, visited, pos + 1);
        backtrack(i, j - 1, board, word, find, visited, pos + 1);
        visited[i][j] = false; // 回改当前节点状态
    }
};
// @lc code=end

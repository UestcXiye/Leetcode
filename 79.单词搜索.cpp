/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
class Solution
{
private:
    const int dx[4] = {0, 0, 1, -1};
    const int dy[4] = {1, -1, 0, 0};

public:
    // 主函数
    bool exist(vector<vector<char>> &board, string word)
    {
        if (board.empty())
            return false;
        int m = board.size(), n = m ? board[0].size() : 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        function<bool(int, int, int)> backtrack = [&](int i, int j, int level) -> bool
        {
            if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
                return false;
            if (visited[i][j] || board[i][j] != word[level])
                return false;
            if (level == word.size() - 1)
                return true;
            bool flag = false;
            visited[i][j] = true; // 修改当前节点状态
            // 递归子节点
            for (int k = 0; k < 4; k++)
                if (backtrack(i + dx[k], j + dy[k], level + 1))
                {
                    flag = true;
                    break;
                }
            visited[i][j] = false; // 回改当前节点状态
            return flag;
        };

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (backtrack(i, j, 0))
                    return true;
        return false;
    }
};
// @lc code=end

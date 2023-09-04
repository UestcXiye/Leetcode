/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

// @lc code=start

// DFS
//  class Solution
//  {
//  public:
//      // 主函数
//      void solve(vector<vector<char>> &board)
//      {
//          if (board.empty())
//              return;
//          int m = board.size(), n = m ? board[0].size() : 0;
//          for (int i = 0; i < m; i++)
//          {
//              dfs(board, i, 0);
//              dfs(board, i, n - 1);
//          }
//          for (int j = 0; j < n; j++)
//          {
//              dfs(board, 0, j);
//              dfs(board, m - 1, j);
//          }
//          for (int i = 0; i < m; i++)
//              for (int j = 0; j < n; j++)
//              {
//                  if (board[i][j] == 'A')
//                      board[i][j] = 'O';
//                  else if (board[i][j] == 'O')
//                      board[i][j] = 'X';
//              }
//      }
//      // 辅函数
//      void dfs(vector<vector<char>> &board, int x, int y)
//      {
//          int m = board.size(), n = m ? board[0].size() : 0;
//          if (x < 0 || x >= m || y < 0 || y >= n || board[x][y] != 'O')
//              return;
//          board[x][y] = 'A';
//          dfs(board, x + 1, y);
//          dfs(board, x - 1, y);
//          dfs(board, x, y + 1);
//          dfs(board, x, y - 1);
//      }
//  };

// BFS
class Solution
{
private:
    vector<int> direction{-1, 0, 1, 0, -1};

public:
    // 主函数
    void solve(vector<vector<char>> &board)
    {
        if (board.empty())
            return;
        int m = board.size(), n = m ? board[0].size() : 0;
        queue<pair<int, int>> q;
        // 从最外围开始，初始化队列
        for (int i = 0; i < m; i++)
        {
            if (board[i][0] == 'O')
            {
                q.push(pair<int, int>{i, 0});
                board[i][0] = 'A';
            }
            if (board[i][n - 1] == 'O')
            {
                q.push(pair<int, int>{i, n - 1});
                board[i][n - 1] = 'A';
            }
        }
        for (int j = 0; j < n; j++)
        {
            if (board[0][j] == 'O')
            {
                q.push(pair<int, int>{0, j});
                board[0][j] = 'A';
            }
            if (board[m - 1][j] == 'O')
            {
                q.push(pair<int, int>{m - 1, j});
                board[m - 1][j] = 'A';
            }
        }
        // BFS遍历
        while (!q.empty())
        {
            auto [r, c] = q.front();
            q.pop();
            for (int k = 0; k < 4; k++)
            {
                int x = r + direction[k], y = c + direction[k + 1];
                if (x < 0 || x >= m || y < 0 || y >= n || board[x][y] != 'O')
                    continue;
                q.push(pair<int, int>{x, y});
                board[x][y] = 'A';
            }
        }
        // 最终修改
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 'A')
                    board[i][j] = 'O';
                else if (board[i][j] == 'O')
                    board[i][j] = 'X';
            }
    }
};
// @lc code=end

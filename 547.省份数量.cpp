/*
 * @lc app=leetcode.cn id=547 lang=cpp
 *
 * [547] 省份数量
 */

// @lc code=start
class Solution
{
public:
    // 主函数
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int count = 0;
        for (int i = 0; i < n; i++)
            if (visited[i] == false)
            {
                dfs(isConnected, i, visited);
                count++;
            }
        return count;
    }
    // 辅函数
    void dfs(vector<vector<int>> &isConnected, int i, vector<bool> &visited)
    {
        visited[i] = true;
        int n = isConnected.size();
        for (int j = 0; j < n; j++)
            if (isConnected[i][j] == 1 && visited[j] == false)
                dfs(isConnected, j, visited);
    }
};
// @lc code=end

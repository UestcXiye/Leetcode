/*
 * @lc app=leetcode.cn id=997 lang=cpp
 *
 * [997] 找到小镇的法官
 */

// @lc code=start
class Solution
{
public:
    int findJudge(int n, vector<vector<int>> &trust)
    {
        vector<int> inDegrees(n + 1, 0), outDegrees(n + 1, 0);
        for (vector<int> &edge : trust)
        {
            int from = edge[0], to = edge[1];
            outDegrees[from]++;
            inDegrees[to]++;
        }
        for (int i = 1; i <= n; i++)
        {
            if (outDegrees[i] == 0 && inDegrees[i] == n - 1)
                return i;
        }
        return -1;
    }
};
// @lc code=end

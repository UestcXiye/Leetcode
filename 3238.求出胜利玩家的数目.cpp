/*
 * @lc app=leetcode.cn id=3238 lang=cpp
 *
 * [3238] 求出胜利玩家的数目
 */

// @lc code=start
class Solution
{
public:
    int winningPlayerCount(int n, vector<vector<int>> &pick)
    {
        vector<vector<int>> cnt(n, vector<int>(11, 0));
        for (auto &p : pick)
            cnt[p[0]][p[1]]++;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            bool judge = false;
            for (int j = 0; j < cnt[i].size(); j++)
                if (cnt[i][j] > i)
                    judge = true;
            if (judge)
                ans++;
        }
        return ans;
    }
};
// @lc code=end

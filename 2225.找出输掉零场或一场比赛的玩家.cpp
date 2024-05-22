/*
 * @lc app=leetcode.cn id=2225 lang=cpp
 *
 * [2225] 找出输掉零场或一场比赛的玩家
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> findWinners(vector<vector<int>> &matches)
    {
        set<int> players;                 // 保存所有玩家
        unordered_map<int, int> loserCnt; // 记录败者输掉比赛的次数
        vector<vector<int>> ans(2);

        for (vector<int> &match : matches)
        {
            int winner = match[0], loser = match[1];
            players.insert(winner);
            players.insert(loser);
            loserCnt[loser]++;
        }
        // 统计没有输掉任何比赛的玩家
        for (const auto &player : players)
            if (!loserCnt.contains(player))
                ans[0].push_back(player);
        // 统计恰好输掉一场比赛的玩家
        for (auto &[loser, cnt] : loserCnt)
            if (cnt == 1)
                ans[1].push_back(loser);

        ranges::sort(ans[0]);
        ranges::sort(ans[1]);
        return ans;
    }
};
// @lc code=end

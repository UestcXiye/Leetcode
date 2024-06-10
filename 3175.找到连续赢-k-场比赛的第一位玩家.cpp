/*
 * @lc app=leetcode.cn id=3175 lang=cpp
 *
 * [3175] 找到连续赢 K 场比赛的第一位玩家
 */

// @lc code=start
class Solution
{
public:
    int findWinningPlayer(vector<int> &skills, int k)
    {
        int n = skills.size();
        int mx_i = 0, win = 0;
        for (int i = 1; i < n && win < k; i++)
        {
            if (skills[i] > skills[mx_i])
            {
                mx_i = i;
                win = 0;
            }
            win++;
        }
        return mx_i;
    }
};
// @lc code=end

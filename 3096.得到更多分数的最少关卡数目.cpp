/*
 * @lc app=leetcode.cn id=3096 lang=cpp
 *
 * [3096] 得到更多分数的最少关卡数目
 */

// @lc code=start
class Solution
{
public:
    int minimumLevels(vector<int> &possible)
    {
        int n = possible.size();
        vector<int> preSum(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            int x = possible[i - 1] > 0 ? 1 : -1;
            preSum[i] = preSum[i - 1] + x;
        }
        // 注意，每个玩家都至少需要完成 1 个关卡。
        for (int i = 1; i < n; i++)
        {
            int score1 = preSum[i] - preSum[0];
            int score2 = preSum[n] - preSum[i];
            if (score1 > score2)
                return i;
        }
        return -1;
    }
};
// @lc code=end

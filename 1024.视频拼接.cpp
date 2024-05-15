/*
 * @lc app=leetcode.cn id=1024 lang=cpp
 *
 * [1024] 视频拼接
 */

// @lc code=start
class Solution
{
public:
    int videoStitching(vector<vector<int>> &clips, int time)
    {
        // dp[i] 表示覆盖 [0,i] 所需片段的最小数目
        vector<int> dp(time + 1, 0x3f3f3f3f);
        // 初始化
        dp[0] = 0;
        // 状态转移
        for (int i = 1; i <= time; i++)
            for (vector<int> &clip : clips)
                if (clip[0] <= i && clip[1] >= i)
                    dp[i] = min(dp[i], dp[clip[0]] + 1);
        return dp[time] >= 0x3f3f3f3f ? -1 : dp[time];
    }
};
// @lc code=end

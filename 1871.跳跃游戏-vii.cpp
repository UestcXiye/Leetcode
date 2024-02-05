/*
 * @lc app=leetcode.cn id=1871 lang=cpp
 *
 * [1871] 跳跃游戏 VII
 */

// @lc code=start
class Solution
{
public:
    bool canReach(string s, int minJump, int maxJump)
    {
        int n = s.length();
        vector<bool> dp(n);
        // 初始化
        dp[0] = true;

        // 前缀和
        vector<int> preSum(n);
        // 由于我们从 i = minJump 开始动态规划，
        // 因此需要将 [0, minJump) 这部分的前缀和预处理出来
        for (int i = 0; i < minJump; i++)
            preSum[i] = 1;

        // 状态转移
        for (int i = minJump; i < n; i++)
        {
            // [left, right] 表示位置 i 在状态转移中对应的 j 的区间
            int left = i - maxJump, right = i - minJump;
            if (s[i] == '0')
            {
                int total = preSum[right] - (left <= 0 ? 0 : preSum[left - 1]);
                // dp[i] 为 true，当且仅当 s[i] == '0'，
                // 且 dp[left,...,right] 的和不为 0
                dp[i] = (total != 0);
            }
            preSum[i] = preSum[i - 1] + (int)dp[i];
        }
        return dp[n - 1];
    }
};
// @lc code=end

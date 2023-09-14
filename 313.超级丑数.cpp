/*
 * @lc app=leetcode.cn id=313 lang=cpp
 *
 * [313] 超级丑数
 */

// @lc code=start

// 动态规划

class Solution
{
public:
    int nthSuperUglyNumber(int n, vector<int> &primes)
    {
        vector<int> dp(n + 1, 0); // 用来存储丑数序列
        dp[1] = 1;                // 第一个丑数是1
        int m = primes.size();
        vector<int> nums(m);        // 记录新丑数序列
        vector<int> pointers(m, 1); // 记录质数该与哪一位丑数做乘积
        for (int i = 2; i <= n; i++)
        {
            int minNum = INT_MAX;
            for (int j = 0; j < m; j++)
            {
                nums[j] = dp[pointers[j]] * primes[j]; // 旧丑数 * 质数序列 = 新丑数序列
                minNum = min(minNum, nums[j]);         // 寻找所有新丑数中最小的丑数
            }
            dp[i] = minNum;
            for (int j = 0; j < m; j++)
                if (minNum == nums[j]) // 如果此位置已经诞生过最小丑数
                    pointers[j]++;     // 让此位置所取旧丑数向后推一位
        }
        return dp[n];
    }
};
// @lc code=end

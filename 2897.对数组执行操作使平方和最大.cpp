/*
 * @lc app=leetcode.cn id=2897 lang=cpp
 *
 * [2897] 对数组执行操作使平方和最大
 */

// @lc code=start
class Solution
{
private:
    const int MOD = 1e9 + 7;

public:
    int maxSum(vector<int> &nums, int k)
    {
        vector<int> count(32, 0);
        for (const int num : nums)
        {
            for (int i = 0; i < 32; i++)
                count[i] += (num >> i) & 01;
        }
        long long ans = 0;
        for (int i = 0; i < k; i++)
        {
            int x = 0;
            for (int i = 0; i < 32; i++)
                if (count[i] > 0)
                {
                    x += 1 << i;
                    count[i]--;
                }
            ans = (ans + (long long)x * x) % MOD;
        }
        return ans;
    }
};
// @lc code=end

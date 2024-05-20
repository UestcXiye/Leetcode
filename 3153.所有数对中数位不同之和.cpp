/*
 * @lc app=leetcode.cn id=3153 lang=cpp
 *
 * [3153] 所有数对中数位不同之和
 */

// @lc code=start
class Solution
{
public:
    long long sumDigitDifferences(vector<int> &nums)
    {
        int n = nums.size();
        int cnt[9][10];
        memset(cnt, 0, sizeof(cnt));

        for (int num : nums)
        {
            int i = 0;
            while (num)
            {
                cnt[i][num % 10]++;
                i++;
                num /= 10;
            }
        }

        long long ans = 0LL;
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 10; j++)
                ans += cnt[i][j] * (n - cnt[i][j]);
        return ans >> 1;
    }
};
// @lc code=end

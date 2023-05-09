/*
 * @lc app=leetcode.cn id=2614 lang=cpp
 *
 * [2614] 对角线上的质数
 */

// @lc code=start
class Solution
{
public:
    bool isPrime(int n)
    {
        if (n == 1)
            return false;
        for (int i = 2; i * i <= n; i++)
            if (n % i == 0)
                return false;
        return true;
    }
    int diagonalPrime(vector<vector<int>> &nums)
    {
        int m = nums.size();
        int n = nums[0].size();
        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            if (isPrime(nums[i][i]))
                ans = max(ans, nums[i][i]);
            if (isPrime(nums[i][m - i - 1]))
                ans = max(ans, nums[i][m - i - 1]);
        }
        return ans;
    }
};
// @lc code=end

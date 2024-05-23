/*
 * @lc app=leetcode.cn id=2761 lang=cpp
 *
 * [2761] 和等于目标值的质数对
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> findPrimePairs(int n)
    {
        // 特判
        if (n <= 2)
            return {};

        vector<vector<int>> ans;
        // 从小到大枚举 x
        for (int x = 2; 2 * x <= n; x++)
        {
            int y = n - x;
            if (isPrime(x) && isPrime(y))
                ans.push_back({x, y});
        }
        return ans;
    }
    // 辅函数 - 判断一个数 x 是否是质数
    bool isPrime(int x)
    {
        if (x <= 1)
            return false;
        for (int i = 2; i * i <= x; i++)
            if (x % i == 0)
                return false;
        return true;
    }
};
// @lc code=end

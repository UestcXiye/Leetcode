/*
 * @lc app=leetcode.cn id=2961 lang=cpp
 *
 * [2961] 双模幂运算
 */

// @lc code=start

// 快速幂

class Solution
{
public:
    vector<int> getGoodIndices(vector<vector<int>> &variables, int target)
    {
        vector<int> goodIndices;
        for (int i = 0; i < variables.size(); i++)
        {
            long long a = variables[i][0];
            int b = variables[i][1];
            int c = variables[i][2];
            int m = variables[i][3];
            if ((int)myPow(myPow(a, b, 10), c, m) == target)
                goodIndices.push_back(i);
        }
        return goodIndices;
    }
    // 辅函数 - 快速幂
    long long myPow(long long x, int n, const int mod)
    {
        long long res = 1;
        while (n)
        {
            if (n % 2)
                res = res * x % mod;
            x = x * x % mod;
            n >>= 1;
        }
        return res;
    }
};
// @lc code=end

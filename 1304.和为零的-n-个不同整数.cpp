/*
 * @lc app=leetcode.cn id=1304 lang=cpp
 *
 * [1304] 和为零的 N 个不同整数
 */

// @lc code=start
class Solution
{
public:
    vector<int> sumZero(int n)
    {
        if (n == 1)
            return {0};
        vector<int> ans;
        int num = 1;
        while (num++ <= n / 2)
        {
            ans.push_back(-num);
            ans.push_back(num);
        }
        if (n % 2 == 1)
            ans.push_back(0);
        return ans;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=3075 lang=cpp
 *
 * [3075] 幸福值最大化的选择方案
 */

// @lc code=start
class Solution
{
public:
    long long maximumHappinessSum(vector<int> &happiness, int k)
    {
        int n = happiness.size();
        sort(happiness.begin(), happiness.end(), greater<int>());
        long long sum = 0;
        for (int i = 0; i < k; i++)
            sum += max(happiness[i] - i, 0);
        return sum;
    }
};
// @lc code=end

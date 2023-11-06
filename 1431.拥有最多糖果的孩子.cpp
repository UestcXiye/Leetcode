/*
 * @lc app=leetcode.cn id=1431 lang=cpp
 *
 * [1431] 拥有最多糖果的孩子
 */

// @lc code=start
class Solution
{
public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
    {
        int n = candies.size();
        int maxCandies = *max_element(candies.begin(), candies.end());
        vector<bool> ans(n, false);
        for (int i = 0; i < n; i++)
            if (candies[i] + extraCandies >= maxCandies)
                ans[i] = true;
        return ans;
    }
};
// @lc code=end

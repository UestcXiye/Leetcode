/*
 * @lc app=leetcode.cn id=1103 lang=cpp
 *
 * [1103] 分糖果 II
 */

// @lc code=start
class Solution
{
public:
    vector<int> distributeCandies(int candies, int num_people)
    {
        int n = num_people;
        vector<int> ans(n, 0);
        int candy = 1, i = 0;
        while (candies > 0)
        {
            if (candies >= candy)
            {
                ans[i] += candy;
                candies -= candy;
            }
            else
            {
                ans[i] += candies;
                candies = 0;
            }
            candy++;
            i++;
            if (i >= n)
                i = 0;
        }
        return ans;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=1051 lang=cpp
 *
 * [1051] 高度检查器
 */

// @lc code=start
class Solution
{
public:
    int heightChecker(vector<int> &heights)
    {
        vector<int> expected(heights.begin(), heights.end());
        sort(expected.begin(), expected.end());
        int ans = 0;
        for (int i = 0; i < heights.size(); i++)
            if (heights[i] != expected[i])
                ans++;
        return ans;
    }
};
// @lc code=end

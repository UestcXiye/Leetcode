/*
 * @lc app=leetcode.cn id=1929 lang=cpp
 *
 * [1929] 数组串联
 */

// @lc code=start
class Solution
{
public:
    vector<int> getConcatenation(vector<int> &nums)
    {
        vector<int> ans;
        ans.insert(ans.end(), nums.begin(), nums.end());
        ans.insert(ans.end(), nums.begin(), nums.end());
        return ans;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=2154 lang=cpp
 *
 * [2154] 将找到的值乘以 2
 */

// @lc code=start
class Solution
{
public:
    int findFinalValue(vector<int> &nums, int original)
    {
        unordered_set<int> uset(nums.begin(), nums.end());
        while (uset.count(original))
            original *= 2;
        return original;
    }
};
// @lc code=end

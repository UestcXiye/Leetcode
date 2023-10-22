/*
 * @lc app=leetcode.cn id=908 lang=cpp
 *
 * [908] 最小差值 I
 */

// @lc code=start
class Solution
{
public:
    int smallestRangeI(vector<int> &nums, int k)
    {
        return (*max_element(nums.begin(), nums.end()) - *min_element(nums.begin(), nums.end())) - 2 * k <= 0 ? 0 : (*max_element(nums.begin(), nums.end()) - *min_element(nums.begin(), nums.end())) - 2 * k;
    }
};
// @lc code=end

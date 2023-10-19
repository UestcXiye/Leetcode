/*
 * @lc app=leetcode.cn id=2903 lang=cpp
 *
 * [2903] 找出满足差值条件的下标 I
 */

// @lc code=start
class Solution
{
public:
    vector<int> findIndices(vector<int> &nums, int indexDifference, int valueDifference)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                if (abs(i - j) >= indexDifference && abs(nums[i] - nums[j]) >= valueDifference)
                    return {i, j};
            }
        return {-1, -1};
    }
};
// @lc code=end

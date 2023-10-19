/*
 * @lc app=leetcode.cn id=2905 lang=cpp
 *
 * [2905] 找出满足差值条件的下标 II
 */

// @lc code=start
class Solution
{
public:
    vector<int> findIndices(vector<int> &nums, int indexDifference, int valueDifference)
    {
        int n = nums.size();
        int max_index = 0, min_index = 0;
        for (int j = indexDifference; j < n; j++)
        {
            int i = j - indexDifference;
            if (nums[i] > nums[max_index])
                max_index = i;
            if (nums[i] < nums[min_index])
                min_index = i;
            if (abs(nums[max_index] - nums[j]) >= valueDifference)
                return {max_index, j};
            if (abs(nums[min_index] - nums[j]) >= valueDifference)
                return {min_index, j};
        }
        return {-1, -1};
    }
};
// @lc code=end

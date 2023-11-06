/*
 * @lc app=leetcode.cn id=1403 lang=cpp
 *
 * [1403] 非递增顺序的最小子序列
 */

// @lc code=start
class Solution
{
public:
    vector<int> minSubsequence(vector<int> &nums)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        sort(nums.begin(), nums.end(), greater<int>());
        int index = 0, arrSum = 0;
        vector<int> arr;
        while (arrSum <= sum - arrSum)
        {
            arr.push_back(nums[index++]);
            arrSum = accumulate(arr.begin(), arr.end(), 0);
        }
        return arr;
    }
};
// @lc code=end

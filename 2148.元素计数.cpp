/*
 * @lc app=leetcode.cn id=2148 lang=cpp
 *
 * [2148] 元素计数
 */

// @lc code=start
class Solution
{
public:
    int countElements(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int count = 0;
        int maxElem = nums[nums.size() - 1], minElem = nums[0];
        for (int num : nums)
        {
            if (num != minElem && num != maxElem)
                count++;
        }
        return count;
    }
};
// @lc code=end

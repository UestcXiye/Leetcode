/*
 * @lc app=leetcode.cn id=2164 lang=cpp
 *
 * [2164] 对奇偶下标分别排序
 */

// @lc code=start
class Solution
{
public:
    vector<int> sortEvenOdd(vector<int> &nums)
    {
        vector<int> even, odd;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i % 2 == 0)
                even.push_back(nums[i]);
            else
                odd.push_back(nums[i]);
        }
        sort(even.begin(), even.end());
        sort(odd.begin(), odd.end(), greater<int>());
        for (int i = 0; i < even.size(); i++)
            nums[2 * i] = even[i];
        for (int i = 0; i < odd.size(); i++)
            nums[2 * i + 1] = odd[i];
        return nums;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=2670 lang=cpp
 *
 * [2670] 找出不同元素数目差数组
 */

// @lc code=start
class Solution
{
public:
    vector<int> distinctDifferenceArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> diff(n);
        for (int i = 0; i < n; i++)
        {
            // set<int> prev, next;
            // for (int j = 0; j <= i; j++)
            //     prev.insert(nums[j]);
            // for (int j = i + 1; j < n; j++)
            //     next.insert(nums[j]);
            set<int> prefix(nums.begin(), nums.begin() + i + 1);
            set<int> suffix(nums.begin() + i + 1, nums.end());
            diff[i] = prefix.size() - suffix.size();
        }
        return diff;
    }
};
// @lc code=end

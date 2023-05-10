/*
 * @lc app=leetcode.cn id=2465 lang=cpp
 *
 * [2465] 不同的平均值数目
 */

// @lc code=start
class Solution
{
public:
    int distinctAverages(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<double> s;
        for (int i = 0, j = n - 1; i < j; i++, j--)
            s.insert((nums[i] + nums[j]) / 2.0);
        return s.size();
    }
};
// @lc code=end

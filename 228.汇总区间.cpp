/*
 * @lc app=leetcode.cn id=228 lang=cpp
 *
 * [228] 汇总区间
 */

// @lc code=start
class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        vector<string> ans;
        int len = nums.size();
        int begin = 0, end = 1;
        while (end < len)
        {
            while (end < len && (long long)nums[end] - nums[end - 1] == 1)
                end++;
            if (end - begin == 1)
            {

                ans.push_back({to_string(nums[begin])});
            }
            else
            {

                ans.push_back({to_string(nums[begin]) + "->" + to_string(nums[end - 1])});
            }
            begin = end++;
        }
        if (end == len)
            ans.push_back({to_string(nums[begin])});
        return ans;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=1953 lang=cpp
 *
 * [1953] 你可以工作的最大周数
 */

// @lc code=start
class Solution
{
public:
    long long numberOfWeeks(vector<int> &milestones)
    {
        long long s = accumulate(milestones.begin(), milestones.end(), 0LL);
        long long mx = *max_element(milestones.begin(), milestones.end());
        return mx > s - mx + 1 ? 2 * (s - mx) + 1 : s;
    }
};
// @lc code=end

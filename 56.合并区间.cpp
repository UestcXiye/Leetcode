/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution
{
private:
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        return a[0] < b[0];
    }

public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        // 特判
        if (intervals.empty())
            return {};
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++)
        {
            int left = intervals[i][0], right = intervals[i][1];
            if (ans.empty() || ans.back()[1] < left)
                ans.push_back({left, right});
            else
                ans.back()[1] = max(ans.back()[1], right);
        }
        return ans;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=3169 lang=cpp
 *
 * [3169] 无需开会的工作日
 */

// @lc code=start
class Solution
{

public:
    int countDays(int days, vector<vector<int>> &meetings)
    {

        vector<vector<int>> m = merge(meetings);
        int n = m.size();
        int count = m[0][0] - 1;
        for (int i = 1; i < n; i++)
        {
            if (m[i][0] > m[i - 1][1])
                count += m[i][0] - m[i - 1][1] - 1;
        }
        count += max(0, days - m[n - 1][1]);
        return count;
    }
    // 辅函数- 合并区间
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        // 特判
        if (intervals.empty())
            return {};

        int n = intervals.size();
        sort(intervals.begin(), intervals.end(),
             [&](const vector<int> &v1, const vector<int> &v2)
             {
                 return v1[0] < v2[0];
             });
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

/*
 * @lc app=leetcode.cn id=57 lang=cpp
 *
 * [57] 插入区间
 */

// @lc code=start

// 与 56.合并区间 搭配

// class Solution
// {
// private:
//     static bool cmp(vector<int> &a, vector<int> &b)
//     {
//         return a[0] < b[0];
//     }

// public:
//     vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
//     {
//         intervals.push_back(newInterval);
//         return merge(intervals);
//     }
//     // 辅函数 - 合并区间
//     vector<vector<int>> merge(vector<vector<int>> &intervals)
//     {
//         // 特判
//         if (intervals.empty())
//             return {};
//         int n = intervals.size();
//         sort(intervals.begin(), intervals.end(), cmp);
//         vector<vector<int>> ans;
//         for (int i = 0; i < n; i++)
//         {
//             int left = intervals[i][0], right = intervals[i][1];
//             if (ans.empty() || ans.back()[1] < left)
//                 ans.push_back({left, right});
//             else
//                 ans.back()[1] = max(ans.back()[1], right);
//         }
//         return ans;
//     }
// };

// 模拟

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        int left = newInterval[0], right = newInterval[1];
        bool placed = false;
        vector<vector<int>> ans;
        for (const vector<int> &interval : intervals)
        {
            if (interval[0] > right)
            {
                // 在插入区间的右侧且无交集
                if (placed == false)
                {
                    ans.push_back({left, right});
                    placed = true;
                }
                ans.push_back(interval);
            }
            else if (interval[1] < left)
            {
                // 在插入区间的左侧且无交集
                ans.push_back(interval);
            }
            else
            {
                // 与插入区间有交集，计算它们的并集
                left = min(left, interval[0]);
                right = max(right, interval[1]);
            }
        }
        if (placed == false)
            ans.push_back({left, right});
        return ans;
    }
};
// @lc code=end

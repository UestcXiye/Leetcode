/*
 * @lc app=leetcode.cn id=2895 lang=cpp
 *
 * [2895] 最小处理时间
 */

// @lc code=start

// 贪心

class Solution
{
public:
    int minProcessingTime(vector<int> &processorTime, vector<int> &tasks)
    {
        int n = processorTime.size();
        int min_time = INT_MIN;
        sort(processorTime.begin(), processorTime.end());
        sort(tasks.begin(), tasks.end(), greater<int>());
        for (int i = 0; i < n; i++)
        {
            int process_max_time = processorTime[i] + tasks[4 * i];
            min_time = max(min_time, process_max_time);
        }
        return min_time;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=630 lang=cpp
 *
 * [630] 课程表 III
 */

// @lc code=start
class Solution
{
public:
    int scheduleCourse(vector<vector<int>> &courses)
    {
        // 大根堆
        priority_queue<int> pq;
        int day = 0; // 已消耗时间

        sort(courses.begin(), courses.end(), [](const auto &a, const auto &b)
             {
                 return a[1] < b[1]; // 按照 lastDay 从小到大排序
             });

        for (vector<int> &course : courses)
        {
            int duration = course[0], lastDay = course[1];
            if (day + duration <= lastDay)
            {
                // 没有超过 lastDay，直接学习
                day += duration;
                pq.push(duration);
            }
            // 该课程的时间比之前的最长时间要短
            else if (!pq.empty() && duration < pq.top())
            {

                // 反悔，撤销之前 duration 最长的课程，改为学习该课程
                // 节省出来的时间，能在后面上完更多的课程
                day -= pq.top();
                pq.pop();
                day += duration;
                pq.push(duration);
            }
        }
        return pq.size();
    }
};
// @lc code=end

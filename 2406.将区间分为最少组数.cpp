/*
 * @lc app=leetcode.cn id=2406 lang=cpp
 *
 * [2406] 将区间分为最少组数
 */

// @lc code=start

// 优先队列

// class Solution
// {
// private:
//     static bool cmp(const vector<int> &a, const vector<int> &b)
//     {
//         return a[0] < b[0];
//     }

// public:
//     int minGroups(vector<vector<int>> &intervals)
//     {
//         // 特判
//         if (intervals.empty())
//             return 0;

//         priority_queue<int, vector<int>, greater<>> pq;
//         sort(intervals.begin(), intervals.end(), cmp);
//         for (vector<int> &interval : intervals)
//         {
//             if (!pq.empty() && pq.top() < interval[0])
//                 pq.pop();
//             pq.push(interval[1]);
//         }
//         // 最终，优先队列存储的是每个区间的右边界
//         return pq.size(); // 优先队列的大小即为划分组数
//     }
// };

// 差分数组

class Solution
{
public:
    int minGroups(vector<vector<int>> &intervals)
    {
        // 特判
        if (intervals.empty())
            return 0;

        // 构造差分数组
        map<int, int> diff;
        for (vector<int> &interval : intervals)
        {
            int from = interval[0], to = interval[1];
            diff[from]++;
            diff[to + 1]--;
        }

        int min_group = 0, sum = 0;
        for (auto &[_, d] : diff)
        {
            sum += d;
            min_group = max(min_group, sum);
        }
        return min_group;
    }
};
// @lc code=end

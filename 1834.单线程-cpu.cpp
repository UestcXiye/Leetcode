/*
 * @lc app=leetcode.cn id=1834 lang=cpp
 *
 * [1834] 单线程 CPU
 */

// @lc code=start
class Solution
{
private:
    using PII = pair<int, int>;
    using LL = long long;

public:
    vector<int> getOrder(vector<vector<int>> &tasks)
    {
        int n = tasks.size();
        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0); // 生成 0 ~ n-1
        sort(indices.begin(), indices.end(), [&](int i, int j)
             { return tasks[i][0] < tasks[j][0]; });

        vector<int> ans;
        // 优先队列
        priority_queue<PII, vector<PII>, greater<PII>> q;
        // 时间戳
        LL timestamp = 0;
        // 数组上遍历的指针
        int ptr = 0;
        for (int i = 0; i < n; i++)
        {
            // 如果没有可以执行的任务，直接快进到数组中下一个还没有分配给 CPU 的那个任务进入任务队列的时间
            if (q.empty())
            {
                timestamp = max(timestamp, (LL)tasks[indices[ptr]][0]);
            }
            // 将所有小于等于时间戳的任务放入优先队列
            while (ptr < n && tasks[indices[ptr]][0] <= timestamp)
            {
                q.emplace(tasks[indices[ptr]][1], indices[ptr]);
                ptr++;
            }
            // 选择处理时间最小的任务
            auto &&[processingTime, processIndex] = q.top();
            timestamp += processingTime;
            ans.push_back(processIndex);
            q.pop();
        }
        return ans;
    }
};
// @lc code=end

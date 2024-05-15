/*
 * @lc app=leetcode.cn id=2589 lang=cpp
 *
 * [2589] 完成所有任务的最少时间
 */

// @lc code=start
class Solution
{
public:
    int findMinimumTime(vector<vector<int>> &tasks)
    {
        sort(tasks.begin(), tasks.end(),
             [&](const vector<int> &v1, const vector<int> &v2)
             { return v1[1] < v2[1]; });
        int ans = 0;
        vector<int> run(tasks.back()[1] + 1);
        for (vector<int> &task : tasks)
        {
            int start = task[0], end = task[1], duration = task[2];
            int time = accumulate(run.begin() + start, run.begin() + end + 1, 0);
            duration -= time; // 去掉运行中的时间点
            for (int i = end; duration > 0; i--)
            { // 剩余的 d 填充区间后缀
                if (!run[i])
                {
                    run[i] = true; // 运行
                    duration--;
                    ans++;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=2432 lang=cpp
 *
 * [2432] 处理用时最长的那个任务的员工
 */

// @lc code=start
class Solution
{
public:
    static bool cmp(const vector<int> A, const vector<int> B)
    {
        if (A[1] > B[1])
            return true;
        if (A[1] == B[1] && A[0] < B[0])
            return true;
        return false;
    }
    int hardestWorker(int n, vector<vector<int>> &logs)
    {
        int len = logs.size();
        vector<vector<int>> times;
        for (int i = 0; i < len; i++)
        {
            if (i == 0)
                times.push_back(logs[i]);
            else
            {
                int id = logs[i][0];
                int time = logs[i][1] - logs[i - 1][1];
                times.push_back({id, time});
            }
        }
        // for (int i = 0; i < times.size(); i++)
        //     cout << times[i][0] << " " << times[i][1] << endl;
        sort(times.begin(), times.end(), cmp);
        // for (int i = 0; i < times.size(); i++)
        //     cout << times[i][0] << " " << times[i][1] << endl;
        return times[0][0];
    }
};
// @lc code=end

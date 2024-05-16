/*
 * @lc app=leetcode.cn id=621 lang=cpp
 *
 * [621] 任务调度器
 */

// @lc code=start
class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        vector<int> cnt(26, 0);
        for (char &task : tasks)
            cnt[task - 'A']++;

        int mx = *max_element(cnt.begin(), cnt.end());
        int s = 0, mxCnt = 0;
        for (int &c : cnt)
        {
            s += c;
            if (c == mx)
                mxCnt++;
        }

        return max(s, (n + 1) * (mx - 1) + mxCnt);
    }
};
// @lc code=end

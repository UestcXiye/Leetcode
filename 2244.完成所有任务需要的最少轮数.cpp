/*
 * @lc app=leetcode.cn id=2244 lang=cpp
 *
 * [2244] 完成所有任务需要的最少轮数
 */

// @lc code=start
class Solution
{
public:
    int minimumRounds(vector<int> &tasks)
    {
        int n = tasks.size();
        unordered_map<int, int> freq;
        for (int &task : tasks)
            freq[task]++;

        int ans = 0;
        for (auto &[t, f] : freq)
        {
            if (f < 2)
                return -1;
            else if (f < 4)
                ans++;
            else
            {
                ans += f / 3;
                if (f % 3)
                    ans++;
            }
        }
        return ans;
    }
};
// @lc code=end

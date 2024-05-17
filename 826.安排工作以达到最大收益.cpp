/*
 * @lc app=leetcode.cn id=826 lang=cpp
 *
 * [826] 安排工作以达到最大收益
 */

// @lc code=start
class Solution
{
public:
    int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker)
    {
        int n = difficulty.size();
        vector<pair<int, int>> jobs(n);
        for (int i = 0; i < n; i++)
            jobs[i] = {difficulty[i], profit[i]};
        sort(jobs.begin(), jobs.end(), 
        [&]);
        ranges::sort(worker);
        int ans = 0, j = 0, maxProfit = 0;
        for (int &w : worker)
        {
            while (j < n && jobs[j].first <= w)
            {
                maxProfit = max(maxProfit, jobs[j].second);
                j++;
            }
            ans += maxProfit;
        }
        return ans;
    }
};
// @lc code=end

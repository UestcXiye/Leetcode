/*
 * @lc app=leetcode.cn id=1560 lang=cpp
 *
 * [1560] 圆形赛道上经过次数最多的扇区
 */

// @lc code=start
class Solution
{
public:
    vector<int> mostVisited(int n, vector<int> &rounds)
    {
        vector<int> ans;
        int start = rounds[0], end = rounds[rounds.size() - 1];
        if (start <= end)
        {
            for (int i = start; i <= end; i++)
                ans.push_back(i);
        }
        else
        {
            // 由于题目要求按扇区大小排序，因此我们要将区间分成两部分
            for (int i = 1; i <= end; i++)
                ans.push_back(i);
            for (int i = start; i <= n; i++)
                ans.push_back(i);
        }
        return ans;
    }
};
// @lc code=end

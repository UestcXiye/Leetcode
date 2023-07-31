/*
 * @lc app=leetcode.cn id=6917 lang=cpp
 *
 * [6917] 满足目标工作时长的员工数目
 */

// @lc code=start
class Solution
{
public:
    int numberOfEmployeesWhoMetTarget(vector<int> &hours, int target)
    {
        int ans = 0;
        for (int &hour : hours)
            if (hour >= target)
                ans++;
        return ans;
    }
};
// @lc code=end

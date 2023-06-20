/*
 * @lc app=leetcode.cn id=1491 lang=cpp
 *
 * [1491] 去掉最低工资和最高工资后的工资平均值
 */

// @lc code=start
class Solution
{
public:
    double average(vector<int> &salary)
    {
        sort(salary.begin(), salary.end());
        return (double)accumulate(salary.begin() + 1, salary.end() - 1, 0) / (salary.size() - 2);
    }
};
// @lc code=end

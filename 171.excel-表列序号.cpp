/*
 * @lc app=leetcode.cn id=171 lang=cpp
 *
 * [171] Excel 表列序号
 */

// @lc code=start
class Solution
{
public:
    int titleToNumber(string columnTitle)
    {
        int sum = 0;
        int n = columnTitle.size();
        for (int i = 0; i < n; i++)
        {
            sum += pow(26, n - i - 1) * (columnTitle[i] - 'A' + 1);
        }
        return sum;
    }
};
// @lc code=end

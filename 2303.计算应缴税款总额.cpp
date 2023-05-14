/*
 * @lc app=leetcode.cn id=2303 lang=cpp
 *
 * [2303] 计算应缴税款总额
 */

// @lc code=start
class Solution
{
public:
    double calculateTax(vector<vector<int>> &brackets, int income)
    {
        double totalTax = 0;
        int lower = 0;
        for (auto bracket : brackets)
        {
            int upper = bracket[0], percent = bracket[1];
            double tax = (min(income, upper) - lower) * percent / 100.0;
            totalTax += tax;
            if (income <= upper)
                break;
            lower = upper;
        }
        return totalTax;
    }
};
// @lc code=end

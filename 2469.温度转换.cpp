/*
 * @lc app=leetcode.cn id=2469 lang=cpp
 *
 * [2469] 温度转换
 */

// @lc code=start
class Solution
{
public:
    vector<double> convertTemperature(double celsius)
    {
        return {celsius + 273.15, celsius * 1.80 + 32.00};
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=1619 lang=cpp
 *
 * [1619] 删除某些元素后的数组均值
 */

// @lc code=start
class Solution
{
public:
    double trimMean(vector<int> &arr)
    {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        return accumulate(arr.begin() + n / 20, arr.end() - n / 20, 0.0) / (0.9 * n);
    }
};
// @lc code=end

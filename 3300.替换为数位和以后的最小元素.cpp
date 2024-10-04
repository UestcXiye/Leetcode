/*
 * @lc app=leetcode.cn id=3300 lang=cpp
 *
 * [3300] 替换为数位和以后的最小元素
 */

// @lc code=start
class Solution
{
public:
    int minElement(vector<int> &nums)
    {
        int minElem = INT_MAX;
        for (int &num : nums)
            minElem = min(minElem, digitSum(num));
        return minElem;
    }
    // 辅函数 - 求数位之和
    int digitSum(int x)
    {
        int sum = 0;
        while (x)
        {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }
};
// @lc code=end

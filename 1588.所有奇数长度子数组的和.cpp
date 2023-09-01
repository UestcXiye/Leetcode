/*
 * @lc app=leetcode.cn id=1588 lang=cpp
 *
 * [1588] 所有奇数长度子数组的和
 */

// @lc code=start
class Solution
{
public:
    int sumOddLengthSubarrays(vector<int> &arr)
    {
        int n = arr.size();
        int sum = 0;
        for (int begin = 0; begin < n; begin++)
            for (int len = 1; begin + len <= n; len += 2)
                sum += accumulate(arr.begin() + begin, arr.begin() + begin + len, 0);
        return sum;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=1550 lang=cpp
 *
 * [1550] 存在连续三个奇数的数组
 */

// @lc code=start
class Solution
{
public:
    bool threeConsecutiveOdds(vector<int> &arr)
    {
        int n = arr.size();
        for (int i = 2; i < n; i++)
            if (arr[i - 2] % 2 && arr[i - 1] % 2 && arr[i] % 2)
                return true;
        return false;
    }
};
// @lc code=end

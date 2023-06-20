/*
 * @lc app=leetcode.cn id=1539 lang=cpp
 *
 * [1539] 第 k 个缺失的正整数
 */

// @lc code=start
class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        int current = 1;
        int n = arr.size();
        int i = 0;
        while (k > 0 && i < n)
        {
            if (arr[i] == current)
                i++;
            else
                k--;
            current++;
        }
        if (k)
            return current + k - 1;
        else
            return current - 1;
    }
};
// @lc code=end

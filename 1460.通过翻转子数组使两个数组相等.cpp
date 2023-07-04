/*
 * @lc app=leetcode.cn id=1460 lang=cpp
 *
 * [1460] 通过翻转子数组使两个数组相等
 */

// @lc code=start
class Solution
{
public:
    bool canBeEqual(vector<int> &target, vector<int> &arr)
    {
        sort(target.begin(), target.end());
        sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size(); i++)
            if (target[i] != arr[i])
                return false;
        return true;
    }
};
// @lc code=end

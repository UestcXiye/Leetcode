/*
 * @lc app=leetcode.cn id=941 lang=cpp
 *
 * [941] 有效的山脉数组
 */

// @lc code=start
class Solution
{
public:
    bool validMountainArray(vector<int> &arr)
    {
        if (arr.size() < 3)
            return false;
        int max_num_index = max_element(arr.begin(), arr.end()) - arr.begin();
        if (max_num_index == 0 || max_num_index == arr.size() - 1)
            return false;
        for (int i = 1; i <= max_num_index; i++)
            if (arr[i] <= arr[i - 1])
                return false;
        for (int i = max_num_index; i < arr.size() - 1; i++)
            if (arr[i] <= arr[i + 1])
                return false;
        return true;
    }
};
// @lc code=end

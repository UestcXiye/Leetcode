/*
 * @lc app=leetcode.cn id=3069 lang=cpp
 *
 * [3069] 将元素分配到两个数组中 I
 */

// @lc code=start
class Solution
{
public:
    vector<int> resultArray(vector<int> &nums)
    {
        vector<int> arr1, arr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        for (int i = 2; i < nums.size(); i++)
        {
            if (arr1.back() > arr2.back())
                arr1.push_back(nums[i]);
            else
                arr2.push_back(nums[i]);
        }

        vector<int> result(arr1.begin(), arr1.end());
        for (int &x : arr2)
            result.push_back(x);
        return result;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=3010 lang=cpp
 *
 * [3010] 将数组分成最小总代价的子数组 I
 */

// @lc code=start

// STL

class Solution
{
public:
    int minimumCost(vector<int> &nums)
    {
        // 特判
        if (nums.size() == 3)
            return accumulate(nums.begin(), nums.end(), 0);

        int n = nums.size();

        // 第一个代价一定是 nums[0]
        int cost = *nums.begin();
        nums.erase(nums.begin());

        // 后面两个代价是 nums[1,...,n] 的最小值和次小值
        auto it = min_element(nums.begin(), nums.end());
        cost += *it;
        nums.erase(it);
        it = min_element(nums.begin(), nums.end());
        cost += *it;

        return cost;
    }
};

// 排序

// class Solution
// {
// public:
//     int minimumCost(vector<int> &nums)
//     {
//         sort(nums.begin() + 1, nums.end());
//         return accumulate(nums.begin(), nums.begin() + 3, 0);
//     }
// };
// @lc code=end

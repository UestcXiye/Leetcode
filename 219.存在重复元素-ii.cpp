/*
 * @lc app=leetcode.cn id=219 lang=cpp
 *
 * [219] 存在重复元素 II
 */

// @lc code=start
// class Solution
// {
// public:
//     bool containsNearbyDuplicate(vector<int> &nums, int k)
//     {
//         int n = nums.size();
//         if (n < 2)
//             return false;
//         unordered_map<int, int> umap;
//         for (int i = 0; i < n; i++)
//         {
//             if (umap.find(nums[i]) != umap.end() && i - umap[nums[i]] <= k)
//                 return true;
//             umap[nums[i]] = i;
//         }
//         return false;
//     }
// };
class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (n < 2)
            return false;
        unordered_set<int> uset;
        for (int i = 0; i < n; i++)
        {
            if (i > k)
                uset.erase(nums[i - k - 1]);
            if (uset.find(nums[i]) != uset.end())
                return true;
            uset.insert(nums[i]);
        }
        return false;
    }
};
// @lc code=end

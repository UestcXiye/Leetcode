/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
// class Solution
// {
// public:
//     vector<int> twoSum(vector<int> &nums, int target)
//     {
//         vector<int> ans;
//         int n = nums.size();
//         for (int i = 0; i < n; i++)
//             for (int j = i + 1; j < n; j++)
//                 if (nums[i] + nums[j] == target)
//                 {
//                     ans.push_back(i);
//                     ans.push_back(j);
//                 }
//         return ans;
//     }
// };

// 哈希

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        // 键是数字，值是该数字在数组的位置
        unordered_map<int, int> hash;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            int num = nums[i];
            auto pos = hash.find(target - num);
            if (pos == hash.end())
                hash[num] = i;
            else
            {
                ans.push_back(pos->second);
                ans.push_back(i);
                break;
            }
        }
        return ans;
    }
};
// @lc code=end

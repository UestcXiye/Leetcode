/*
 * @lc app=leetcode.cn id=448 lang=cpp
 *
 * [448] 找到所有数组中消失的数字
 */

// @lc code=start
// class Solution
// {
// public:
//     vector<int> findDisappearedNumbers(vector<int> &nums)
//     {
//         int n = nums.size();
//         set<int> s;
//         vector<int> ans;
//         for (int i = 0; i < n; i++)
//             s.insert(nums[i]);
//         for (int i = 1; i <= n; i++)
//             if (s.find(i) == s.end())
//                 ans.push_back(i);
//         return ans;
//     }
// };
class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        int n = nums.size();
        for (auto &num : nums)
        {
            int x = (num - 1) % n;
            nums[x] += n;
        }
        vector<int> ret;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] <= n)
            {
                ret.push_back(i + 1);
            }
        }
        return ret;
    }
};
// @lc code=end

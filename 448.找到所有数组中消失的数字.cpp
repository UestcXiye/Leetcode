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
        // 直接对原数组进行标记
        for (const int &num : nums)
        {
            int pos = abs(num) - 1;
            if (nums[pos] > 0)
                nums[pos] = -nums[pos];
        }
        vector<int> ans;
        for (int i = 0; i < n; i++)
            if (nums[i] > 0)
                ans.push_back(i + 1);
        return ans;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=2248 lang=cpp
 *
 * [2248] 多个数组求交集
 */

// @lc code=start
class Solution
{
public:
    vector<int> intersection(vector<vector<int>> &nums)
    {
        int n = nums.size();
        map<int, int> m;
        for (vector<int> arr : nums)
        {
            for (int num : arr)
                m[num]++;
        }
        vector<int> ans;
        for (auto iter : m)
        {
            if (iter.second == n)
                ans.push_back(iter.first);
        }
        return ans;
    }
};
// @lc code=end

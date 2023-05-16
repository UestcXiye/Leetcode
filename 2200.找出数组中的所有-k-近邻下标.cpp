/*
 * @lc app=leetcode.cn id=2200 lang=cpp
 *
 * [2200] 找出数组中的所有 K 近邻下标
 */

// @lc code=start
class Solution
{
public:
    vector<int> findKDistantIndices(vector<int> &nums, int key, int k)
    {
        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (abs(i - j) <= k && nums[j] == key)
                {
                    ans.push_back(i);
                    break;
                }
        // sort(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end

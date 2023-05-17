/*
 * @lc app=leetcode.cn id=2099 lang=cpp
 *
 * [2099] 找到和最大的长度为 K 的子序列
 */

// @lc code=start
class Solution
{
public:
    static bool cmp(const vector<int> A, const vector<int> B)
    {
        return A[1] > B[1];
    }
    vector<int> maxSubsequence(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<vector<int>> serials;
        for (int i = 0; i < n; i++)
            serials.push_back({i, nums[i]});
        sort(serials.begin(), serials.end(), cmp);
        vector<int> indexs;
        for (int i = 0; i < k; i++)
            indexs.push_back(serials[i][0]);
        sort(indexs.begin(), indexs.end());
        vector<int> ans;
        for (int index : indexs)
            ans.push_back(nums[index]);

        return ans;
    }
};
// @lc code=end

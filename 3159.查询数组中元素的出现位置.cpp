/*
 * @lc app=leetcode.cn id=3159 lang=cpp
 *
 * [3159] 查询数组中元素的出现位置
 */

// @lc code=start
class Solution
{
public:
    vector<int> occurrencesOfElement(vector<int> &nums, vector<int> &queries, int x)
    {
        vector<int> index;
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] == x)
                index.push_back(i);
        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); i++)
            ans[i] = queries[i] > index.size() ? -1 : index[queries[i] - 1];
        return ans;
    }
};
// @lc code=end

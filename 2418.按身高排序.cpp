/*
 * @lc app=leetcode.cn id=2418 lang=cpp
 *
 * [2418] 按身高排序
 */

// @lc code=start
class Solution
{
public:
    vector<string> sortPeople(vector<string> &names, vector<int> &heights)
    {
        int n = names.size();
        vector<int> indexs;
        for (int i = 0; i < n; i++)
            indexs.push_back(i);
        sort(indexs.begin(), indexs.end(), [&](int x, int y)
             { return heights[x] > heights[y]; });
        vector<string> ans(n);
        for (int i = 0; i < n; i++)
            ans[i] = names[indexs[i]];

        return ans;
    }
};
// @lc code=end

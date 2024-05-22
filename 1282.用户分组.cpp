/*
 * @lc app=leetcode.cn id=1282 lang=cpp
 *
 * [1282] 用户分组
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> groupThePeople(vector<int> &groupSizes)
    {
        unordered_map<int, vector<int>> group;
        for (int i = 0; i < groupSizes.size(); i++)
            group[groupSizes[i]].push_back(i);

        vector<vector<int>> ans;
        for (auto &[sz, vec] : group)
        {
            for (int i = 0; i < vec.size() / sz; i++)
            {
                vector<int> g;
                for (int j = 0; j < sz; j++)
                    g.push_back(vec[i * sz + j]);
                ans.push_back(g);
            }
        }

        return ans;
    }
};
// @lc code=end

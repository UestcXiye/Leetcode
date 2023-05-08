/*
 * @lc app=leetcode.cn id=506 lang=cpp
 *
 * [506] 相对名次
 */

// @lc code=start
class Solution
{
public:
    // cmp函数前面加个static，否则报错：
    // reference to non-static member function must be called
    static bool cmp(const pair<int, int> A, const pair<int, int> B)
    {
        return A.second > B.second; // 降序排列
    }
    vector<string> findRelativeRanks(vector<int> &score)
    {
        int n = score.size();
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
            v.push_back(pair<int, int>(i, score[i]));
        sort(v.begin(), v.end(), cmp);
        vector<string> ans(n);
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
                ans[v[i].first] = "Gold Medal";
            else if (i == 1)
                ans[v[i].first] = "Silver Medal";
            else if (i == 2)
                ans[v[i].first] = "Bronze Medal";
            else
                ans[v[i].first] = to_string(i + 1);
        }
        return ans;
    }
};
// @lc code=end

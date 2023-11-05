/*
 * @lc app=leetcode.cn id=1337 lang=cpp
 *
 * [1337] 矩阵中战斗力最弱的 K 行
 */

// @lc code=start
class Solution
{
private:
    static bool cmp(const pair<int, int> &p1, const pair<int, int> &p2)
    {
        if (p1.second == p2.second)
            return p1.first < p2.first;
        return p1.second < p2.second;
    }

public:
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
    {
        int m = mat.size(), n = m ? mat[0].size() : 0;
        vector<pair<int, int>> power;
        vector<int> ans;

        for (int i = 0; i < m; i++)
        {
            int soldier = 0;
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 1)
                    soldier++;
                else
                    break;
            }
            power.push_back(pair<int, int>(i, soldier));
        }
        sort(power.begin(), power.end(), cmp);
        for (int i = 0; i < k; i++)
            ans.push_back(power[i].first);

        return ans;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=3143 lang=cpp
 *
 * [3143] 正方形中的最多点数
 */

// @lc code=start
class Solution
{
public:
    int maxPointsInsideSquare(vector<vector<int>> &points, string s)
    {
        vector<pair<int, char>> combined;
        for (int i = 0; i < points.size(); i++)
        {
            int mx = max(abs(points[i][0]), abs(points[i][1]));
            combined.push_back({mx, s[i]});
        }
        sort(combined.begin(), combined.end(),
             [&](const pair<int, char> &p1, const pair<int, char> &p2)
             {
                 return p1.first < p2.first;
             });
        unordered_set<char> set;
        int bound = 0, ans = 0;
        for (auto &entry : combined)
        {
            if (entry.first > bound)
            {
                bound = entry.first;
                ans = set.size();
            }
            if (set.count(entry.second) == 0)
                set.insert(entry.second);
            else
                return ans;
        }
        return set.size();
    }
};
// @lc code=end

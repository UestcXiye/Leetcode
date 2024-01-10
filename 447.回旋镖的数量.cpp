/*
 * @lc app=leetcode.cn id=447 lang=cpp
 *
 * [447] 回旋镖的数量
 */

// @lc code=start

// 枚举 + 哈希

class Solution
{
public:
    int numberOfBoomerangs(vector<vector<int>> &points)
    {
        // 特判
        if (points.empty())
            return 0;

        int ans = 0;
        for (const vector<int> &p : points)
        {
            unordered_map<int, int> distances;
            for (const vector<int> &q : points)
            {
                int distance = (p[0] - q[0]) * (p[0] - q[0]) + (p[1] - q[1]) * (p[1] - q[1]);
                distances[distance]++;
            }
            for (auto &[_, dis] : distances)
                ans += dis * (dis - 1);
        }
        return ans;
    }
};
// @lc code=end

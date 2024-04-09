/*
 * @lc app=leetcode.cn id=3102 lang=cpp
 *
 * [3102] 最小化曼哈顿距离
 */

// @lc code=start
class Solution
{
public:
    int minimumDistance(vector<vector<int>> &points)
    {
        multiset<int> xs, ys;
        for (vector<int> &point : points)
        {
            // 曼哈顿距离 -> 切比雪夫距离
            xs.insert(point[0] + point[1]);
            ys.insert(point[1] - point[0]);
        }
        int ans = INT_MAX;
        for (auto &point : points)
        {
            int x = point[0] + point[1], y = point[1] - point[0];
            xs.erase(xs.find(x));
            ys.erase(ys.find(y));
            int x_dis = *xs.rbegin() - *xs.begin();
            int y_dis = *ys.rbegin() - *ys.begin();
            ans = min(ans, max(x_dis, y_dis));
            xs.insert(x);
            ys.insert(y);
        }
        return ans;
    }
};
// @lc code=end

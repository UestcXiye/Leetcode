/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
 */

// @lc code=start
class Solution
{
private:
    static bool cmp(const vector<int> A, const vector<int> B)
    {
        return A[1] < B[1];
    }
    bool remainBalloons(vector<bool> &burst)
    {
        for (int i = 0; i < burst.size(); i++)
            if (burst[i] == false)
                return true;
        return false;
    }

public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        if (points.empty())
            return 0;
        int n = points.size();
        vector<bool> burst(n, false);
        int ans = 0;
        sort(points.begin(), points.end(), cmp);
        while (remainBalloons(burst))
        {
            int i = 0;
            while (i < n && burst[i] == true)
                i++;
            for (int j = i; j < n; j++)
            {
                if (points[j][0] <= points[i][1])
                    burst[j] = true;
            }
            ans++;
        }
        return ans;
    }
};
// @lc code=end

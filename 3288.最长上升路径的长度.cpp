/*
 * @lc app=leetcode.cn id=3288 lang=cpp
 *
 * [3288] 最长上升路径的长度
 */

// @lc code=start
class Solution
{
public:
    int maxPathLength(vector<vector<int>> &coordinates, int k)
    {
        int n = coordinates.size();
        vector<array<int, 3>> vec;
        for (int i = 0; i < n; i++)
            vec.push_back({coordinates[i][0], coordinates[i][1], i});
        sort(vec.begin(), vec.end(),
             [&](array<int, 3> &a, array<int, 3> &b)
             {
                 if (a[0] != b[0])
                     return a[0] < b[0];
                 else
                     return a[1] > b[1];
             });

        int ans = -1;

        // 以规定点为终点的，从左到右看的最长上升子序列
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            int head = 0, tail = n;
            while (head < tail)
            {
                int mid = (head + tail + 1) >> 1;
                if (dp[mid] < vec[i][1])
                    head = mid;
                else
                    tail = mid - 1;
            }
            dp[head + 1] = vec[i][1];
            if (vec[i][2] == k)
            {
                ans += head + 1;
                break;
            }
        }

        // 以规定点为终点的，从右到左看的最长下降子序列
        fill(dp.begin() + 1, dp.end(), INT_MIN);
        dp[0] = INT_MAX;
        for (int i = n - 1; i >= 0; i--)
        {
            int head = 0, tail = n;
            while (head < tail)
            {
                int mid = (head + tail + 1) >> 1;
                if (dp[mid] > vec[i][1])
                    head = mid;
                else
                    tail = mid - 1;
            }
            dp[head + 1] = vec[i][1];
            if (vec[i][2] == k)
            {
                ans += head + 1;
                break;
            }
        }

        return ans;
    }
};
// @lc code=end

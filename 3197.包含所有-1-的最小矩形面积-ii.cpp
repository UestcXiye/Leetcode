/*
 * @lc app=leetcode.cn id=3197 lang=cpp
 *
 * [3197] 包含所有 1 的最小矩形面积 II
 */

// @lc code=start
class Solution
{
    // 顺时针旋转矩阵 90°
    vector<vector<int>> rotate(vector<vector<int>> &a)
    {
        int m = a.size();
        int n = a[0].size();
        vector<vector<int>> b(n, vector<int>(m));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                b[j][m - 1 - i] = a[i][j];
            }
        }
        return b;
    }

    int minimumArea(vector<vector<int>> &a, int u, int d, int l, int r)
    {
        int left = a[0].size(), right = 0, top = a.size(), bottom = 0;
        for (int i = u; i < d; i++)
        {
            for (int j = l; j < r; j++)
            {
                if (a[i][j] == 1)
                {
                    left = min(left, j);
                    right = max(right, j);
                    top = min(top, i);
                    bottom = i;
                }
            }
        }
        return (right - left + 1) * (bottom - top + 1);
    }

    int f(vector<vector<int>> &a)
    {
        int ans = INT_MAX;
        int m = a.size();
        int n = a[0].size();
        if (m >= 3)
        {
            for (int i = 1; i < m; i++)
            {
                for (int j = i + 1; j < m; j++)
                {
                    // 图片上左
                    int area = minimumArea(a, 0, i, 0, n);
                    area += minimumArea(a, i, j, 0, n);
                    area += minimumArea(a, j, m, 0, n);
                    ans = min(ans, area);
                }
            }
        }
        if (m >= 2 && n >= 2)
        {
            for (int i = 1; i < m; i++)
            {
                for (int j = 1; j < n; j++)
                {
                    // 图片上中
                    int area = minimumArea(a, 0, i, 0, n);
                    area += minimumArea(a, i, m, 0, j);
                    area += minimumArea(a, i, m, j, n);
                    ans = min(ans, area);
                    // 图片上右
                    area = minimumArea(a, 0, i, 0, j);
                    area += minimumArea(a, 0, i, j, n);
                    area += minimumArea(a, i, m, 0, n);
                    ans = min(ans, area);
                }
            }
        }
        return ans;
    }

public:
    int minimumSum(vector<vector<int>> &grid)
    {
        auto g = rotate(grid);
        return min(f(grid), f(g));
    }
};
// @lc code=end

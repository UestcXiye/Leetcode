/*
 * @lc app=leetcode.cn id=733 lang=cpp
 *
 * [733] 图像渲染
 */

// @lc code=start
class Solution
{
private:
    const int dx[4] = {1, 0, 0, -1};
    const int dy[4] = {0, 1, -1, 0};

public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        int currentColor = image[sr][sc];
        if (currentColor == color)
            return image;
        int m = image.size(), n = image[0].size();
        queue<pair<int, int>> q;
        q.emplace(sr, sc);
        image[sr][sc] = color;
        while (!q.empty())
        {
            int x = q.front().first, y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int mx = x + dx[i], my = y + dy[i];
                if (mx >= 0 && mx < m && my >= 0 && my < n && image[mx][my] == currentColor)
                {
                    q.emplace(mx, my);
                    image[mx][my] = color;
                }
            }
        }
        return image;
    }
};
// @lc code=end

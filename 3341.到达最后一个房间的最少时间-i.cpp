/*
 * @lc app=leetcode.cn id=3341 lang=cpp
 *
 * [3341] 到达最后一个房间的最少时间 I
 */

// @lc code=start
class Solution
{
private:
    const int dx[4] = {0, 1, 0, -1};
    const int dy[4] = {1, 0, -1, 0};

public:
    int minTimeToReach(vector<vector<int>> &moveTime)
    {
        int m = moveTime.size(), n = m ? moveTime[0].size() : 0;

        // distance[i][j]记录从节点(0,0)到当前节点(i,j)的最短路径
        vector<vector<int>> distance(m, vector<int>(n, INT_MAX / 2));
        queue<pair<int, int>> q;
        int ans = INT_MAX;

        q.push({0, 0});
        distance[0][0] = 0;

        while (!q.empty())
        {
            auto t = q.front();
            q.pop();
            int x = t.first / n, y = t.first % n;

            if (x == m - 1 && y == n - 1)
                ans = min(ans, t.second);

            for (int i = 0; i < 4; i++)
            {
                int r = x + dx[i], c = y + dy[i];
                if (r >= 0 && r < m && c >= 0 && c < n)
                {
                    if (moveTime[r][c] >= distance[x][y])
                    {
                        if (distance[r][c] <= moveTime[r][c] + 1)
                            continue;
                        distance[r][c] = moveTime[r][c] + 1;
                        q.push({r * n + c, distance[r][c]});
                    }
                    else
                    {
                        if (distance[r][c] <= distance[x][y] + 1)
                            continue;
                        distance[r][c] = distance[x][y] + 1;
                        q.push({r * n + c, distance[r][c]});
                    }
                }
            }
        }

        return ans;
    }
};
// @lc code=end

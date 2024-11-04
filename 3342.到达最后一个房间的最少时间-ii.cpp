/*
 * @lc app=leetcode.cn id=3342 lang=cpp
 *
 * [3342] 到达最后一个房间的最少时间 II
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
        vector<vector<int>> distance(m, vector<int>(n, INT_MAX));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

        pq.emplace(0, 0, 0);
        distance[0][0] = 0;

        while (1)
        {
            auto [dis, x, y] = pq.top();
            pq.pop();

            if (x == m - 1 && y == n - 1)
                return dis;

            if (dis > distance[x][y])
                continue;

            for (int i = 0; i < 4; i++)
            {
                int r = x + dx[i], c = y + dy[i];
                if (r >= 0 && r < m && c >= 0 && c < n)
                {
                    int new_dis = max(dis, moveTime[r][c]) + (x + y) % 2 + 1;
                    if (new_dis < distance[r][c])
                    {
                        distance[r][c] = new_dis;
                        pq.emplace(new_dis, r, c);
                    }
                }
            }
        }
    }
};
// @lc code=end

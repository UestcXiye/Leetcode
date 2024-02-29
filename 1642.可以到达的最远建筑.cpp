/*
 * @lc app=leetcode.cn id=1642 lang=cpp
 *
 * [1642] 可以到达的最远建筑
 */

// @lc code=start
class Solution
{
public:
    int furthestBuilding(vector<int> &heights, int bricks, int ladders)
    {
        int n = heights.size();
        // 小根堆
        priority_queue<int, vector<int>, greater<int>> pq;
        // 使用砖块总数
        int sumH = 0;

        for (int i = 0; i < n - 1; i++)
        {
            int deltaH = heights[i + 1] - heights[i];
            if (deltaH > 0)
            {
                pq.push(deltaH);
                // 反悔，最小的高度差改为使用砖块
                if (pq.size() > ladders)
                {
                    sumH += pq.top();
                    pq.pop();
                }
                // 都用完了，返回当前下标
                if (sumH > bricks)
                    return i;
            }
        }
        return n - 1;
    }
};
// @lc code=end

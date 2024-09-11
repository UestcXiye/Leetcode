/*
 * @lc app=leetcode.cn id=3275 lang=cpp
 *
 * [3275] 第 K 近障碍物查询
 */

// @lc code=start
class Solution
{
public:
    vector<int> resultsArray(vector<vector<int>> &queries, int k)
    {
        int n = queries.size();
        vector<int> ans(n, -1);
        priority_queue<int> pq; // 大根堆
        for (int i = 0; i < n; i++)
        {
            int dis = abs(queries[i][0]) + abs(queries[i][1]);
            pq.push(dis);
            if (pq.size() > k)
                pq.pop();
            if (pq.size() == k)
            {
                // 堆顶就是当前第 k 小的距离
                ans[i] = pq.top();
            }
        }
        return ans;
    }
};
// @lc code=end

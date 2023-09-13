/*
 * @lc app=leetcode.cn id=218 lang=cpp
 *
 * [218] 天际线问题
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings)
    {
        vector<vector<int>> ans;
        // 使用优先队列储存每个建筑物的高度和右端
        // 这里使用pair，其默认比较函数是先比较第一个值，如果相等则再比较第二个值
        priority_queue<pair<int, int>> max_heap; // <高度, 右端>
        int i = 0, n = buildings.size();
        int cur_x, cur_h;
        // 获取目前会拔高天际线、且妨碍到前一个建筑物（的右端端点）的下一个建筑物
        while (i < n || !max_heap.empty())
        {
            if (max_heap.empty() || (i < n && buildings[i][0] <= max_heap.top().second))
            {
                cur_x = buildings[i][0];
                while (i < n && cur_x == buildings[i][0])
                {
                    max_heap.push(pair<int, int>(buildings[i][2], buildings[i][1]));
                    i++;
                }
            }
            else
            {
                cur_x = max_heap.top().second;
                while (!max_heap.empty() && cur_x >= max_heap.top().second)
                    max_heap.pop();
            }
            cur_h = (max_heap.empty()) ? 0 : max_heap.top().first;
            if (ans.empty() || cur_h != ans.back()[1])
                ans.push_back({cur_x, cur_h});
        }
        return ans;
    }
};
// @lc code=end

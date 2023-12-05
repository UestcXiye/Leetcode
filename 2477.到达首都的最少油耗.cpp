/*
 * @lc app=leetcode.cn id=2477 lang=cpp
 *
 * [2477] 到达首都的最少油耗
 */

// @lc code=start
class Solution
{
private:
    long long ans = 0;

public:
    long long minimumFuelCost(vector<vector<int>> &roads, int seats)
    {
        // 特判
        if (roads.empty() || seats == 0)
            return 0;
        int n = roads.size();
        vector<vector<int>> edges(n + 1);
        for (vector<int> &road : roads)
        {
            int from = road[0], to = road[1];
            // 记录每个点的邻居
            edges[from].push_back(to);
            edges[to].push_back(from);
        }
        function<int(int, int)> dfs = [&](int x, int father) -> int
        {
            int subTreeSize = 1;
            for (int &y : edges[x])
                if (y != father) // 递归子节点，不能递归父节点
                {
                    // 统计子树大小
                    subTreeSize += dfs(y, x);
                }
            if (x != 0) // x 不是根节点
                ans += ceil(1.0 * subTreeSize / seats);
            return subTreeSize;
        };
        dfs(0, -1);
        return ans;
    }
};
// @lc code=end

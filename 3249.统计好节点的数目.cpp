/*
 * @lc app=leetcode.cn id=3249 lang=cpp
 *
 * [3249] 统计好节点的数目
 */

// @lc code=start
class Solution
{
public:
    int countGoodNodes(vector<vector<int>> &edges)
    {
        int n = edges.size() + 1; // 节点数

        // 构建邻接表
        vector<vector<int>> adj(n);
        for (vector<int> &edge : edges)
        {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int ans = 0;

        // parent 为父节点
        function<int(int, int)> dfs = [&](int u, int parent) -> int
        {
            int cnt_sum = 1; // 节点总数，先计入自身
            int single_cnt = 0;
            bool valid = true;

            for (int v : adj[u])
            {
                // 规避邻接点中已访问过的父节点，不需要 visited 数组
                if (v == parent)
                    continue;

                int cnt = dfs(v, u);
                cnt_sum += cnt;
                // 检测子树的节点数量是否相同
                if (single_cnt == 0)
                    single_cnt = cnt;
                else if (single_cnt != cnt)
                    valid = false;
            }
            ans += valid;
            return cnt_sum;
        };

        dfs(0, -1); // -1 即不存在父节点
        return ans;
    }
};
// @lc code=end

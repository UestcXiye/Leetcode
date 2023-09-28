/*
 * @lc app=leetcode.cn id=684 lang=cpp
 *
 * [684] 冗余连接
 */

// @lc code=start
class UnionFind
{
private:
    vector<int> father, size;

public:
    UnionFind(int n) : father(n), size(n, 1)
    {
        // iota函数可以把数组初始化为 0 到 n-1
        iota(father.begin(), father.end(), 0);
    }
    int find(int x)
    {
        while (x != father[x])
        {
            // 路径压缩，使得下次查找更快
            father[x] = father[father[x]];
            x = father[x];
        }
        return x;
    }
    void connect(int p, int q)
    {
        int i = find(p), j = find(q);
        if (i != j)
        {
            // 按秩合并：每次合并都把深度较小的集合合并在深度较大的集合下面
            if (size[i] < size[j])
            {
                father[i] = j;
                size[j] += size[i];
            }
            else
            {
                father[j] = i;
                size[i] += size[j];
            }
        }
    }
    bool isConnected(int p, int q)
    {
        return find(p) == find(q);
    }
};
class Solution
{
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        int n = edges.size();
        UnionFind uf(n + 1);
        // uf.init();
        for (auto &edge : edges)
        {
            int u = edge[0], v = edge[1];
            if (uf.isConnected(u, v))
                return edge;
            uf.connect(u, v);
        }
        return {};
    }
};
// @lc code=end

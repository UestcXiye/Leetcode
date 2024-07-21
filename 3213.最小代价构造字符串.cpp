/*
 * @lc app=leetcode.cn id=3213 lang=cpp
 *
 * [3213] 最小代价构造字符串
 */

// @lc code=start
class Solution
{
public:
    int minimumCost(string target, vector<string> &words, vector<int> &costs)
    {
        int n = target.length();

        // 多项式字符串哈希（方便计算子串哈希值）
        // 哈希函数 hash(s) = s[0] * base^(n-1) + s[1] * base^(n-2) + ... + s[n-2] * base + s[n-1]
        const int MOD = 1'070'777'777;
        mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
        const int BASE = uniform_int_distribution<>(8e8, 9e8)(rng); // 随机 base，防止 hack
        vector<int> pow_base(n + 1);                                // pow_base[i] = base^i
        vector<int> pre_hash(n + 1);                                // 前缀哈希值 pre_hash[i] = hash(s[:i])
        pow_base[0] = 1;
        for (int i = 0; i < n; i++)
        {
            pow_base[i + 1] = (long long)pow_base[i] * BASE % MOD;
            pre_hash[i + 1] = ((long long)pre_hash[i] * BASE + target[i]) % MOD; // 秦九韶算法计算多项式哈希
        }

        // 计算 target[l] 到 target[r-1] 的哈希值
        auto sub_hash = [&](int l, int r)
        {
            return ((pre_hash[r] - (long long)pre_hash[l] * pow_base[r - l]) % MOD + MOD) % MOD;
        };

        map<int, unordered_map<int, int>> min_cost; // 长度 -> 哈希值 -> 最小成本
        for (int i = 0; i < words.size(); i++)
        {
            long long h = 0;
            for (char b : words[i])
            {
                h = (h * BASE + b) % MOD;
            }
            int m = words[i].length();
            if (min_cost[m].find(h) == min_cost[m].end())
            {
                min_cost[m][h] = costs[i];
            }
            else
            {
                min_cost[m][h] = min(min_cost[m][h], costs[i]);
            }
        }

        vector<int> f(n + 1, INT_MAX / 2);
        f[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (auto &[len, mc] : min_cost)
            {
                if (len > i)
                {
                    break;
                }
                auto it = mc.find(sub_hash(i - len, i));
                if (it != mc.end())
                {
                    f[i] = min(f[i], f[i - len] + it->second);
                }
            }
        }
        return f[n] == INT_MAX / 2 ? -1 : f[n];
    }
};
// @lc code=end

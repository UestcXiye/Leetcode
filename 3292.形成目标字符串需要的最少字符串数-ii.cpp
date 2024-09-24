/*
 * @lc app=leetcode.cn id=3292 lang=cpp
 *
 * [3292] 形成目标字符串需要的最少字符串数 II
 */

// @lc code=start
class Solution
{
public:
    int minValidStrings(const vector<string> &words, const string &target)
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

        int max_len = 0;
        for (auto &w : words)
        {
            max_len = max(max_len, (int)w.length());
        }
        vector<unordered_set<int>> sets(max_len);
        for (auto &w : words)
        {
            long long h = 0;
            for (int j = 0; j < w.size(); j++)
            {
                h = (h * BASE + w[j]) % MOD;
                sets[j].insert(h); // 注意 j 从 0 开始
            }
        }
        auto calc_sz = [&](int i) -> int
        {
            // 开区间二分，left 一定满足要求，right 一定不满足要求
            int left = 0, right = min(n - i, max_len) + 1;
            while (left + 1 < right)
            {
                int mid = (left + right) / 2;
                (sets[mid - 1].contains(sub_hash(i, i + mid)) ? left : right) = mid;
            }
            return left;
        };

        int ans = 0;
        int cur_r = 0; // 已建造的桥的右端点
        int nxt_r = 0; // 下一座桥的右端点的最大值
        for (int i = 0; i < n; i++)
        {
            int sz = calc_sz(i);
            nxt_r = max(nxt_r, i + sz);
            if (i == cur_r)
            { // 到达已建造的桥的右端点
                if (i == nxt_r)
                { // 无论怎么造桥，都无法从 i 到 i+1
                    return -1;
                }
                cur_r = nxt_r; // 造一座桥
                ans++;
            }
        }
        return ans;
    }
};
// @lc code=end

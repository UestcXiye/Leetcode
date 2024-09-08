/*
 * @lc app=leetcode.cn id=3272 lang=cpp
 *
 * [3272] 统计好整数的数目
 */

// @lc code=start
class Solution
{
private:
    vector<int> factorial;
    void init(int n)
    {
        factorial.assign(n + 1, 0);
        factorial[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            factorial[i] = factorial[i - 1] * i;
        }
    }

public:
    long long countGoodIntegers(int n, int k)
    {
        init(n);

        long long ans = 0;
        unordered_set<string> vis;
        int base = pow(10, (n - 1) / 2);
        for (int i = base; i < base * 10; i++)
        { // 枚举回文数左半边
            string s = to_string(i);
            s += string(s.rbegin() + (n % 2), s.rend());
            if (stoll(s) % k)
            { // 回文数不能被 k 整除
                continue;
            }

            ranges::sort(s);
            if (!vis.insert(s).second)
            { // 不能重复统计
                continue;
            }

            int cnt[10]{};
            for (char c : s)
            {
                cnt[c - '0']++;
            }
            int res = (n - cnt[0]) * factorial[n - 1];
            for (int c : cnt)
            {
                res /= factorial[c];
            }
            ans += res;
        }
        return ans;
    }
};
// @lc code=end

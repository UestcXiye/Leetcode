/*
 * @lc app=leetcode.cn id=2983 lang=cpp
 *
 * [2983] 回文串重新排列查询
 */

// @lc code=start
class Solution
{
public:
    vector<bool> canMakePalindromeQueries(string s, vector<vector<int>> &queries)
    {
        // 分成左右两半，右半反转
        int n = s.length() / 2;
        string t = s.substr(n);
        reverse(t.begin(), t.end());

        // 预处理三种前缀和
        vector<vector<int>> sum_s(n + 1, vector<int>(26));
        for (int i = 0; i < n; i++)
        {
            sum_s[i + 1] = sum_s[i];
            sum_s[i + 1][s[i] - 'a']++;
        }

        vector<vector<int>> sum_t(n + 1, vector<int>(26));
        for (int i = 0; i < n; i++)
        {
            sum_t[i + 1] = sum_t[i];
            sum_t[i + 1][t[i] - 'a']++;
        }

        vector<int> sum_ne(n + 1);
        for (int i = 0; i < n; i++)
        {
            sum_ne[i + 1] = sum_ne[i] + (s[i] != t[i]);
        }

        // 计算子串中各个字符的出现次数，闭区间 [l, r]
        auto count = [](vector<vector<int>> &sum, int l, int r) -> vector<int>
        {
            auto res = sum[r + 1];
            for (int i = 0; i < 26; i++)
            {
                res[i] -= sum[l][i];
            }
            return res;
        };

        auto subtract = [](vector<int> s1, vector<int> s2) -> vector<int>
        {
            for (int i = 0; i < 26; i++)
            {
                s1[i] -= s2[i];
                if (s1[i] < 0)
                {
                    return {};
                }
            }
            return s1;
        };

        auto check = [&](int l1, int r1, int l2, int r2, vector<vector<int>> &sumS, vector<vector<int>> &sumT) -> bool
        {
            if (sum_ne[l1] > 0 || // [0, l1-1] 有 s[i] != t[i]
                sum_ne[n] - sum_ne[max(r1, r2) + 1] > 0)
            { // [max(r1,r2)+1, n-1] 有 s[i] != t[i]
                return false;
            }
            // 区间包含
            if (r2 <= r1)
            {
                return count(sumS, l1, r1) == count(sumT, l1, r1);
            }
            // 区间不相交
            if (r1 < l2)
            {
                return sum_ne[l2] - sum_ne[r1 + 1] == 0 && // [r1+1, l2-1] 都满足 s[i] == t[i]
                       count(sumS, l1, r1) == count(sumT, l1, r1) &&
                       count(sumS, l2, r2) == count(sumT, l2, r2);
            }
            // 区间相交但不包含
            auto s1 = subtract(count(sumS, l1, r1), count(sumT, l1, l2 - 1));
            auto s2 = subtract(count(sumT, l2, r2), count(sumS, r1 + 1, r2));
            return !s1.empty() && !s2.empty() && s1 == s2;
        };

        vector<bool> ans(queries.size());
        for (int i = 0; i < queries.size(); i++)
        {
            auto &q = queries[i];
            int l1 = q[0], r1 = q[1], l2 = n * 2 - 1 - q[3], r2 = n * 2 - 1 - q[2];
            ans[i] = l1 <= l2 ? check(l1, r1, l2, r2, sum_s, sum_t) : check(l2, r2, l1, r1, sum_t, sum_s);
        }
        return ans;
    }
};
// @lc code=end

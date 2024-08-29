/*
 * @lc app=leetcode.cn id=3234 lang=cpp
 *
 * [3234] 统计 1 显著的字符串的数量
 */

// @lc code=start
class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        int n = s.length();
        vector<int> a;
        for (int i = 0; i < n; i++)
            if (s[i] == '0')
                a.push_back(i);

        int tot1 = n - a.size();
        a.push_back(n); // 哨兵

        int ans = 0, i = 0; // >= left 的第一个 0 的下标是 a[i]

        // 枚举子串左端点
        for (int left = 0; left < n; left++)
        { // 枚举子串有多少个 0
            // 枚举 0 的下标
            for (int k = i; k < a.size() - 1; k++)
            {
                int cnt0 = k - i + 1;
                if (cnt0 * cnt0 > tot1)
                    break;
                int p = a[k], q = a[k + 1];
                int cnt1 = a[k] - left - (k - i);
                if (cnt1 >= cnt0 * cnt0)
                {
                    // p, p+1, ..., q-1 都可以作为子串的右端点
                    ans += q - p;
                }
                else
                {
                    // cnt1 的个数少，补充 cnt0 * cnt0 - cnt1 个
                    ans += max(q - p - (cnt0 * cnt0 - cnt1), 0);
                }
            }
            // 没有 0 的情况
            if (s[left] == '0')
            {
                i++; // 这个 0 后面不会再枚举到了
            }
            else
            {
                ans += a[i] - left; // 不含 0 的子串个数
                tot1--;
            }
        }
        return ans;
    }
};
// @lc code=end

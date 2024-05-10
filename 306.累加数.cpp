/*
 * @lc app=leetcode.cn id=306 lang=cpp
 *
 * [306] 累加数
 */

// @lc code=start
class Solution
{
public:
    bool isAdditiveNumber(string num)
    {
        int n = num.length();
        vector<vector<int>> list;

        function<bool(int)> backtrack = [&](int u) -> bool
        {
            int m = list.size();
            if (u == n)
                return m >= 3;
            int max = num[u] == '0' ? u + 1 : n; // 处理前导 0
            vector<int> cur;
            for (int i = u; i < max; i++)
            {
                // 枚举[u,n - 1]
                cur.insert(cur.begin(), num[i] - '0');
                if (m < 2 || check(list[m - 2], list[m - 1], cur))
                {
                    list.push_back(cur);
                    if (backtrack(i + 1))
                        return true;
                    list.pop_back();
                }
            }
            return false;
        };

        return backtrack(0);
    }
    // 辅函数 - 高精度加法判断 a+b 是否等于 c
    bool check(vector<int> &a, vector<int> &b, vector<int> &c)
    {
        vector<int> ans;
        int t = 0;
        for (int i = 0; i < a.size() || i < b.size(); i++)
        {
            if (i < a.size())
                t += a[i];
            if (i < b.size())
                t += b[i];
            ans.push_back(t % 10);
            t /= 10;
        }
        if (t > 0)
        { // 处理最高位的进位
            ans.push_back(1);
        }
        if (c.size() != ans.size())
            return false;
        for (int i = 0; i < c.size(); i++)
        {
            if (c[i] != ans[i])
                return false;
        }
        return true;
    }
};
// @lc code=end

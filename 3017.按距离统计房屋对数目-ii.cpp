/*
 * @lc app=leetcode.cn id=3017 lang=cpp
 *
 * [3017] 按距离统计房屋对数目 II
 */

// @lc code=start
class Solution
{
public:
    vector<long long> countOfPairs(int n, int x, int y)
    {
        if (x > y)
        {
            swap(x, y);
        }

        vector<int> diff(n + 1);

        auto add = [&](int l, int r, int v)
        {
            if (l > r)
                return;
            diff[l] += v;
            diff[r + 1] -= v;
        };

        auto update = [&](int i, int x, int y)
        {
            add(y - i, n - i, -1); // 撤销 [y,n]
            int dec = y - x - 1;   // 缩短的距离
            add(y - i - dec, n - i - dec, 1);

            int j = (x + y + 1) / 2 + 1;
            add(j - i, y - 1 - i, -1); // 撤销 [j, y-1]
            add(x - i + 2, x - i + y - j + 1, 1);
        };

        auto update2 = [&](int i, int x, int y)
        {
            add(y - i, n - i, -1);           // 撤销 [y,n]
            int dec = (y - i) - (i - x + 1); // 缩短的距离
            add(y - i - dec, n - i - dec, 1);

            int j = i + (y - x + 1) / 2 + 1;
            add(j - i, y - 1 - i, -1); // 撤销 [j, y-1]
            add(i - x + 2, i - x + y - j + 1, 1);
        };

        for (int i = 1; i <= n; i++)
        {
            add(1, i - 1, 1);
            add(1, n - i, 1);
            if (x + 1 >= y)
            {
                continue;
            }
            if (i <= x)
            {
                update(i, x, y);
            }
            else if (i >= y)
            {
                update(n + 1 - i, n + 1 - y, n + 1 - x);
            }
            else if (i < (x + y) / 2)
            {
                update2(i, x, y);
            }
            else if (i > (x + y + 1) / 2)
            {
                update2(n + 1 - i, n + 1 - y, n + 1 - x);
            }
        }

        vector<long long> ans(n);
        long long sum_d = 0;
        for (int i = 0; i < n; i++)
        {
            sum_d += diff[i + 1];
            ans[i] = sum_d;
        }
        return ans;
    }
};
// @lc code=end

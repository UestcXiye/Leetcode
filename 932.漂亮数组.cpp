/*
 * @lc app=leetcode.cn id=932 lang=cpp
 *
 * [932] 漂亮数组
 */

// @lc code=start

// 性质1：如果 X, Y, Z 是一个漂亮数组，则 k*X+b, k*Y+b, k*Z+b 也一定是漂亮数组
// 性质2：奇数 + 偶数 = 奇数

// 思路：
// 对于一个正整数 n，我们将其等分为两部分 left 和 right，
// 如果 left 和 right 都是漂亮数组，且 left 全部是奇数，right 全部是偶数，
// 那么此时 left +  right 一定是漂亮数组。

// 自顶向下的分治算法：
// 先将数组分为两部分，将奇数放在 left，偶数放在 right，
// 同时保证 left 和 right 都是漂亮数组
// 递归...

class Solution
{
public:
    vector<int> beautifulArray(int n)
    {
        // unordered_map<int, vector<int>> umap;
        vector<int> ans(n, 0);
        int t = 0;
        // if (umap.find(n) != umap.end())
        //     return umap[n];
        if (n != 1)
        {
            for (auto x : beautifulArray((n + 1) / 2))
                ans[t++] = 2 * x - 1; // left
            for (auto x : beautifulArray(n / 2))
                ans[t++] = 2 * x; // right
        }
        else
            ans[0] = 1;
        // umap[n] = ans;
        return ans;
    }
};
// @lc code=end

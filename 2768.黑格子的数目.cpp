/*
 * @lc app=leetcode.cn id=2768 lang=cpp
 *
 * [2768] 黑格子的数目
 */

// @lc code=start
class Solution
{
private:
    const int dx[4] = {-1, 0, -1, 0};
    const int dy[4] = {-1, -1, 0, 0};

public:
    vector<long long> countBlackBlocks(int m, int n, vector<vector<int>> &coordinates)
    {
        map<pair<int, int>, int> cnt;
        for (vector<int> &coordinate : coordinates)
        {
            int x = coordinate[0], y = coordinate[1];
            // 位于 [x,y] 的黑块，对 [x-1,y-1]、[x-1,y]、[x,y-1]、[x,y] 的贡献为 1
            for (int k = 0; k < 4; k++)
            {
                int r = x + dx[k], c = y + dy[k];
                if (r >= 0 && r < m - 1 && c >= 0 && c < n - 1)
                    cnt[{r, c}]++;
            }
        }
        vector<long long> ans(5, 0LL);
        for (auto &[p, c] : cnt)
            ans[c]++;
        ans[0] = (long long)(m - 1) * (n - 1) - accumulate(ans.begin() + 1, ans.end(), 0LL);
        return ans;
    }
};
// @lc code=end

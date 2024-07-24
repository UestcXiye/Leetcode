/*
 * @lc app=leetcode.cn id=3219 lang=cpp
 *
 * [3219] 切蛋糕的最小总开销 II
 */

// @lc code=start
class Solution
{
public:
    long long minimumCost(int m, int n, vector<int> &horizontalCut, vector<int> &verticalCut)
    {
        sort(horizontalCut.begin(), horizontalCut.end(), greater<int>());
        sort(verticalCut.begin(), verticalCut.end(), greater<int>());

        long long ans = 0;
        int cnt_h = 1, cnt_v = 1;
        int i = 0, j = 0;
        while (i < m - 1 || j < n - 1)
        {
            if (j == n - 1 || i < m - 1 && horizontalCut[i] > verticalCut[j])
            {
                ans += horizontalCut[i++] * cnt_h; // 横切
                cnt_v++;                           // 需要竖切的蛋糕块增加
            }
            else
            {
                ans += verticalCut[j++] * cnt_v; // 竖切
                cnt_h++;                         // 需要横切的蛋糕块增加
            }
        }
        return ans;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=3208 lang=cpp
 *
 * [3208] 交替组 II
 */

// @lc code=start
class Solution
{
public:
    int numberOfAlternatingGroups(vector<int> &colors, int k)
    {
        int n = colors.size();
        int ans = 0, cnt = 0;
        for (int i = 0; i < n * 2; i++)
        {
            if (i > 0 && colors[i % n] == colors[(i - 1) % n])
            {
                cnt = 0;
            }
            cnt++;
            ans += i >= n && cnt >= k;
        }
        return ans;
    }
};
// @lc code=end

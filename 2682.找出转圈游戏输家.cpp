/*
 * @lc app=leetcode.cn id=2682 lang=cpp
 *
 * [2682] 找出转圈游戏输家
 */

// @lc code=start
class Solution
{
public:
    vector<int> circularGameLosers(int n, int k)
    {
        vector<int> count(n + 1, 0);
        int location = 1, i = 1;
        while (true)
        {
            count[location]++;
            if (count[location] == 2)
                break;
            location = (location + i * k) % n == 0 ? n : (location + i * k) % n;
            i++;
        }
        vector<int> ans;
        for (int j = 1; j <= n; j++)
        {
            if (count[j] == 0)
                ans.push_back(j);
        }
        return ans;
    }
};
// @lc code=end

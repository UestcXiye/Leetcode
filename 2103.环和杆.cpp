/*
 * @lc app=leetcode.cn id=2103 lang=cpp
 *
 * [2103] 环和杆
 */

// @lc code=start
class Solution
{
public:
    int countPoints(string rings)
    {
        bool rod[10][3];
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 3; j++)
                rod[i][j] = false;
        int n = rings.size() / 2;
        for (int i = 0; i < n; i++)
        {
            int serial = rings[2 * i + 1] - '0';
            char color = rings[2 * i];
            if (color == 'R')
                rod[serial][0] = true;
            else if (color == 'G')
                rod[serial][1] = true;
            else
                rod[serial][2] = true;
        }
        int ans = 0;
        for (int i = 0; i < 10; i++)
        {
            if (rod[i][0] && rod[i][1] && rod[i][2])
                ans++;
        }
        return ans;
    }
};
// @lc code=end

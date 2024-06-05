/*
 * @lc app=leetcode.cn id=3168 lang=cpp
 *
 * [3168] 候诊室中的最少椅子数
 */

// @lc code=start
class Solution
{
public:
    int minimumChairs(string s)
    {
        int chair = 0;
        int max_chair = INT_MIN;
        for (char &c : s)
        {
            if (c == 'E')
            {
                chair++;
                if (chair > max_chair)
                    max_chair = chair;
            }
            else
                chair--;
        }
        return max_chair;
    }
};
// @lc code=end

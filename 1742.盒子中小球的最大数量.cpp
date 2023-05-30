/*
 * @lc app=leetcode.cn id=1742 lang=cpp
 *
 * [1742] 盒子中小球的最大数量
 */

// @lc code=start
class Solution
{
public:
    int countBalls(int lowLimit, int highLimit)
    {
        vector<int> v(46, 0);
        for (int i = lowLimit; i <= highLimit; i++)
        {
            int number = 0, num = i;
            while (num)
            {
                number += num % 10;
                num /= 10;
            }
            v[number]++;
        }
        int maxCount = 0;
        for (int i = 1; i <= 45; i++)
        {
            if (v[i] > maxCount)
            {
                maxCount = v[i];
            }
        }
        return maxCount;
    }
};
// @lc code=end

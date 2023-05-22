/*
 * @lc app=leetcode.cn id=605 lang=cpp
 *
 * [605] 种花问题
 */

// @lc code=start
class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        if (n > (flowerbed.size() + 1) / 2)
            return false;
        int count = 0;
        int prev = -1;
        for (int i = 0; i < flowerbed.size(); i++)
        {
            if (flowerbed[i] == 1)
            {
                if (prev < 0)
                    count += i / 2;
                else
                    count += (i - prev - 2) / 2;
                prev = i;
            }
        }
        if (prev < 0)
            count = (flowerbed.size() + 1) / 2;
        else
            count += (flowerbed.size() - prev - 1) / 2;
        return n <= count;
    }
};
// @lc code=end

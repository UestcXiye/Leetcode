/*
 * @lc app=leetcode.cn id=970 lang=cpp
 *
 * [970] 强整数
 */

// @lc code=start
class Solution
{
public:
    vector<int> powerfulIntegers(int x, int y, int bound)
    {
        unordered_set<int> nums;
        // for (int i = 1; i < bound; i *= x)
        // {
        //     for (int j = 1; i + j <= bound; j *= y)
        //     {
        //         nums.insert(i + j);
        //         if (y == 1)
        //             break;
        //     }
        //     if (x == 1)
        //         break;
        // }
        int num1 = 1;
        for (int i = 0; i <= 20; i++)
        {
            int num2 = 1;
            for (int j = 0; j <= 20; j++)
            {
                int num = num1 + num2;
                if (num <= bound)
                    nums.insert(num);
                else
                    break;
                num2 *= y;
            }
            if (num1 >= bound)
                break;
            num1 *= x;
        }
        return vector<int>(nums.begin(), nums.end());
    }
};
// @lc code=end

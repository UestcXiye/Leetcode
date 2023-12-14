/*
 * @lc app=leetcode.cn id=400 lang=cpp
 *
 * [400] 第 N 位数字
 */

// @lc code=start
class Solution
{
public:
    int findNthDigit(int index)
    {
        if (index < 0)
            return -1;
        int digits = 1;
        while (true)
        {
            int numbers = countOfIntegers(digits);
            if (index < (long long)digits * numbers)
                return digitAtIndex(index, digits);
            index -= digits * numbers;
            digits++;
        }
        return -1;
    }
    int digitAtIndex(int index, int digits)
    {
        int number = beginNumber(digits) + index / digits;
        int indexFromRight = digits - index % digits;
        for (int i = 1; i < indexFromRight; i++)
            number /= 10;
        return number % 10;
    }
    // 辅函数 - 返回 digits 位数的总个数
    int countOfIntegers(int digits)
    {
        if (digits == 1)
            return 10;
        int count = pow(10, digits - 1);
        return 9 * count;
    }
    // 辅函数 - 返回 digits 位数的第一个数字
    int beginNumber(int digits)
    {
        if (digits == 1)
            return 0;
        return pow(10, digits - 1);
    }
};
// @lc code=end

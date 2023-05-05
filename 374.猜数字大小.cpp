/*
 * @lc app=leetcode.cn id=374 lang=cpp
 *
 * [374] 猜数字大小
 */

// @lc code=start
/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution
{
public:
    int guessNumber(int n)
    {
        int begin = 1, end = n, mid, ans;
        while (begin < end)
        {
            // mid = (begin + end) / 2;
            mid = begin + (end - begin) / 2;
            if (guess(mid) == -1)
            {
                end = mid - 1;
            }
            else if (guess(mid) == 1)
            {
                begin = mid + 1;
            }
            else
                return mid;
        }
        return begin;
    }
};
// @lc code=end

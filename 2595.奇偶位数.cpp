/*
 * @lc app=leetcode.cn id=2595 lang=cpp
 *
 * [2595] 奇偶位数
 */

// @lc code=start
class Solution
{
public:
    vector<int> transToBits(int n)
    {
        vector<int> bits;
        while (n)
        {
            bits.push_back(n % 2);
            n /= 2;
        }
        // reverse(bits.begin(), bits.end());
        return bits;
    }
    vector<int> evenOddBit(int n)
    {
        int even = 0, odd = 0;
        vector<int> bits = transToBits(n);
        for (int i = 0; i < bits.size(); i++)
            if (bits[i] == 1)
            {
                if (i % 2 == 1)
                    odd++;
                else
                    even++;
            }
        return {even, odd};
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=1009 lang=cpp
 *
 * [1009] 十进制整数的反码
 */

// @lc code=start
class Solution
{
public:
    int bitwiseComplement(int n)
    {
        // 找到 num 二进制表示最高位的那个 1，其位数为 highBit
        int highBit = 0;
        for (int i = 1; i <= 30; i++)
        {
            if (n >= (1 << i))
                highBit = i;
            else
                break;
        }
        // 遍历 num 的第 0 ~ highBit 个二进制位，将它们依次进行取反
        // 构造掩码 mask = 1 << (highBit + 1)) - 1，它是一个 i+1 位的二进制数，并且每一位都是 1
        // 当 highBit = 30 时，构造掩码 mask 时注意保证不要产生整数溢出
        int mask = (highBit == 30 ? 0x7fffffff : (1 << (highBit + 1)) - 1);
        // 我们将 num 与 mask 进行异或运算，即可得到答案
        return n ^ mask;
    }
};
// @lc code=end

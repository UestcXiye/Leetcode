/*
 * @lc app=leetcode.cn id=476 lang=cpp
 *
 * [476] 数字的补数
 */

// @lc code=start

// 模拟

// class Solution
// {
// private:
//     vector<int> trans(int n)
//     {
//         vector<int> result;
//         while (n > 0)
//         {
//             result.push_back(n % 2);
//             n /= 2;
//         }
//         reverse(result.begin(), result.end());
//         return result;
//     }
//     void reverseBits(vector<int> &bits)
//     {
//         for (int i = 0; i < bits.size(); i++)
//         {
//             if (bits[i] == 1)
//                 bits[i] = 0;
//             else
//                 bits[i] = 1;
//         }
//     }
//     int toNum(vector<int> v)
//     {
//         int n = v.size();
//         int sum = 0;
//         for (int i = 0; i < n; i++)
//             sum += v[i] * pow(2, n - i - 1);
//         return sum;
//     }

// public:
//     int findComplement(int num)
//     {
//         vector<int> bits = trans(num);
//         reverseBits(bits);
//         return toNum(bits);
//     }
// };

// 位运算

class Solution
{
public:
    int findComplement(int num)
    {
        // 找到 num 二进制表示最高位的那个 1，其位数为 highBit
        int highBit = 0;
        for (int i = 1; i <= 30; i++)
        {
            if (num >= (1 << i))
                highBit = i;
            else
                break;
        }
        // 遍历 num 的第 0 ~ highBit 个二进制位，将它们依次进行取反
        // 构造掩码 mask = 1 << (highBit + 1)) - 1，它是一个 i+1 位的二进制数，并且每一位都是 1
        // 当 highBit = 30 时，构造掩码 mask 时注意保证不要产生整数溢出
        int mask = (highBit == 30 ? 0x7fffffff : (1 << (highBit + 1)) - 1);
        // 我们将 num 与 mask 进行异或运算，即可得到答案
        return num ^ mask;
    }
};

// @lc code=end

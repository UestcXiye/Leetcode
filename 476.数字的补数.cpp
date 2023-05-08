/*
 * @lc app=leetcode.cn id=476 lang=cpp
 *
 * [476] 数字的补数
 */

// @lc code=start
class Solution
{
    vector<int> trans(int n)
    {
        vector<int> result;
        while (n > 0)
        {
            result.push_back(n % 2);
            n /= 2;
        }
        reverse(result.begin(), result.end());
        return result;
    }
    void reverseBits(vector<int> &bits)
    {
        for (int i = 0; i < bits.size(); i++)
        {
            if (bits[i] == 1)
                bits[i] = 0;
            else
                bits[i] = 1;
        }
    }

    int toNum(vector<int> v)
    {
        int n = v.size();
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += v[i] * pow(2, n - i - 1);
        return sum;
    }

public:
    int findComplement(int num)
    {
        vector<int> bits = trans(num);
        reverseBits(bits);
        return toNum(bits);
    }
};

// class Solution
// {
// public:
//     int findComplement(int num)
//     {
//         int highbit = 0;
//         for (int i = 1; i <= 30; ++i)
//         {
//             if (num >= (1 << i))
//             {
//                 highbit = i;
//             }
//             else
//             {
//                 break;
//             }
//         }
//         int mask = (highbit == 30 ? 0x7fffffff : (1 << (highbit + 1)) - 1);
//         return num ^ mask;
//     }
// };

// @lc code=end

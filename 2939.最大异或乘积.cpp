/*
 * @lc app=leetcode.cn id=2939 lang=cpp
 *
 * [2939] 最大异或乘积
 */

// @lc code=start
class Solution
{
public:
    int maximumXorProduct(long long a, long long b, int n)
    {
        if (a < b)
        {
            swap(a, b); // 保证 a >= b
        }

        long long mask = (1LL << n) - 1;
        long long ax = a & ~mask; // 第 n 位及其左边，无法被 x 影响，先算出来
        long long bx = b & ~mask;
        a &= mask; // 低于第 n 位，能被 x 影响
        b &= mask;

        long long left = a ^ b;      // 可分配：a XOR x 和 b XOR x 一个是 1 另一个是 0
        long long one = mask ^ left; // 无需分配：a XOR x 和 b XOR x 均为 1
        ax |= one;                   // 先加到异或结果中
        bx |= one;

        // 现在要把 left 分配到 ax 和 bx 中
        // 根据基本不等式（均值定理），分配后应当使 ax 和 bx 尽量接近，乘积才能尽量大
        if (left > 0 && ax == bx)
        {
            // 尽量均匀分配，例如把 1111 分成 1000 和 0111
            long long high_bit = 1LL << (63 - __builtin_clzll(left));
            ax |= high_bit;
            left ^= high_bit;
        }
        // 如果 a & ~mask 更大，则应当全部分给 bx（注意最上面保证了 a>=b）
        bx |= left;

        const long long MOD = 1'000'000'007;
        return ax % MOD * (bx % MOD) % MOD; // 注意不能直接 LL * LL，否则溢出
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=2835 lang=cpp
 *
 * [2835] 使子序列的和等于目标的最少操作次数
 */

// @lc code=start
class Solution
{
public:
    int minOperations(vector<int> &nums, int target)
    {
        // 排除无解的情况
        if (accumulate(nums.begin(), nums.end(), 0LL) < target)
            return -1;
        // nums 从大到小排序
        sort(nums.begin(), nums.end(), greater<int>());
        int step = 0;
        // t 表示比当前二进制位小的所有数之和
        long long t = 0;
        for (int i = 0; i < 32; i++)
        {
            // 如果 target 的第 i 位是 1
            if (target >> i & 01)
            {
                int x = 1 << i;
                // 不断把比当前二进制位小的数加到 t 里
                while (!nums.empty() && nums.back() < x && t < x)
                {
                    t += nums.back();
                    nums.pop_back();
                }
                // 比当前二进制位小的数之和已经大于等于当前二进制位，这一位不用操作
                if (t >= x)
                    t -= x;
                // 刚好找到需要的数，也不用操作
                else if (nums.back() == x)
                    nums.pop_back();
                else
                {
                    // 看下一个更大的数，用它拆出当前二进制位
                    int y = nums.back();
                    nums.pop_back();
                    while (y > x)
                    {
                        y >>= 1;
                        // 注意：只有这里会往 nums 的尾部添加数
                        // 由于添加的数都小于原来的尾部，而且是以递减的顺序添加的
                        // 所以 nums 递减的性质不改变
                        nums.push_back(y);
                        step++;
                    }
                }
            }
        }
        return step;
    }
};
// @lc code=end

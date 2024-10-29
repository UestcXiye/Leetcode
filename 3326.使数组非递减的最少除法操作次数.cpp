/*
 * @lc app=leetcode.cn id=3326 lang=cpp
 *
 * [3326] 使数组非递减的最少除法操作次数
 */

// @lc code=start

// 预处理
const int MX = 1e6 + 1;
int LPF[MX];

auto init = []
{
    for (int i = 2; i < MX; i++)
        if (LPF[i] == 0)
            for (int j = i; j < MX; j += i)
                if (LPF[j] == 0)
                    LPF[j] = i;

    return 0;
}();

class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int ans = 0;

        for (int i = nums.size() - 2; i >= 0; i--)
        {
            if (nums[i] > nums[i + 1])
            {
                nums[i] = LPF[nums[i]];
                if (nums[i] > nums[i + 1])
                    return -1;
                ans++;
            }
        }

        return ans;
    }
};
// @lc code=end

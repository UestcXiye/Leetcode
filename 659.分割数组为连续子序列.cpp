/*
 * @lc app=leetcode.cn id=659 lang=cpp
 *
 * [659] 分割数组为连续子序列
 */

// @lc code=start
class Solution
{
public:
    bool isPossible(vector<int> &nums)
    {
        if (nums.size() < 3)
            return false;
        unordered_map<int, int> numsCount, tailCount;
        // 统计数组 nums 中各元素出现次数
        for (int &num : nums)
            numsCount[num]++;
        // tailCount[i] 表示以 i 结尾的符合条件的子序列个数
        for (int &num : nums)
        {
            if (numsCount[num] == 0)
                continue;
            else if (numsCount[num] > 0 && tailCount[num - 1] > 0)
            {
                // 1. 补充到已有子序列的尾部
                numsCount[num] -= 1;
                tailCount[num - 1] -= 1;
                tailCount[num] += 1;
            }
            else if (numsCount[num] > 0 && numsCount[num + 1] > 0 && numsCount[num + 2] > 0)
            {
                // 2. 新建一条长度为 3 的子序列
                // 注意 1 的优先级比 2 高
                numsCount[num] -= 1;
                numsCount[num + 1] -= 1;
                numsCount[num + 2] -= 1;
                tailCount[num + 2] += 1;
            }
            else
                return false;
        }
        return true;
    }
};
// @lc code=end

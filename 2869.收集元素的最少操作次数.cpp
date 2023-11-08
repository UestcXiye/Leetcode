/*
 * @lc app=leetcode.cn id=2869 lang=cpp
 *
 * [2869] 收集元素的最少操作次数
 */

// @lc code=start
class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        int count = 0;
        unordered_set<int> us;
        while (!nums.empty())
        {
            int num = nums.back();
            nums.pop_back();
            us.insert(num);
            count++;
            bool judge = true;
            for (int i = 1; i <= k; i++)
                if (!us.count(i))
                    judge = false;
            if (judge)
                break;
        }
        return count;
    }
};
// @lc code=end

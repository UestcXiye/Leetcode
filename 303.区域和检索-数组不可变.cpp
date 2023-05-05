/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 */

// @lc code=start
class NumArray
{
public:
    vector<int> v;
    vector<int> sums;
    NumArray(vector<int> &nums)
    {
        v = nums;
        int n = nums.size();
        sums.resize(n + 1);
        for (int i = 0; i < n; i++)
        {
            sums[i + 1] = sums[i] + nums[i];
        }
    }

    int sumRange(int left, int right)
    {
        return sums[right + 1] - sums[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end

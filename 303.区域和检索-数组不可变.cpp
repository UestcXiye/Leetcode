/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 */

// @lc code=start

// 前缀和

class NumArray
{
private:
    vector<int> pSum;

public:
    NumArray(vector<int> nums) : pSum(nums.size() + 1, 0)
    {
        partial_sum(nums.begin(), nums.end(), pSum.begin() + 1);
    }

    int sumRange(int i, int j)
    {
        return pSum[j + 1] - pSum[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end

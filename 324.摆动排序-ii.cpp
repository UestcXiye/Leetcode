/*
 * @lc app=leetcode.cn id=324 lang=cpp
 *
 * [324] 摆动排序 II
 */

// @lc code=start
class Solution
{
public:
    void wiggleSort(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> arr = nums;
        ranges::sort(arr);
        int x = (n + 1) / 2;
        // 逆序插入
        // i 为插入下标，j 为波谷下标，k 为波峰下标
        for (int i = 0, j = x - 1, k = n - 1; i < n; i += 2, j--, k--)
        {
            nums[i] = arr[j];
            if (i + 1 < n)
                nums[i + 1] = arr[k];
        }
    }
};
// @lc code=end

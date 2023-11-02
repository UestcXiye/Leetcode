/*
 * @lc app=leetcode.cn id=1013 lang=cpp
 *
 * [1013] 将数组分成和相等的三个部分
 */

// @lc code=start
class Solution
{
public:
    bool canThreePartsEqualSum(vector<int> &arr)
    {
        int arrSum = accumulate(arr.begin(), arr.end(), 0);
        if (arrSum % 3 != 0)
            return false;
        int target = arrSum / 3;
        int n = arr.size(), sum = 0, i = 0;
        while (i < n)
        {
            sum += arr[i];
            if (sum == target)
                break;
            i++;
        }
        if (sum != target || i >= n - 2)
            return false;
        int j = i + 1;
        sum = 0;
        while (j < n)
        {
            sum += arr[j];
            if (sum == target)
                break;
            j++;
        }
        if (j >= n - 1)
            return false;
        return true;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=2574 lang=cpp
 *
 * [2574] 左右元素和的差值
 */

// @lc code=start
class Solution
{
public:
    vector<int> leftRigthDifference(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> leftSum(n);
        vector<int> rightSum(n);
        leftSum[0] = 0;
        for (int i = 1; i < n; i++)
            leftSum[i] = leftSum[i - 1] + nums[i - 1];
        // for (int i = 0; i < n; i++)
        //     cout << leftSum[i] << " ";
        // cout << endl;
        rightSum[n - 1] = 0;
        for (int i = n - 2; i >= 0; i--)
            rightSum[i] = rightSum[i + 1] + nums[i + 1];
        // for (int i = 0; i < n; i++)
        //     cout << rightSum[i] << " ";
        // cout << endl;
        vector<int> answer(n);
        for (int i = 0; i < n; i++)
            answer[i] = abs(leftSum[i] - rightSum[i]);
        return answer;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=989 lang=cpp
 *
 * [989] 数组形式的整数加法
 */

// @lc code=start
// class Solution
// {
// public:
//     vector<int> addToArrayForm(vector<int> &num, int k)
//     {
//         long long sum = 0;
//         for (int i = 0; i < num.size(); i++)
//         {
//             sum *= 10;
//             sum += num[i];
//         }
//         sum += k;
//         vector<int> ans;
//         while (sum)
//         {
//             ans.push_back(sum % 10);
//             sum /= 10;
//         }
//         reverse(ans.begin(), ans.end());
//         return ans;
//     }
// };
class Solution
{
public:
    vector<int> addToArrayForm(vector<int> &num, int k)
    {
        vector<int> res;
        int n = num.size();
        for (int i = n - 1; i >= 0; i--)
        {
            int sum = num[i] + k % 10;
            k /= 10;
            if (sum >= 10)
            {
                k++;
                sum -= 10;
            }
            res.push_back(sum);
        }
        while (k)
        {
            res.push_back(k % 10);
            k /= 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

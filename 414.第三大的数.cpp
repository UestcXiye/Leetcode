/*
 * @lc app=leetcode.cn id=414 lang=cpp
 *
 * [414] 第三大的数
 */

// @lc code=start
class Solution
{
public:
    int thirdMax(vector<int> &nums)
    {
        set<int> s;
        for (int i = 0; i < nums.size(); i++)
            s.insert(nums[i]);
        set<int>::iterator it = s.end();
        if (s.size() < 3)
            it--;
        else
        {
            it--;
            it--;
            it--;
        }
        return *it;
    }
};

// class Solution
// {
// public:
//     int thirdMax(vector<int> &nums)
//     {
//         sort(nums.begin(), nums.end(), greater<>());
//         for (int i = 1, diff = 1; i < nums.size(); ++i)
//         {
//             if (nums[i] != nums[i - 1] && ++diff == 3)
//             { // 此时 nums[i] 就是第三大的数
//                 return nums[i];
//             }
//         }
//         return nums[0];
//     }
// };
// @lc code=end

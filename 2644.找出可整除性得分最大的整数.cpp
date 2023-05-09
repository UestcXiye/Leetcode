/*
 * @lc app=leetcode.cn id=2644 lang=cpp
 *
 * [2644] 找出可整除性得分最大的整数
 */

// @lc code=start
// class Solution
// {
// public:
//     int maxDivScore(vector<int> &nums, vector<int> &divisors)
//     {
//         int n = divisors.size();
//         int maxScore = 0;
//         vector<int> scores(n);
//         for (int i = 0; i < n; i++)
//         {
//             int score = 0;
//             for (int num : nums)
//                 if (num % divisors[i] == 0)
//                     score++;
//             scores[i] = score;
//             maxScore = max(maxScore, score);
//         }
//         int ans = __INT_MAX__;
//         for (int i = 0; i < n; i++)
//             if (scores[i] == maxScore)
//                 ans = min(ans, divisors[i]);
//         return ans;
//     }
// };

class Solution
{
public:
    int maxDivScore(vector<int> &nums, vector<int> &divisors)
    {
        int n = divisors.size();
        int maxScore = 0;
        int ans = __INT_MAX__;
        for (int i = 0; i < n; i++)
        {
            int score = 0;
            for (int num : nums)
                if (num % divisors[i] == 0)
                    score++;
            if (score > maxScore)
                ans = divisors[i];
            else if (score == maxScore)
                ans = min(divisors[i], ans);
            maxScore = max(maxScore, score);
        }
        return ans;
    }
};
// @lc code=end

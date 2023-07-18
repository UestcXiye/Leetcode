/*
 * @lc app=leetcode.cn id=2748 lang=cpp
 *
 * [2748] 美丽下标对的数目
 */

// @lc code=start
class Solution
{
private:
    int gcd(int x, int y)
    {
        for (int i = min(x, y); i >= 1; i--)
            if (x % i == 0 && y % i == 0)
                return i;
        return 1;
    }

public:
    int countBeautifulPairs(vector<int> &nums)
    {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n - 1; i++)
            for (int j = i + 1; j < n; j++)
            {
                int num_i = nums[i], index_i;
                while (num_i)
                {
                    index_i = num_i % 10;
                    num_i /= 10;
                }
                int index_j = nums[j] % 10;
                if (gcd(index_i, index_j) == 1)
                    ans++;
            }
        return ans;
    }
};
// @lc code=end

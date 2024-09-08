/*
 * @lc app=leetcode.cn id=3267 lang=cpp
 *
 * [3267] 统计近似相等数对 II
 */

// @lc code=start
class Solution
{
public:
    int countPairs(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        unordered_map<int, int> cnt;
        int ans = 0;
        for (int &x : nums)
        {
            unordered_set<int> st = {x}; // 不交换
            string s = to_string(x);
            int m = s.length();
            for (int i = 0; i < m; i++)
            {
                for (int j = i + 1; j < m; j++)
                {
                    swap(s[i], s[j]);
                    st.insert(stoi(s)); // 交换一次
                    for (int p = i + 1; p < m; p++)
                    {
                        for (int q = p + 1; q < m; q++)
                        {
                            swap(s[p], s[q]);
                            st.insert(stoi(s)); // 交换两次
                            swap(s[p], s[q]);
                        }
                    }
                    swap(s[i], s[j]);
                }
            }
            for (int v : st)
            {
                ans += cnt.contains(v) ? cnt[v] : 0;
            }
            cnt[x]++;
        }
        return ans;
    }
};
// @lc code=end

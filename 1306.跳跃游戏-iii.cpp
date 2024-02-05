/*
 * @lc app=leetcode.cn id=1306 lang=cpp
 *
 * [1306] 跳跃游戏 III
 */

// @lc code=start

// 广度优先搜索

class Solution
{
public:
    bool canReach(vector<int> &arr, int start)
    {
        // 特判
        if (arr[start] == 0)
            return true;

        int n = arr.size();
        vector<bool> visited(n);
        queue<int> q;
        q.push(start);
        visited[start] = true;

        while (!q.empty())
        {
            // 当前下标 i
            int i = q.front();
            q.pop();

            // 往左走
            int left = i - arr[i];
            if (left >= 0 && !visited[left])
            {
                if (arr[left] == 0) // 跳到对应元素值为 0
                    return true;
                q.push(left);
                visited[left] = true;
            }
            // 往右走
            int right = i + arr[i];
            if (right < n && !visited[right])
            {
                if (arr[right] == 0) // 跳到对应元素值为 0
                    return true;
                q.push(right);
                visited[right] = true;
            }
        }
        return false;
    }
};
// @lc code=end

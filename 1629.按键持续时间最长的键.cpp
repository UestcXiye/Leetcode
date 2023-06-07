/*
 * @lc app=leetcode.cn id=1629 lang=cpp
 *
 * [1629] 按键持续时间最长的键
 */

// @lc code=start
class Solution
{
public:
    char slowestKey(vector<int> &releaseTimes, string keysPressed)
    {
        int n = releaseTimes.size();
        int maxPressedTime = releaseTimes[0];
        char ans = keysPressed[0];
        for (int i = 1; i < n; i++)
        {
            int pressedTime = releaseTimes[i] - releaseTimes[i - 1];
            if (pressedTime > maxPressedTime)
            {
                maxPressedTime = pressedTime;
                ans = keysPressed[i];
            }
            else if (pressedTime == maxPressedTime && keysPressed[i] > ans)
                ans = keysPressed[i];
        }
        return ans;
    }
};
// @lc code=end

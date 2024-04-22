/*
 * @lc app=leetcode.cn id=1311 lang=cpp
 *
 * [1311] 获取你好友已观看的视频
 */

// @lc code=start

using PSI = pair<string, int>;

class Solution
{
public:
    vector<string> watchedVideosByFriends(vector<vector<string>> &watchedVideos, vector<vector<int>> &friends, int id, int level)
    {
        int n = friends.size();
        // 1. BFS 找出所有 Level k 的好友
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(id);
        visited[id] = true;
        while (level--)
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                int u = q.front();
                q.pop();
                for (int &v : friends[u])
                    if (!visited[v])
                    {
                        q.push(v);
                        visited[v] = true;
                    }
            }
        }
        // 2. 统计好友观看过的视频
        unordered_map<string, int> freq;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (string &watchedVideo : watchedVideos[u])
                freq[watchedVideo]++;
        }
        // 3. 将视频按照要求排序
        vector<PSI> videos(freq.begin(), freq.end());
        sort(videos.begin(), videos.end(),
             [](const PSI &v1, const PSI &v2)
             {
                 if (v1.second != v2.second)
                     return v1.second < v2.second;
                 else
                     return v1.first < v2.first;
             });

        vector<string> ans;
        for (PSI &video : videos)
            ans.push_back(video.first);
        return ans;
    }
};
// @lc code=end

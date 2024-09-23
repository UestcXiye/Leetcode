#
# @lc app=leetcode.cn id=3286 lang=python3
#
# [3286] 穿越网格图的安全路径
#

# @lc code=start
class Solution:
    def findSafeWalk(self, grid: List[List[int]], health: int) -> bool:
        m, n = len(grid), len(grid[0])

        vis = [[False] * n for _ in range(m)]
        vis[0][0] = True

        dx = [0, 1, 0, -1]
        dy = [1, 0, -1, 0]

        @cache
        def dfs(x: int, y: int, h: int) -> bool:
            if h <= 0:
                return False
            if x == m - 1 and y == n - 1 and h > 0:
                return True
            
            for i in range(4):
                nx = x + dx[i]
                ny = y + dy[i]
                if nx >= 0 and nx < m and ny >= 0 and ny < n and vis[nx][ny] == False:
                    vis[nx][ny] = True
                    if dfs(nx, ny, h - grid[nx][ny]):
                        return True
                    vis[nx][ny] = False
            return False

        return dfs(0, 0, health - grid[0][0])
# @lc code=end


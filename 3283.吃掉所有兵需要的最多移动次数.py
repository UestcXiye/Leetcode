#
# @lc app=leetcode.cn id=3283 lang=python3
#
# [3283] 吃掉所有兵需要的最多移动次数
#

# @lc code=start
DIRS = ((2, 1), (1, 2), (-1, 2), (-2, 1), (-2, -1), (-1, -2), (1, -2), (2, -1))

class Solution:
    def maxMoves(self, kx: int, ky: int, positions: List[List[int]]) -> int:
        n = len(positions)
        # 计算马到兵的步数，等价于计算兵到其余格子的步数
        dis = [[[-1] * 50 for _ in range(50)] for _ in range(n)]
        for d, (px, py) in zip(dis, positions):
            d[px][py] = 0
            q = [(px, py)]
            step = 1
            while q:
                tmp = q
                q = []
                for p in tmp:
                    for dx, dy in DIRS:
                        x, y = p[0] + dx, p[1] + dy
                        if 0 <= x < 50 and 0 <= y < 50 and d[x][y] < 0:
                            d[x][y] = step
                            q.append((x, y))
                step += 1

        positions.append((kx, ky))
        u = (1 << n) - 1

        @cache
        def dfs(i: int, mask: int) -> int:
            if mask == 0:
                return 0
            odd = (u ^ mask).bit_count() % 2
            res = inf if odd else 0
            x, y = positions[i]
            for j, d in enumerate(dis):
                if mask >> j & 1:
                    if odd:
                        # Bob
                        res = min(res, dfs(j, mask ^ (1 << j)) + d[x][y])
                    else:
                        # Alice
                        res = max(res, dfs(j, mask ^ (1 << j)) + d[x][y])
            return res
        return dfs(n, u)
# @lc code=end


--
-- @lc app=leetcode.cn id=610 lang=mysql
--
-- [610] 判断三角形
--

-- @lc code=start
# Write your MySQL query statement below
SELECT x, y, z,
CASE
    WHEN x + y > z AND x + z > y AND y + z > x THEN 'Yes' ELSE 'No'
END AS triangle
FROM Triangle;
-- @lc code=end


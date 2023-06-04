--
-- @lc app=leetcode.cn id=1667 lang=mysql
--
-- [1667] 修复表中的名字
--

-- @lc code=start
# Write your MySQL query statement below
SELECT user_id,
CONCAT(Upper(left(name, 1)), Lower(substring(name, 2))) AS name 
FROM users 
ORDER BY user_id
-- @lc code=end


--
-- @lc app=leetcode.cn id=1251 lang=mysql
--
-- [1251] 平均售价
--

-- @lc code=start
# Write your MySQL query statement below
-- average_price 应该四舍五入到小数点后两位
SELECT
    product_id,
    ROUND(SUM(sales) / SUM(units), 2) AS average_price
FROM (
    SELECT
        Prices.product_id AS product_id,
        Prices.price * UnitsSold.units AS sales,
        UnitsSold.units AS units
    FROM
        Prices JOIN UnitsSold
    ON
        Prices.product_id = UnitsSold.product_id
    WHERE
        UnitsSold.purchase_date BETWEEN Prices.start_date AND Prices.end_date
    ) AS t
GROUP BY product_id;

-- @lc code=end


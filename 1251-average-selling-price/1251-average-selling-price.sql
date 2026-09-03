# Write your MySQL query statement below
select p.product_id , COALESCE(ROUND(SUM(p.price * u.units) / SUM(u.units), 2), 0)
as average_price
FROM Prices p
LEFT JOIN UnitsSold u
    ON p.product_id = u.product_id
   AND u.purchase_date <= p.end_date and u.purchase_date >= p.start_date
   
GROUP BY p.product_id;

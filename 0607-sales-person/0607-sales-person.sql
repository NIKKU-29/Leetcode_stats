-- Write your PostgreSQL query statement below
SELECT name 
FROM SalesPerson
WHERE sales_id NOT IN (
    SELECT sales_id 
    FROM Orders o 
    JOIN Company c ON o.com_id = c.com_id AND c.name = 'RED'
)
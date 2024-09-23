SELECT s.user_id,
         ROUND(ifnull(avg(action='confirmed'),0),2) as confirmation_rate
FROM Signups s
LEFT JOIN Confirmations c 
ON s.user_id = c.user_id
GROUP BY s.user_id;





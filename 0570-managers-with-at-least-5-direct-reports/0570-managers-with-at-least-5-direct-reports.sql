# Write your MySQL query statement below
Select e.name
from Employee as e
JOIN Employee as m on e.id=m.managerId
group by m.managerId
having count(*) > 4 

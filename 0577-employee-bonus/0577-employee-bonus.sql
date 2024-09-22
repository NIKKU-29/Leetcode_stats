# Write your MySQL query statement below
select e.name , b.bonus
from Employee as e
Left Join Bonus as b on e.empID=b.empID
where b.bonus < 1000 or b.bonus is null
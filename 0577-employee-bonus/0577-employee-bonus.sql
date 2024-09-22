# Write your MySQL query statement below
select name , bonus
from Employee
Left Join Bonus on Employee.empID=Bonus.empID
where bonus < 1000 or bonus is null
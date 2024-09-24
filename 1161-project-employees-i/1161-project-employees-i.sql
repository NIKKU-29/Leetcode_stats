# Write your MySQL query statement below
select project_id , round(avg(e.experience_years),2) as average_years
from project p
Left join Employee e
on p.employee_id=e.employee_id
group by project_id

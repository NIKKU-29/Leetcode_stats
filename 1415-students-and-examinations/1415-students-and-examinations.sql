select s.student_id,s.student_name,sub.subject_name,count(e.subject_name) as attended_exams
from Students as s
cross join subjects as sub
Left Join Examinations as e
on s.student_id=e.student_id and sub.subject_name = e.subject_name
group by student_id,student_name,subject_name
order by s.student_id ,sub.subject_name;
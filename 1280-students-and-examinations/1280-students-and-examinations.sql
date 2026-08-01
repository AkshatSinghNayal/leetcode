# Write your MySQL query statement below
select  stu.student_id , stu.student_name,  sub.subject_name, count(ex.student_id) as attended_exams
from Students as stu
cross join Subjects as sub
left join Examinations as ex 
on stu.student_id = ex.student_id and sub.subject_name = ex.subject_name
group by sub.subject_name , stu.student_id , stu.student_name
ORDER BY stu.student_id, sub.subject_name;
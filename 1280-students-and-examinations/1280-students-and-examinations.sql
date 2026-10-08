select stu.student_id, stu.student_name, sub.subject_name, count(ex.subject_name) as attended_exams
from Students as stu
cross join Subjects as sub
left join Examinations as ex
on stu.student_id = ex.student_id and sub.subject_name = ex.subject_name
-- where ex.student_id is not null or ex.subject_name is not null
group by stu.student_id,stu.student_name,sub.subject_name
order by stu.student_id,sub.subject_name

# Write your MySQL query statement below
select machine_id ,  round((sum(case when activity_type = 'start' then -timestamp else timestamp end))*1.0/count(Distinct process_id),3) as processing_time
    
from Activity
group by machine_id
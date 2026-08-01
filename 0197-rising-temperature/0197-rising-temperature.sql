# Write your MySQL query statement below
select w2.id 
from Weather as w1
left join Weather as w2
on DATEDIFF(w2.recordDate, w1.recordDate) = 1 and w2.temperature > w1.temperature 
where  w2.id is not null;
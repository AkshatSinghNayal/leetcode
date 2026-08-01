# Write your MySQL query statement below
select e.customer_id, count( e.customer_id ) as count_no_trans
from Visits as e 
left join Transactions as u 
on e.visit_id = u.visit_id
where u.amount is null 
group by e.customer_id
order by count_no_trans asc;
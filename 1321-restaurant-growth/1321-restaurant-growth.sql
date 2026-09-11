select c1.visited_on , sum(c2.amount) as amount , round(sum(c2.amount)/7,2) as average_amount
from (
    select visited_on , sum(amount) as amount 
    from Customer
    group by visited_on
) as c1

inner join (
    select visited_on , sum(amount) as amount 
    from Customer
    group by visited_on
) as c2 

on c2.visited_on between c1.visited_on - interval 6 day and c1.visited_on 
group by c1.visited_on
having count(*)= 7
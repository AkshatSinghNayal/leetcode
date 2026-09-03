select r.contest_id , round(count(*)/(select count(*) from Users)*100,2) as percentage
from Users as u
left join Register as r
on u.user_id = r.user_id
group by r.contest_id
having r.contest_id is not null
order by percentage  desc , r.contest_id  asc
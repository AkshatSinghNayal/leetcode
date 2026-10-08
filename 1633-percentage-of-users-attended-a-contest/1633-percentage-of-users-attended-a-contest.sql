SELECT r.contest_id, round((count(*)/( select count(*) from Users))*100,2) as percentage
from Register as r
group by contest_id
order by percentage desc, r.contest_id asc
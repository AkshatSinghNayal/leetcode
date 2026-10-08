select m.name
from Employee as m
join Employee as e
on m.id = e.managerId
group by e.managerId
having count(e.managerId)>=5
order by m.id
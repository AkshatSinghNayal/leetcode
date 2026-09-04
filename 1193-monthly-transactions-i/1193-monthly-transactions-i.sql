select DATE_FORMAT(T.trans_date, '%Y-%m') as month , T.country, count(*) as trans_count, 
sum( case when state ='approved' then 1 else 0 end ) as approved_count,
sum( T.amount) as trans_total_amount,
sum(case when state = 'approved' then T.amount else 0 end) as approved_total_amount

from Transactions as T
group by T.country, DATE_FORMAT(T.trans_date, '%Y-%m')
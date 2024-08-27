select 
distinct(vi.customer_id) as customer_id,
count(vi.visit_id) as count_no_trans
from Visits vi  
left join 
Transactions ti 
on vi.visit_id = ti.visit_id
where ti.transaction_id is null group by vi.customer_id

# Write your MySQL query statement below

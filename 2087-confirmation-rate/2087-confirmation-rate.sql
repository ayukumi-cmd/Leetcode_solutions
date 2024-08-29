# Write your MySQL query statement below
Select s.user_id ,
 IFNULL(round(sum(action='confirmed')/
 count(s.user_id), 2) , 0.00) 
 confirmation_rate 
from Signups s
left join Confirmations c
on s.user_id= c.user_id 
group by s.user_id
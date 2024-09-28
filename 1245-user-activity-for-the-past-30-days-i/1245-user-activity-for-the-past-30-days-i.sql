# Write your MySQL query statement below


with  active as(
    select 
       count(distinct user_id) as active_users , 
       activity_date  as day
       from Activity 
     where  activity_date BETWEEN '2019-06-28' AND '2019-07-27'
     group by  activity_date
)
select a.day as day, a.active_users as active_users from active as a; 

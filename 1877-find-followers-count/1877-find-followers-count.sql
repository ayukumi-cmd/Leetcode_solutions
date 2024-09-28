# Write your MySQL query statement below
with follow  as(
    select 
    distinct( user_id) as uses,
    count(follower_id) as followed_by 
    from Followers
    group by uses

)

select u.uses as user_id , u.followed_by as followers_count 
from follow as u group by user_id order by user_id asc
# Write your MySQL query statement below
with solve as (
    select 
        teacher_id as teach, 
        count(distinct(subject_id)) as cnt 
        from  Teacher 
        group by teacher_id
        order by teacher_id 
)
select s.teach as teacher_id , s.cnt as cnt from solve as s 


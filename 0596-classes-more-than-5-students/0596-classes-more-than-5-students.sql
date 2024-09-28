with classes_5  as(
    select distinct(class) as cl,
    count(class) as cnt from Courses 
    group by cl 
)

select c.cl as class from classes_5 as c
 where c.cnt>4
 group by class
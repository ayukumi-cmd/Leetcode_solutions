# Write your MySQL query statement below


with pr as (
    select 
          customer_id as cd,
          count(distinct(product_key)) as cnt 
          from Customer
          group by cd 
          order by cd
)

select p.cd as customer_id from pr as p 
            where  p.cnt in (select count(product_key) from Product)

       
# Write your MySQL query statement below
SELECT p.project_id , round(AVG(e.experience_years),2) as average_years from Project p left join Employee e on e.employee_id=p.employee_id
group by p.project_id
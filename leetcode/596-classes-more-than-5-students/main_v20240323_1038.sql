# Write your MySQL query statement below
select t1.class
from (
  select class, count(1) as student_cnt 
  from Courses 
  group by class
) as t1 
where t1.student_cnt >= 5



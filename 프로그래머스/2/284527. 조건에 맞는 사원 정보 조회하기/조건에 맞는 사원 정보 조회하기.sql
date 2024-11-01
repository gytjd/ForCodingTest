-- 코드를 작성해주세요

select sum(g.score) as score,h.emp_no,h.emp_name,h.position,h.email from hr_employees h join hr_grade g on h.emp_no=g.emp_no group by h.emp_no order by score desc limit 1
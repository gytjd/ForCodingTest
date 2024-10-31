-- 코드를 작성해주세요
select h.dept_id,h.dept_name_en,j.temp as AVG_SAL from hr_department h join (select dept_id,round(sum(sal)/count(dept_id)) as temp from hr_employees group by dept_id) j on h.dept_id=j.dept_id
order by AVG_SAL desc
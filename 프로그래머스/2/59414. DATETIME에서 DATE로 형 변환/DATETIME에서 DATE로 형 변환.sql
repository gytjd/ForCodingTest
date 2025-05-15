-- 코드를 입력하세요

select i.animal_id,i.name,date_format(i.datetime,"%Y-%m-%d") as 날짜 from animal_ins i order by i.animal_id
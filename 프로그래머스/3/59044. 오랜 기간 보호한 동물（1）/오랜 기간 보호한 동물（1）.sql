-- 코드를 입력하세요
select i.name,i.datetime from animal_ins i where i.animal_id not in (select o.animal_id from animal_outs o) order by i.datetime limit 3

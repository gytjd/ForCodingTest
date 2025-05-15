-- 코드를 입력하세요
SELECT i.animal_type as ANIMAL_TYPE,case when i.name is null then "No name" else i.name end as NAME,i.sex_upon_intake as SEX_UPON_INTAKE from animal_ins i
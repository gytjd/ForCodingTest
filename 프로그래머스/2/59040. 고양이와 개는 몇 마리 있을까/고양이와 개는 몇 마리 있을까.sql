-- 코드를 입력하세요
SELECT animal_type as ANIMAL_TYPE,count(ANIMAL_TYPE) as count FROM ANIMAL_INS GROUP BY ANIMAL_TYPE
order by animal_type asc
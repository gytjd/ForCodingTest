-- 코드를 입력하세요
select member_id as MEMBER_ID,member_name as MEMBER_NAME,gender as GENDER,date_format(date_of_birth,"%Y-%m-%d") as DATE_OF_BIRTH from member_profile where month(date_of_birth)="03" and tlno is not null and gender="W"
order by member_id
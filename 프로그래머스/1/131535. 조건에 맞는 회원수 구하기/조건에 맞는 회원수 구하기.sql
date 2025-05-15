-- 코드를 입력하세요
SELECT count(*) as USERS from user_info u where YEAR(u.joined)=2021 and u.age between 20 and 29
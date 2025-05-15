-- 코드를 작성해주세요
select count(*) as FISH_COUNT,n.fish_name as FISH_NAME from fish_info f join fish_name_info n on f.fish_type=n.fish_type
group by n.fish_name order by FISH_COUNT desc
SELECT count(*) as fish_count
FROM fish_info AS F 
JOIN fish_name_info AS N ON F.fish_type = N.fish_type
where N.fish_Name='BASS' or N.fish_Name='SNAPPER'
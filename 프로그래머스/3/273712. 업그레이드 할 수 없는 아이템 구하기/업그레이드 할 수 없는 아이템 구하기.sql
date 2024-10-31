-- 코드를 작성해주세요

select i.item_id,i.item_name,i.rarity from item_info i where i.item_id not in (select t.parent_item_id from item_tree t where t.parent_item_id is not null group by t.parent_item_id) order by i.item_id desc
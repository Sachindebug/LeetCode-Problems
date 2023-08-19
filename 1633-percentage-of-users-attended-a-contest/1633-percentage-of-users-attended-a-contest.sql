select R.contest_id, round((count(R.user_id)*100) / (select count(user_id) from Users), 2) as percentage
from Users U
inner join Register R
on U.user_id=R.user_id
group by contest_id
order by percentage desc, contest_id;
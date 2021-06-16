USE PUBS;

-- a) SELECT au_fname, au_lname FROM AUTHORS;
-- b) SELECT au_fname, au_lname, phone FROM AUTHORS;
-- c) SELECT au_fname as first_name, au_lname as last_name, phone as telephone FROM AUTHORS ORDER BY au_fname,au_lname ASC;
/* e)
SELECT au_fname as first_name, au_lname as last_name, phone as telephone 
FROM AUTHORS
WHERE state LIKE 'CA' and au_lname NOT LIKE 'Ringer'
ORDER BY au_fname,au_lname ASC;*/
/* f)
SELECT * FROM publishers
WHERE pub_name LIKE '%Bo%';
*/
/*  g)
SELECT DISTINCT pub_name FROM publishers JOIN titles ON publishers.pub_id=titles.pub_id
WHERE type like 'business';
*/
/* h)
select pub_name, SUM(qty) as booksSold
from (publishers join titles on publishers.pub_id=titles.pub_id) join sales on titles.title_id=sales.title_id
GROUP BY pub_name;
*/

/* i)
select pub_name,titles.title, SUM(qty) as booksSold
from (publishers join titles on publishers.pub_id=titles.pub_id) join sales on titles.title_id=sales.title_id
GROUP BY pub_name,titles.title;
*/

/* j)
Select title, stor_name
from (sales join titles on sales.title_id=titles.title_id) join stores on sales.stor_id=stores.stor_id
where stor_name like 'bookbeat';
*/

/* k)
select au_fname , au_lname, Count(Distinct type) as #oftypes
from (authors join titleauthor on authors.au_id=titleauthor.au_id) join titles on titles.title_id=titleauthor.title_id
Group by au_fname, au_lname
having Count(Distinct type) > 1
order by au_fname, au_lname ASC;
*/

/*l
select publishers.pub_id, titles.type, AVG(price) as AVGPRICE, SUM(qty) as #total
from (publishers join titles on publishers.pub_id=titles.pub_id) join sales on titles.title_id=sales.title_id
GROUP BY publishers.pub_id, titles.type;

m)
select titles.type
from titles join (select type,AVG(advance) AS average from titles GROUP BY type) AS tmp ON titles.type=tmp.type  
where advance > 1.5 * tmp.average 

n)
select title, au_fname, au_lname, (royaltyper/100.0)*(royalty/100.0)*ytd_sales*price as valor_arrecadado
 from (titles join titleauthor on titles.title_id=titleauthor.title_id) join authors on titleauthor.au_id=authors.au_id

o)
select distinct title, ytd_sales, ytd_sales*price as facturacao, 
				(ytd_sales*price) * (royalty*0.01) as auths_revenue, 
				ytd_sales*price - royalty*0.01 * ytd_sales*price as publisher_revenue 
from titles
where ytd_sales > 0  

p)
select distinct title, ytd_sales, CONCAT( au_fname, ' ', au_lname) as name, 
				(ytd_sales * price)  as auths_revenue, 
				ytd_sales*price - royalty*0.01 * ytd_sales*price as publisher_revenue 
from (titles join titleauthor on titles.title_id=titleauthor.title_id) join authors on titleauthor.au_id=authors.au_id
where ytd_sales > 0  

q)
select stor_name from (stores JOIN sales ON stores.stor_id=sales.stor_id) --not finished

r)
select stor_name from 
(select avg(qty) as all_average from stores join sales on sales.stor_id=stores.stor_id) as average_all
join 
(select stor_name, avg(qty) as average_single from stores join sales on sales.stor_id=stores.stor_id
group by stor_name) as average_single
on average_single > all_average

s)
select title 
from titles 
where title_id not in 
	(select title_id from sales join stores on sales.stor_id=stores.stor_id 
	where stor_name='Bookbeat');
*/
--t) 
select pub_name, stor_name from stores, publishers 
except (select pub_name, stores.stor_id
		from (((stores join sales on stores.stor_id=sales.stor_id) join 
		titles on sales.title_id=titles.title_id) join 
		publishers on titles.pub_id=publishers.pub_id)
		group by pub_name, stores.stor_id)





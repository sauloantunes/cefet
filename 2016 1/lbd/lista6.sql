-- Lista 6
-- Ana Cláudia e Saulo Antunes

-- 1) Apresente o nome do cliente e o total de compras para cada cliente.

select c.name, sum(o.total) total
from customer c, ord o
where c.custid = o.custid
group by c.name;

name											total 
-----------------------------------------------------
EVERY MOUNTAIN									7160.8
VOLLYRITE										27775.5
JUST TENNIS										764
WOMENS SPORTS									710
K + T SPORTS									46370
NORTH WOODS HEALTH AND FITNESS SUPPLY CENTER	6400
TKB SPORT SHOP									101.4
SHAPE UP										9024.4
JOCKSPORTS										5280.9

-- 2) Liste os produtos que nunca foram pedidos.

select prodid, descrip
from product 
where prodid not in (select prodid from item);

prodid	descrip
---------------
22200	PLUS TENNIS RACKET
22201	PLUS TENNIS BALLS

-- 3) Exiba cada produto pedido e o seu preço médio (média de ITEM.ACTUALPRICE).

select p.descrip, round(sum(i.itemtot) / sum(i.qty), 2) media
from item i, product p
where i.prodid = p.prodid
group by p.descrip;

descrip						media
---------------------------------
SB ENERGY BAR-6 PACK		2.37
SP JUNIOR RACKET			10.89
RH: GUIDE TO TENNIS			3.4
ACE TENNIS BALLS-6 PACK		5.58
ACE TENNIS BALLS-3 PACK		2.98
SB VITA SNACK-6 PACK		4
ACE TENNIS NET				57.98
ACE TENNIS RACKET II		44.66
SP TENNIS RACKET			24
ACE TENNIS RACKET I			34.49

-- 4) Liste o total de vendas (soma de ORD.TOTAL) por empregado.

select E.EMPNO, E.ENAME, sum (O.TOTAL) total
from EMP E, CUSTOMER C, ORD O
where E.EMPNO = C.REPID and C.CUSTID = O.CUSTID
group by E.ENAME, E.EMPNO;

empno 	ename 	total 
---------------------
7844	TURNER	58050.9
7521	WARD	9889.8
7654	MARTIN	27775.5
7499	ALLEN	7870.8

-- 5) Apresente o total (soma de ORD.TOTAL) e a média (média de ORD.TOTAL) de vendas por cidade.

select c.city, sum(o.total) soma, avg(o.total) media
from customer c, ord o
where c.custid = o.custid
group by c.city;

city 				soma 		media
-------------------------------------
BURLINGAME			28539.5		4756.583333333333333333333333333333333333
CUPERTINO			7160.8		1790.2
BELMONT				5280.9		1320.225
REDWOOD CITY		101.4		101.4
SANTA CLARA			46370		46370
PALO ALTO			9024.4		3008.133333333333333333333333333333333333
HIBBING				6400		6400
SUNNYVALE			710			710

-- 6) Identifique o produto mais vendido (ou seja, maior soma de quantidade de itens), apresentando a quantidade de vezes que ele foi pedido.

select I.PRODID, sum (I.QTY) soma
from ITEM I
group by I.PRODID
having sum (I.QTY) = (select max(soma_qty)
                      from (select I.PRODID, sum (I.QTY) soma_qty
                            from ITEM I
                            group by I.PRODID));

prodid 	soma
------------ 
100870	2288

-- 7) Exiba o pedido com mais itens (contar os itens), apresentando essa quantidade de itens.

select o.ordid, count(i.itemid) itens
from ord o, item i 
where o.ordid = i.ordid
group by o.ordid
having count(i.itemid) = (select max(itens)
                          from (select count(itemid) itens
                                from item
                                group by ordid));

ordid	itens 
-------------
617		10

-- 8) Apresente o total de vendas (soma de ORD.TOTAL) para os empregados que são supervisores de outros empregados.

select e.mgr, sum(o.total) total
from emp e, customer c, ord o 
where e.empno = c.repid
and c.custid = o.custid
group by e.mgr;

mgr		total 
-------------
7698	103587

-- 9) Apresente a faixa salarial de cada empregado (coluna SALGRADE.GRADE), assim como o seu nome e o seu próprio salário.

select e.ename, e.sal, s.grade
from emp e, salgrade s 
where e.sal between s.losal and s.hisal;

ename 	sal 	grade 
---------------------
SMITH	800		1
JAMES	950		1
ADAMS	1100	1
WARD	1250	2
MARTIN	1250	2
MILLER	1300	2
TURNER	1500	3
ALLEN	1600	3
CLARK	2450	4
BLAKE	2850	4
JONES	2975	4
FORD	3000	4
SCOTT	3000	4
KING	5000	5

-- 10) Faça uma consulta para verificar se existe algum empregado que não está em nenhuma das faixas salariais da tabela SALGRADE. Se existir, apresente o nome e o salário do empregado

select e.ename, e.sal
from emp e
where e.sal not between 
            (select min(losal) from salgrade)    
            and 
            (select max(hisal) from salgrade)
order by e.ename;

ename 	sal 
-----------
Antonio	20000
-- Lista 5

-- Ana Cláudia - Saulo Antunes

-- 1) Apresente o nome e a data de admissão de todos os empregados que começam com a letra
-- ‘R’ no último nome.

select first_name, last_name, hire_date
from employees
where last_name like 'R%';

first_name	last_name	hire_date
---------------------------------
Trenna		Rajs		17-OCT-95
Den			Raphaely	07-DEC-94
Michael		Rogers		26-AUG-98
John		Russell		01-OCT-96


-- 2) Apresente o último nome concatenado com o primeiro nome de todos os empregados que
-- trabalham no departamento 60.

select last_name || ' ' || first_name name
from employees
where department_id = 60;

name
----
Hunold Alexander
Ernst Bruce
Austin David
Pataballa Valli
Lorentz Diana

-- 3) Apresente em maiúsculas o nome do departamento 60.

select upper(department_name) dept_name
from departments
where department_id = 60;

dept_name
---------
IT

-- 4) Apresente o nome completo de todos os empregados que foram admitidos no ano de 1999
-- (use a coluna hire_date).

select concat(concat(first_name,' '), last_name) name
from employees
where hire_date like '%99';

name
----
Diana Lorentz
Luis Popp
Karen Colmenares
Kevin Mourgos
James Landry
TJ Olson
Ki Gee
Gerald Cambrault
Oliver Tuvault
Danielle Greene
William Smith
Elizabeth Bates
Kimberely Grant
Martha Sullivan
Anthony Cabrio
Randall Perkins
Vance Jones
Donald OConnell

-- 5) Apresente o nome e o salario anual de todos os empregados que ganham entre 4000 e 7000.

select first_name, salary
from employees
where salary >= 4000 and salary <= 7000;

first_name		salary
----------------------
Bruce			6000
David			4800
Valli			4800
Diana			4200
Luis			6900
Shanta			6500
Kevin			5800
Oliver			7000
Sarath			7000
David			6800
Sundar			6400
Amit			6200
Sundita			6100
Kimberely		7000
Charles			6200
Nandita			4200
Alexis			4100
Sarah			4000
Jennifer		4400
Pat				6000
Susan			6500

-- 6) Executando uma ou mais comandos SQL, apresente o nome completo dos empregados que
-- trabalham no departamento de nome ‘Shipping’.

select e.first_name || ' ' || e.last_name name
from employees e join departments d
on e.department_id = d.department_id
where d.department_name = 'Shipping';

name
----
Matthew Weiss
Adam Fripp
Payam Kaufling
Shanta Vollman
Kevin Mourgos
Julia Nayer
Irene Mikkilineni
James Landry
Steven Markle
Laura Bissot
Mozhe Atkinson
James Marlow
TJ Olson
Jason Mallin
Michael Rogers
Ki Gee
Hazel Philtanker
Renske Ladwig
Stephen Stiles
John Seo
Joshua Patel
Trenna Rajs
Curtis Davies
Randall Matos
Peter Vargas
Winston Taylor
Jean Fleaur
Martha Sullivan
Girard Geoni
Nandita Sarchand
Alexis Bull
Julia Dellinger
Anthony Cabrio
Kelly Chung
Jennifer Dilly
Timothy Gates
Randall Perkins
Sarah Bell
Britney Everett
Samuel McCain
Vance Jones
Alana Walsh
Kevin Feeney
Donald OConnell
Douglas Grant

-- 7) Retorne o nome de todos os empregados que trabalham no departamento ‘Shipping’
-- ganhando entre 5000 e 8000 e que foram admitidos entre 1997 e 1999.

select e.first_name || ' ' || e.last_name name
from employees e join departments d
on e.department_id = d.department_id
where d.department_name = 'Shipping'
and hire_date >= '01-JAN-1997' and hire_date < '01-JAN-2000'
and salary >= 5000 and salary <= 8000;

name
----
Shanta Vollman
Kevin Mourgos

-- 8) Com um ou mais comandos SQL, apresente todos os empregados que são gerenciados
-- diretamente pelo empregado Steven King.

select e.first_name
from employees m join employees e 
on m.employee_id = e.manager_id
where m.first_name = 'Steven' and m.last_name = 'King';

first_name
----------
Neena
Lex
Den
Matthew
Adam
Payam
Shanta
Kevin
John
Karen
Alberto
Gerald
Eleni
Michael

-- 9) Apresente o nome de cada empregado e o país onde trabalha.

select e.first_name, c.country_name
from employees e join departments d
on e.department_id = d.department_id join locations l 
on d.location_id = l.location_id join countries c 
on l.country_id = c.country_id;

-- ou

select e.first_name, c.country_name
from employees e, countries c, departaments d, locations l
where e.department_id = d.department_id
and d.location_id = l.location_id
and l.country_id = c.country_id

first_name 		country_name
----------------------------
Steven			United States of America
Neena			United States of America
Lex				United States of America
Alexander		United States of America
Bruce			United States of America
David			United States of America
Valli			United States of America
Diana			United States of America
Nancy			United States of America
Daniel			United States of America
John			United States of America
Ismael			United States of America
Jose Manuel		United States of America
Luis			United States of America
Den				United States of America
Alexander		United States of America
Shelli			United States of America
Sigal			United States of America
Guy				United States of America
Karen			United States of America
Matthew			United States of America
Adam			United States of America
Payam			United States of America
Shanta			United States of America
Kevin			United States of America
Julia			United States of America
Irene			United States of America
James			United States of America
Steven			United States of America
Laura			United States of America
Mozhe			United States of America
James			United States of America
TJ				United States of America
Jason			United States of America
Michael			United States of America
Ki				United States of America
Hazel			United States of America
Renske			United States of America
Stephen			United States of America
John			United States of America
Joshua			United States of America
Trenna			United States of America
Curtis			United States of America
Randall			United States of America
Peter			United States of America
John			United Kingdom
Karen			United Kingdom
Alberto			United Kingdom
Gerald			United Kingdom
Eleni			United Kingdom
Peter			United Kingdom
David			United Kingdom
Peter			United Kingdom
Christopher		United Kingdom
Nanette			United Kingdom
Oliver			United Kingdom
Janette			United Kingdom
Patrick			United Kingdom
Allan			United Kingdom
Lindsey			United Kingdom
Louise			United Kingdom
Sarath			United Kingdom
Clara			United Kingdom
Danielle		United Kingdom
Mattea			United Kingdom
David			United Kingdom
Sundar			United Kingdom
Amit			United Kingdom
Lisa			United Kingdom
Harrison		United Kingdom
Tayler			United Kingdom
William			United Kingdom
Elizabeth		United Kingdom
Sundita			United Kingdom
Ellen			United Kingdom
Alyssa			United Kingdom
Jonathon		United Kingdom
Jack			United Kingdom
Charles			United Kingdom
Winston			United States of America
Jean			United States of America
Martha			United States of America
Girard			United States of America
Nandita			United States of America
Alexis			United States of America
Julia			United States of America
Anthony			United States of America
Kelly			United States of America
Jennifer		United States of America
Timothy			United States of America
Randall			United States of America
Sarah			United States of America
Britney			United States of America
Samuel			United States of America
Vance			United States of America
Alana			United States of America
Kevin			United States of America
Donald			United States of America
Douglas			United States of America
Jennifer		United States of America
Michael			Canada
Pat				Canada
Susan			United Kingdom
Hermann			Germany
Shelley			United States of America
William			United States of America

-- 10) Apresente o nome dos empregados do departamento ‘Shipping’ admitidos entre 1999 e
-- 2005 e que ganham mais de 2000. Para cada empregado, apresente também o nome do seu
-- departamento, a cidade, o país e a região do departamento.

select e.first_name, e.salary, d.department_name, l.city, c.country_name, r.region_name
from employees e join departments d
on e.department_id = e.department_id join locations l 
on d.location_id = l.location_id join countries c 
on l.country_id = c.country_id join regions r
on c.region_id = r.region_id
where d.department_name = 'Shipping'
and e.hire_date >= '01-JAN-1991' and e.hire_date < '01-JAN-2006'
and e.salary >= 2000;

first_name	salary 	department_name city 					country_name 				region_name
Lex			17000	Shipping		South San Francisco		United States of America	Americas
Bruce		6000	Shipping		South San Francisco		United States of America	Americas
David		4800	Shipping		South San Francisco		United States of America	Americas
Valli		4800	Shipping		South San Francisco		United States of America	Americas
Diana		4200	Shipping		South San Francisco		United States of America	Americas
Nancy		12000	Shipping		South San Francisco		United States of America	Americas
Daniel		9000	Shipping		South San Francisco		United States of America	Americas
John		8200	Shipping		South San Francisco		United States of America	Americas
Ismael		7700	Shipping		South San Francisco		United States of America	Americas
Jose Manuel	7800	Shipping		South San Francisco		United States of America	Americas
Luis		6900	Shipping		South San Francisco		United States of America	Americas
Den			11000	Shipping		South San Francisco		United States of America	Americas
Alexander	3100	Shipping		South San Francisco		United States of America	Americas
Shelli		2900	Shipping		South San Francisco		United States of America	Americas
Sigal		2800	Shipping		South San Francisco		United States of America	Americas
Guy			2600	Shipping		South San Francisco		United States of America	Americas
Karen		2500	Shipping		South San Francisco		United States of America	Americas
Matthew		8000	Shipping		South San Francisco		United States of America	Americas
Adam		8200	Shipping		South San Francisco		United States of America	Americas
Payam		7900	Shipping		South San Francisco		United States of America	Americas
Shanta		6500	Shipping		South San Francisco		United States of America	Americas
Kevin		5800	Shipping		South San Francisco		United States of America	Americas
Julia		3200	Shipping		South San Francisco		United States of America	Americas
Irene		2700	Shipping		South San Francisco		United States of America	Americas
James		2400	Shipping		South San Francisco		United States of America	Americas
Steven		2200	Shipping		South San Francisco		United States of America	Americas
Laura		3300	Shipping		South San Francisco		United States of America	Americas
Mozhe		2800	Shipping		South San Francisco		United States of America	Americas
James		2500	Shipping		South San Francisco		United States of America	Americas
TJ			2100	Shipping		South San Francisco		United States of America	Americas
Jason		3300	Shipping		South San Francisco		United States of America	Americas
Michael		2900	Shipping		South San Francisco		United States of America	Americas
Ki			2400	Shipping		South San Francisco		United States of America	Americas
Hazel		2200	Shipping		South San Francisco		United States of America	Americas
Renske		3600	Shipping		South San Francisco		United States of America	Americas
Stephen		3200	Shipping		South San Francisco		United States of America	Americas
John		2700	Shipping		South San Francisco		United States of America	Americas
Joshua		2500	Shipping		South San Francisco		United States of America	Americas
Trenna		3500	Shipping		South San Francisco		United States of America	Americas
Curtis		3100	Shipping		South San Francisco		United States of America	Americas
Randall		2600	Shipping		South San Francisco		United States of America	Americas
Peter		2500	Shipping		South San Francisco		United States of America	Americas
John		14000	Shipping		South San Francisco		United States of America	Americas
Karen		13500	Shipping		South San Francisco		United States of America	Americas
Alberto		12000	Shipping		South San Francisco		United States of America	Americas
Gerald		11000	Shipping		South San Francisco		United States of America	Americas
Eleni		10500	Shipping		South San Francisco		United States of America	Americas
Peter		10000	Shipping		South San Francisco		United States of America	Americas
David		9500	Shipping		South San Francisco		United States of America	Americas
Peter		9000	Shipping		South San Francisco		United States of America	Americas
Christopher	8000	Shipping		South San Francisco		United States of America	Americas
Nanette		7500	Shipping		South San Francisco		United States of America	Americas
Oliver		7000	Shipping		South San Francisco		United States of America	Americas
Janette		10000	Shipping		South San Francisco		United States of America	Americas
Patrick		9500	Shipping		South San Francisco		United States of America	Americas
Allan		9000	Shipping		South San Francisco		United States of America	Americas
Lindsey		8000	Shipping		South San Francisco		United States of America	Americas
Louise		7500	Shipping		South San Francisco		United States of America	Americas
Sarath		7000	Shipping		South San Francisco		United States of America	Americas
Clara		10500	Shipping		South San Francisco		United States of America	Americas
Danielle	9500	Shipping		South San Francisco		United States of America	Americas
Mattea		7200	Shipping		South San Francisco		United States of America	Americas
David		6800	Shipping		South San Francisco		United States of America	Americas
Sundar		6400	Shipping		South San Francisco		United States of America	Americas
Amit		6200	Shipping		South San Francisco		United States of America	Americas
Lisa		11500	Shipping		South San Francisco		United States of America	Americas
Harrison	10000	Shipping		South San Francisco		United States of America	Americas
Tayler		9600	Shipping		South San Francisco		United States of America	Americas
William		7400	Shipping		South San Francisco		United States of America	Americas
Elizabeth	7300	Shipping		South San Francisco		United States of America	Americas
Sundita		6100	Shipping		South San Francisco		United States of America	Americas
Ellen		11000	Shipping		South San Francisco		United States of America	Americas
Alyssa		8800	Shipping		South San Francisco		United States of America	Americas
Jonathon	8600	Shipping		South San Francisco		United States of America	Americas
Jack		8400	Shipping		South San Francisco		United States of America	Americas
Charles		6200	Shipping		South San Francisco		United States of America	Americas
Winston		3200	Shipping		South San Francisco		United States of America	Americas
Jean		3100	Shipping		South San Francisco		United States of America	Americas
Martha		2500	Shipping		South San Francisco		United States of America	Americas
Girard		2800	Shipping		South San Francisco		United States of America	Americas
Nandita		4200	Shipping		South San Francisco		United States of America	Americas
Alexis		4100	Shipping		South San Francisco		United States of America	Americas
Julia		3400	Shipping		South San Francisco		United States of America	Americas
Anthony		3000	Shipping		South San Francisco		United States of America	Americas
Kelly		3800	Shipping		South San Francisco		United States of America	Americas
Jennifer	3600	Shipping		South San Francisco		United States of America	Americas
Timothy		2900	Shipping		South San Francisco		United States of America	Americas
Randall		2500	Shipping		South San Francisco		United States of America	Americas
Sarah		4000	Shipping		South San Francisco		United States of America	Americas
Britney		3900	Shipping		South San Francisco		United States of America	Americas
Samuel		3200	Shipping		South San Francisco		United States of America	Americas
Vance		2800	Shipping		South San Francisco		United States of America	Americas
Alana		3100	Shipping		South San Francisco		United States of America	Americas
Kevin		3000	Shipping		South San Francisco		United States of America	Americas
Donald		2600	Shipping		South San Francisco		United States of America	Americas
Douglas		2600	Shipping		South San Francisco		United States of America	Americas
Michael		13000	Shipping		South San Francisco		United States of America	Americas
Pat			6000	Shipping		South San Francisco		United States of America	Americas
Susan		6500	Shipping		South San Francisco		United States of America	Americas
Hermann		10000	Shipping		South San Francisco		United States of America	Americas
Shelley		12000	Shipping		South San Francisco		United States of America	Americas
William		8300	Shipping		South San Francisco		United States of America	Americas

-- 11) Apresente o nome completo dos empregados e os cargos já ocupados antes do atual. Os
-- cargos anteriores estão em JOB_HISTORY que também possui uma chave estrangeira para
-- JOBS.

select e.first_name || ' ' || e.last_name name, j.job_title
from job_history jh join employees e 
on e.employee_id = jh.employee_id join jobs j
on jh.job_id = j.job_id;

name 				job_title
-----------------------------
Neena Kochhar		Public Accountant
Neena Kochhar		Accounting Manager
Lex De Haan			Programmer
Den Raphaely		Stock Clerk
Payam Kaufling		Stock Clerk
Jonathon Taylor		Sales Representative
Jonathon Taylor		Sales Manager
Jennifer Whalen		Administration Assistant
Jennifer Whalen		Public Accountant
Michael Hartstein	Marketing Representative

-- 12) Apresente o nome dos empregados que nunca tiveram mais de um cargo na empresa. Ou
-- seja, os que nunca aparecem em JOB_HISTORY. Faça isso com junção externa.

select e.first_name || ' ' || e.last_name name
from employees e left outer join job_history jh
on e.employee_id = jh.employee_id
where jh.employee_id is null;

name
----
Steven King
Alexander Hunold
Bruce Ernst
David Austin
Valli Pataballa
Diana Lorentz
Nancy Greenberg
Daniel Faviet
John Chen
Ismael Sciarra
Jose Manuel Urman
Luis Popp
Alexander Khoo
Shelli Baida
Sigal Tobias
Guy Himuro
Karen Colmenares
Matthew Weiss
Adam Fripp
Shanta Vollman
Kevin Mourgos
Julia Nayer
Irene Mikkilineni
James Landry
Steven Markle
Laura Bissot
Mozhe Atkinson
James Marlow
TJ Olson
Jason Mallin
Michael Rogers
Ki Gee
Hazel Philtanker
Renske Ladwig
Stephen Stiles
John Seo
Joshua Patel
Trenna Rajs
Curtis Davies
Randall Matos
Peter Vargas
John Russell
Karen Partners
Alberto Errazuriz
Gerald Cambrault
Eleni Zlotkey
Peter Tucker
David Bernstein
Peter Hall
Christopher Olsen
Nanette Cambrault
Oliver Tuvault
Janette King
Patrick Sully
Allan McEwen
Lindsey Smith
Louise Doran
Sarath Sewall
Clara Vishney
Danielle Greene
Mattea Marvins
David Lee
Sundar Ande
Amit Banda
Lisa Ozer
Harrison Bloom
Tayler Fox
William Smith
Elizabeth Bates
Sundita Kumar
Ellen Abel
Alyssa Hutton
Jack Livingston
Kimberely Grant
Charles Johnson
Winston Taylor
Jean Fleaur
Martha Sullivan
Girard Geoni
Nandita Sarchand
Alexis Bull
Julia Dellinger
Anthony Cabrio
Kelly Chung
Jennifer Dilly
Timothy Gates
Randall Perkins
Sarah Bell
Britney Everett
Samuel McCain
Vance Jones
Alana Walsh
Kevin Feeney
Donald OConnell
Douglas Grant
Pat Fay
Susan Mavris
Hermann Baer
Shelley Higgins
William Gietz

-- 13) Apresente todas as cidades (CITY em LOCATIONS) e seus departamentos.

select l.city, d.department_name
from locations l join departments d
on l.location_id = d.location_id;

city 					department_name
---------------------------------------
Southlake				IT
South San Francisco		Shipping
Seattle					Administration
Seattle					Purchasing
Seattle					Executive
Seattle					Finance
Seattle					Accounting
Seattle					Treasury
Seattle					Corporate Tax
Seattle					Control And Credit
Seattle					Shareholder Services
Seattle					Benefits
Seattle					Manufacturing
Seattle					Construction
Seattle					Contracting
Seattle					Operations
Seattle					IT Support
Seattle					NOC
Seattle					IT Helpdesk
Seattle					Government Sales
Seattle					Retail Sales
Seattle					Recruiting
Seattle					Payroll
Toronto					Marketing
London					Human Resources
Oxford					Sales
Munich					Public Relations

-- 14) Agora, apresente aquelas cidades que não possuem nenhum departamento. Utilize junção
-- externas.

select l.city
from locations l left join departments d
on l.location_id = d.location_id
where d.location_id is null;

city
----
Roma
Venice
Tokyo
Hiroshima
South Brunswick
Whitehorse
Beijing
Bombay
Sydney
Singapore
Stretford
Sao Paulo
Geneva
Bern
Utrecht
Mexico City

-- 15) Apresente também, para a questão 14, os nomes dos países das cidades sem departamento.
-- Apresente uma consulta com junção externa e outra com sub-consulta.

select l.city, c.country_name
from locations l left join countries c
on l.country_id = c.country_id left join departments d
on l.location_id = d.location_id
where d.location_id is null;

select l.city, c.country_name
from locations l, countries c
where l.country_id = c.country_id 
and l.location_id not in (select location_id from departments d where d.location_id = l.location_id);

city 				country_name
--------------------------------
Beijing				China
Bern				Switzerland
Bombay				India
Geneva				Switzerland
Hiroshima			Japan
Mexico City			Mexico
Roma				Italy
Sao Paulo			Brazil
Singapore			Singapore
South Brunswick		United States of America
Stretford			United Kingdom
Sydney				Australia
Tokyo				Japan
Utrecht				Netherlands
Venice				Italy
Whitehorse			Canada

-- 16) Apresente, distintamente, todos os cargos sendo ocupados atualmente na cidade de
-- ‘Seattle’. Utilize, para isso, somente sub-consultas e a cláusula SELECT DISTINCT na
-- consultas internas. A palavra reservada DISTINCT remove as duplicidades dos resultados e
-- deve vir somente uma vez, sendo depois de SELECT e antes das colunas da projeção.

select distinct job_title from jobs
where job_id = any(select job_id from employees e where 
			 department_id = any(select department_id from departaments where location_id = 
			 					(select location_id from locations where city = 'Seattle')));

job_title
---------
Purchasing Clerk
Accounting Manager
Administration Vice President
Administration Assistant
Purchasing Manager
President
Finance Manager
Accountant
Public Accountant

-- 17) Resolva a consulta 16 utilizando somente junções ao invés de sub-consultas.

select distinct j.job_title
from employees e join jobs j 
on e.job_id = j.job_id join departments d 
on e.department_id = d.department_id join locations l 
on d.location_id = l.location_id
where l.city = 'Seattle';

job_title
---------
Purchasing Clerk
Accounting Manager
Administration Vice President
Administration Assistant
Purchasing Manager
President
Finance Manager
Accountant
Public Accountant

-- 18) Apresente o nome completo dos empregados que têm “Sales” no cargo atual e que a
-- comissão (COMMISSION_PCT de EMPLOYEES) seja válida, ou melhor não vazia. Utilize
-- somente sub-consultas e a cláusula LIKE.

select first_name || ' ' || last_name name from 
	(select * from employees where department_id =
			any(select department_id from departments where department_name like '%Sales%'))
  where COMMISSION_PCT is not null;

name
----
John Russell
Karen Partners
Alberto Errazuriz
Gerald Cambrault
Eleni Zlotkey
Peter Tucker
David Bernstein
Peter Hall
Christopher Olsen
Nanette Cambrault
Oliver Tuvault
Janette King
Patrick Sully
Allan McEwen
Lindsey Smith
Louise Doran
Sarath Sewall
Clara Vishney
Danielle Greene
Mattea Marvins
David Lee
Sundar Ande
Amit Banda
Lisa Ozer
Harrison Bloom
Tayler Fox
William Smith
Elizabeth Bates
Sundita Kumar
Ellen Abel
Alyssa Hutton
Jonathon Taylor
Jack Livingston
Charles Johnson

-- 19) Resolva a questão 18 sem sub-consultas.

select e.first_name || ' ' || e.last_name name from 
employees e join departments d
on e.department_id = d.department_id
where d.department_name like '%Sales%'
and e.COMMISSION_PCT is not null;

name
----
John Russell
Karen Partners
Alberto Errazuriz
Gerald Cambrault
Eleni Zlotkey
Peter Tucker
David Bernstein
Peter Hall
Christopher Olsen
Nanette Cambrault
Oliver Tuvault
Janette King
Patrick Sully
Allan McEwen
Lindsey Smith
Louise Doran
Sarath Sewall
Clara Vishney
Danielle Greene
Mattea Marvins
David Lee
Sundar Ande
Amit Banda
Lisa Ozer
Harrison Bloom
Tayler Fox
William Smith
Elizabeth Bates
Sundita Kumar
Ellen Abel
Alyssa Hutton
Jonathon Taylor
Jack Livingston
Charles Johnson
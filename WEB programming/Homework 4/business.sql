create database business;
use business;
create table customer(
  customer_name varchar(20) not null primary key,
  customer_address varchar(40),
  customer_city varchar(30),
  customer_phone char(10)
);
create table porder(
  porder_number varchar(5) not null primary key,
  porder_totalcost int,
  porder_cname varchar(20),
  porder_payment varchar(10) 
);
create table product( 
  product_ordernumber varchar(5) not null primary key,
  product0 int,
  product1 int,
  product2 int,
  product3 int,
  product4 int
);
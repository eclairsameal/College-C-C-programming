create database students;
use students;
create table question(
  student_id varchar(10) not null primary key,
  student_name varchar(40) not null,
  answers int,
  corect int
)
insert into question values (
  '444',
  'VALSHE',
  '5',
  '4'
);
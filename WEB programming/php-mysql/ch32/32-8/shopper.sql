/* 圖片請自行製作 */
CREATE DATABASE shopper;
USE shopper;
CREATE TABLE shopping ( 
  session tinytext NOT NULL, 
  product tinytext NOT NULL, 
  quantity tinytext NOT NULL, 
  card tinytext NOT NULL, 
  id int(4) DEFAULT '0' NOT NULL auto_increment, 
  KEY id (id), 
  PRIMARY KEY (id) 
); 
CREATE TABLE inventory ( 
  product tinytext NOT NULL, 
  quantity tinytext NOT NULL, 
  id int(4) DEFAULT '0' NOT NULL auto_increment, 
  description tinytext NOT NULL, 
  price float(10,2) DEFAULT '0.00' NOT NULL, 
  category char(1) DEFAULT '' NOT NULL, 
  KEY id (id), 
  PRIMARY KEY (id), 
  KEY price (price) 
);
insert into inventory values ('硬碟機','5','1','80G','5600','1');
insert into inventory values ('CPU','12','2','P4-2.4G','6600','1');
insert into inventory values ('DVD-ROM','7','3','12X','2000','1');
insert into inventory values ('主機板','3','4','ASUS','5000','2');
insert into inventory values ('顯示卡','6','5','64M','4500','1');
insert into inventory values ('燒錄機','4','6','52W','3000','1');
 

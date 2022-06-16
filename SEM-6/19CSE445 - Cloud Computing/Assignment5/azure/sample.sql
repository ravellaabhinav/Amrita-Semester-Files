CREATE DATABASE SampleDB;
USE SampleDB;
CREATE TABLE login (username varchar(25),password varchar(25));

    

INSERT INTO login values ("gowtham","ramesh");
INSERT INTO login values ("Prakash","Periyasamy"); 
INSERT INTO login values ("Baskar","Arumugam"); 


select * from login;  

drop table login;

drop database SampleDB;
create table Owns (
title varchar(20),
year int,
studioName varchar(20) not null,
primary key (title, year),
foreign key (title, year) references Movies(title, year),
foreign key (studioName) references Studios(name)
);
#include <ctime>  // time and localtime
#include "date.h"
#include <iostream>
using namespace std;

int Date::daysPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Date::Date() {
	time_t timer = time(0); // time in seconds since 1970-01-01
	tm* locTime = localtime(&timer); // broken-down time
	year = 1900 + locTime->tm_year;
	month = 1 + locTime->tm_mon;
	day = locTime->tm_mday;
}

Date::Date(int y, int m, int d): year(y), month(m), day(d) {}

int Date::getYear() const {
	return year;
}

int Date::getMonth() const {
	return month;
}

int Date::getDay() const {
	return day;
}

void Date::next() {
	if(day<daysPerMonth[month-1]) {
		day++;
	}else{
		day=1;
		if(month<12) {
			month++;
		}else{
			month=1;
			year++;
		}
	}
}

std::ostream& operator<<(std::ostream& out, const Date& d){
	string day;
	string month;
	if (d.day < 10) day = to_string(0) + to_string(d.day);
	else day = to_string(d.day);
	if (d.month < 10) month = to_string(0) + to_string(d.month);
	else month = to_string(d.month);
	out << d.getYear() << "-" << month << "-" << day;
	return out;
}

void operator>>(std::istream& in, Date& d){
	string s;
	in >> s;
	
	if (s.size() != 10 || s[4] != '-' || s[7] != '-'){
		in.setstate(ios_base::failbit);
	} else {
		try {
			d.year = stoi(s.substr(0,4));
			d.month = stoi(s.substr(5,2));
			d.day = stoi(s.substr(8,2));
			if(d.year < 999){
				in.setstate(ios_base::failbit);
			} else if(!(d.month < 13 && d.month > 0)){
				in.setstate(ios_base::failbit);
			} else if(!(d.day > 0 && d.day <= Date::daysPerMonth[d.month - 1])){
				in.setstate(ios_base::failbit);
			}
		} catch (exception e){
			in.setstate(ios_base::failbit);
		}

		
	} 
}
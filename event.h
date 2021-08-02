#pragma once
#include <iostream>
#include <string.h>
#include <time.h>
#include <cstdlib>
using namespace std;

class Date
{
 private:
  int day;
  int month;
  int year;
public:
Date(int day, int month, int year)
{
  this->day=day;
  this->month=month;
  this->year=year;
}

void display_Date()
{
  cout<<day<<"-"<<month<<"-"<<year<<endl;

}

};



class event
{
private:
  string name;
  int a;
  int b;
  int c;
public:
	string unit;
	event(string name,int a, int b, int c)
	{
		this->name=name;
		this->a=a;
		this->b=b;
		this->c=c;
	}

	string getName()
	{
		return name;
	}

	virtual double vote_count(double vote)
        {
		return 0;
	}

	virtual ~event()
	{

	}
};

class Candidates_related_event: public event
{
public:
	Candidates_related_event(string name,int a, int b, int c):event(name,a,b,c)
{
   unit="Votes";
}
	double vote_count(double vote)
	{

        double time=rand()%100;
        return vote+time;
	}

	~Candidates_related_event()
	{

	}
};



class Leaders_related_event: public event
{
public:
	Leaders_related_event(string name,int a, int b, int c):event(name,a,b,c)
{
   unit="Votes";
}
	double vote_count(double vote)
	{

        double time=rand()%100;
        return vote+time;
	}

	~Leaders_related_event()
	{

	}
};

class Issues_related_event: public event
{
public:
	Issues_related_event(string name,int a, int b, int c):event(name,a,b,c)
{
   unit="Votes";
}
	double vote_count(double vote)
	{

        double time=rand()%100;
        return vote+time;
	}

	~Issues_related_event()
	{

	}
};





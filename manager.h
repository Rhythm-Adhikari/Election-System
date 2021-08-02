#pragma once
#include <iostream>
#include "campaign_members.h"
using namespace std;
class manager
{
private:

  string name;
  int age;
  int salary;
  double exp;

public:
	manager(string name,int age, int salary, double exp)
	{
		this->name=name;
		this->age=age;
		this->salary=salary;
		this->exp=exp;
	}
	string get_name()
	{
		return name;
	}
    int get_age()
    {
    	return age;
    }
    int get_salary()
    {
    	return salary;
    }
    double get_exp()
    {
    	return exp;
    }

    void displayInfo()
    {
      cout<<"  Campaign Manager Name: "<<name<<"  Age:  "<<age<<"  Salary:  "<<salary<<"  Experience:  "<<exp;
    }



};
class field_manager
{
private:
   string name;
   int age;
   int rank;
   int fieldExperience;
public:
   field_manager(string name,int age,int rank,int fieldExperience)
   {
   	  this->name=name;
   	  this->age=age;
   	  this->rank=rank;
   	  this->fieldExperience=fieldExperience;
   }

    void improve_campaign(campaign_members*P)
{
      P->set_vote(P->get_vote()+2);
}

   string get_name()
   {
     return name;
   }

   int get_age()
   {
   	return age;
   }

   int get_rank()
   {
   	return rank;
   }

   int get_field_experience()
   {
   	return fieldExperience;
   }
    void displayInfo()
    {
      cout<<"Outdoor Campaign Manager Name: "<<name<<"  Age:  "<<age<<"  rank:  "<<rank<<"  Campaign experience:  "<<fieldExperience;
    }
};

class Online_manager
{
private:
   string name;
   int age;
   int position;
   int managerExperience;
public:
   Online_manager(string name,int age,int position,int OnlineExperience)
   {
   	  this->name+=name;
   	  this->age=age;
   	  this->position=position;
   	  this->managerExperience=managerExperience;
   }

   string get_name()
   {
     return name;
   }
        void improve_campaign(campaign_members*P)
{
      P->set_vote(P->get_vote()+1);
}


   int get_age()
   {
   	return age;
   }



   int get_manager_experience()
   {
   	return managerExperience;
   }

    void displayInfo()
    {
      cout<<"  online Ad Manager Name: "<<name<<"  Age:  "<<age<<"    Online ad Manager experience:  "<<managerExperience;
    }
};

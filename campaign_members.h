#pragma once
#include "event.h"
class campaign_members
{
private:
	string name;
	double vote;
	double totalVote;
    string with_Political_party;
public:
	campaign_members(string name,string with_Political_party, int vote)
	{
		this->name=name;
		this->with_Political_party=with_Political_party;
		this->vote=vote;
		totalVote=0;
	}
	void perform(event*E)
	{
        double votee=rand()%100;
        vote=E->vote_count(votee);
	}

	string get_name()
	{
		return name;
	}

	void set_total_Vote(int s)
	{
		totalVote=s;
	}

    double get_total_vote()
    {
       return totalVote;
    }

	double get_vote()
	{
		return vote;
	}

	string get_Team()
	{
		return with_Political_party;
	}

	void set_vote(double s)
	{
      vote=s;
	}


	 void displayInfo()
    {
      cout<<" "<<with_Political_party<<"  vote:  "<<vote<<"  Name:  "<<name;
    }



};

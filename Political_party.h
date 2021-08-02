#pragma once
#include "manager.h"

class Political_party
{
private:
  campaign_members*PresidentCandidate;
  field_manager*f_manager;
  Online_manager*o_manager;
  manager*Manager;
  string name;
public:
	Political_party(string name,campaign_members*PresidentCandidate,field_manager*f_manager, Online_manager*o_manager, manager*Manager)
	{
		this->name=name;
		this->PresidentCandidate=PresidentCandidate;
		this->f_manager=f_manager;
		this->o_manager=o_manager;
		this->Manager=Manager;
	}

	double get_presidental_vote()
	{
		return PresidentCandidate->get_vote();
	}

	string get_electorates_name()
	{
     return PresidentCandidate->get_name();
	}

	double get_electorates_total_vote()
	{
		return PresidentCandidate->get_total_vote();
	}

	void Perform(event*E)
	{
     PresidentCandidate->perform(E);
     f_manager->improve_campaign(PresidentCandidate);
     o_manager->improve_campaign(PresidentCandidate);

     PresidentCandidate->set_total_Vote(PresidentCandidate->get_total_vote()+PresidentCandidate->get_vote());


	}

	string get_name()
	{
		return name;
	}


	void displayCampaignteam()
	{
		cout<<name<<endl<<endl;
		PresidentCandidate->displayInfo();
		cout<<endl;

		f_manager->displayInfo();
		cout<<endl;

		o_manager->displayInfo();
		cout<<endl;

		Manager->displayInfo();
		cout<<endl<<endl<<endl;
	}

	~Political_party()
	{
		delete PresidentCandidate;
		delete f_manager;
		delete o_manager;
		delete Manager;
	}

};

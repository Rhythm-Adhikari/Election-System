#pragma once
#include "Political_party.h"
#include "event.h"
#include <cstdlib>
#include <sstream>

class election
{
private:
	Date*dates[5];
    string name;
	int elec_num;
	int campaign_days;
	Political_party*Political_partys[30];
	string adOnlineNationIssue[3];
	string locations[5];
	string fieldCampainNationIssue[3];
	event*events[6];

public:
	election(int elec_num, int campaign_days, string name)
	{
    adOnlineNationIssue[0]="Global Warming Radio ad";
    adOnlineNationIssue[1]="Covid-19 Press confrence ";
    adOnlineNationIssue[2]="National Debt Radio ad";
    fieldCampainNationIssue[0]="Cyber Security Speech";
    fieldCampainNationIssue[1]="National Security Rally ";
    fieldCampainNationIssue[2]="Health Care System campaign";

	locations[0]="Orange";
    locations[1]="Wagga-Wagga";
    locations[2]="Sydney";
    locations[3]="Bathurst";
    locations[4]="Wollongong";

		srand(time(NULL));
		int randomYear=2000+rand()%100;
		int randomMonth=1+rand()%11;
		int randomDay=1+rand()%20;

		for(int a=0;a<4;a++)
		{
		  dates[a]=new Date(randomDay,randomMonth,randomYear);
          events[a]=new Leaders_related_event(adOnlineNationIssue[a],0,0,0);

          if(randomDay>=24)
          {
            int gap=5+rand()%3;
            randomDay=1+(randomDay+gap)%31;
            randomMonth=1+(randomMonth)%12;

            if(((randomMonth+1)%12)>12)
            {
            randomYear++;
            }

          }
          else
          {
          	int gap=5+rand()%3;
            randomDay=1+(randomDay+gap)%29;

             if(((randomMonth+1)%12)>12)
            {
            randomYear++;
            }


          }
		}

		for(int a=4;a<6;a++)
		{
			dates[a]=new Date(randomDay,randomMonth,randomYear);
            events[a]=new Candidates_related_event(fieldCampainNationIssue[a-4],0,0,0);

            if(randomDay>=24)
          {
            int gap=5+rand()%3;
            randomDay=(randomDay+gap)%29;
            randomMonth=1+(randomMonth)%12;

            if(((randomMonth+1)%12)>12)
            {
            randomYear++;
            }

          }

          else
          {
          	int gap=5+rand()%3;
            randomDay=(randomDay+gap)%29;

             if(((randomMonth+1)%12)>12)
            {
            randomYear++;
            }


          }

		}



		this->elec_num=elec_num;
		this->campaign_days=campaign_days;
        this->name=name;



          for(int b=0;b<this->elec_num;b++)
          {
          	  ostringstream str1;
          	  str1<<b+1;
          	  string ss=str1.str();

          	  campaign_members*PresidentCandidate=new campaign_members("Male Candidate = "+ss,"Political_party = Tunder"+ss+"1",0);


          	  manager*M=new manager("manager = "+ss,22+(b+1),2000+(b*100),2+(b+1));
          	  field_manager*F=new field_manager("field manager  "+ss,20+(b+1),1-(b),1+(b));
          	  Online_manager*T=new Online_manager("Online manager  "+ss,30+(b+1),1-(b),1+(b));

              Political_partys[b]=new Political_party("Political party"+ss,PresidentCandidate,F,T,M);
          }




       for(int b=0;b<this->elec_num;b++)
       {
       	  Political_partys[b]->displayCampaignteam();
       }


	}

	string get_name()
	{
		return name;
	}

	void startElection()
	{
		for(int a=0;a<campaign_days;a++)
		{
			cout<<"Date: ";
			dates[a]->display_Date();
			cout<<endl;
			cout<<"Month 1:"<<endl;
			cout<<"1. "<<adOnlineNationIssue[0]<<endl;
			cout<<"2. "<<fieldCampainNationIssue[1]<<endl;
			cout<<"3. "<<fieldCampainNationIssue[2]<<endl;
			cout<<"4. "<<adOnlineNationIssue[2]<<endl;
			cout<<endl;
			cout<<"Month 2:"<<endl;
			cout<<"1. "<<adOnlineNationIssue[1]<<endl;
			cout<<"2. "<<fieldCampainNationIssue[0]<<endl;

			cout<<endl<<endl;

					for(int c=0;c<6;c++)
				{
					if(c%4==0)
					{

						int index1=rand()%6;
						cout<<"Todays Campaign is held at : "<<locations[index1]<<endl;

					}
 					for(int b=0;b<elec_num;b++)
            			{
						Political_partys[b]->Perform(events[c]);
		    			}

		    			 decideVote(c);

				}



		}


         cout<<"                                         "<<endl<<endl;
         cout<<"Candidate: "<<endl<<endl;
         cout<<"Name         Total vote"<<endl;
		for(int a=0;a<elec_num;a++)
		{
           cout<<Political_partys[a]->get_electorates_name()<<"   "<<Political_partys[a]->get_electorates_total_vote()<<endl;
		}


		cout<<endl;


        int max=Political_partys[0]->get_electorates_total_vote();
        int index=0;

		for(int a=0;a<elec_num;a++)
		{
           if(max<Political_partys[a]->get_electorates_total_vote())
           {
              max=Political_partys[a]->get_electorates_total_vote();
              index=a;
           }
		}

		cout<<Political_partys[index]->get_electorates_name()<<" ***********Congrulation Electorate !!!!!!!!!! You have won the election and became the president.*************** "<<Political_partys[index]->get_electorates_total_vote()
		<<endl;


	}

	void decideVote(int c)
	{
		int Mfirst=0;

		int Mindex1=0;

		for(int a=0;a<elec_num;a++)
		{
			 if(Mfirst<=Political_partys[a]->get_presidental_vote())
        {

        	Mfirst=Political_partys[a]->get_presidental_vote();
        	Mindex1=a;
        }

		}
       cout<<events[c]->getName()<<endl<<endl;

         cout<<"Candidate Name:          Vote       "<<endl;
      for(int a=0;a<elec_num;a++)
      {
      	cout<<Political_partys[a]->get_electorates_name()<<"        "<<Political_partys[a]->get_presidental_vote()<<"       "<<events[c]->unit<<endl;
      }

       cout<<endl<<endl;
      cout<<endl<<endl;







    cout<<"Congrulation Electorates "<<endl;
	cout<<Political_partys[Mindex1]->get_electorates_name()<<"You are one step closer to becomming the president "<<endl;

cout<<endl;
cout<<endl;

 }

 ~election()
 {
 	for(int a=0;a<5;a++)
 	{
 		delete dates[a];

 	}
 	for(int a=0;a<elec_num;a++)
 	{

 		delete Political_partys[a];

 	}





 }



};


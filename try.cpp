#include <cstdio>
#include <iostream>
#include <string.h>
#include <cstdlib>
#include <fstream>

using namespace std;
static int p = 0;
int n=10;
class a
{
	char busn[5], driver[10], arrival[5], depart[5], from[10], to[10], seat[8][4][10];
	        int wt,cargowt;
public:
    int i;
    a(){i=0,wt=0;}
	void install(char *);
	void allotment(char *);
	void empty();
	void show();
	void avail();
	void position(int i);
	void cargo(char *);
	void dispatch();
} bus[10];

void vline(char ch)
{
	for (int i=80; i>0; i--)
		cout<<ch;
}

void a::install(char name[20]="")
{ ofstream wr(name,ios::app);
	cout<<"Enter bus no: ";
	cin>>bus[p].busn;
	cout<<"\nEnter Driver's name: ";
	cin>>bus[p].driver;
	cout<<"\nArrival time: ";
	cin>>bus[p].arrival;
	cout<<"\nDeparture: ";
	cin>>bus[p].depart;
	cout<<"\nFrom: \t\t\t";
	cin>>bus[p].from;
	cout<<"\nTo: \t\t\t";
	cin>>bus[p].to;
	cout<<"\n maximum cargo weight: ";
        cin>>bus[p].wt;

	bus[p].empty();

	if(strcmp(name,"")!=0)
	wr<<"bus no:    "<<bus[p].busn<<"\tDriver name:   "<<bus[p].driver<<"\t arrival time:   "<<bus[p].arrival<<"\t departure time:   "<<bus[p].depart<<"\t from:   "<<bus[p].from<<"\t to:   "<<bus[p].to<<"\t max cargo weight:  "<<bus[p].wt<<endl;
wr.close();
p++;
}
void a::allotment(char name[]="")
{
	int seat;
	char number[5];
	int n;
	do
	{
		cout<<"Bus no: ";
		cin>>number;
		for(n=0; n<=p; n++)
		{
			if(strcmp(bus[n].busn, number)==0)
				break;
		}
		while(n<=p)
		{
			cout<<"\nSeat Number: ";
			cin>>seat;
			if(seat>32)
			{
				cout<<"\nThere are only 32 seats available in this bus.";
			}
			else
			{
				if (strcmp(bus[n].seat[seat/4][(seat%4)-1], "Empty")==0)
				{ ofstream wa(name,ios::app);
					cout<<"Enter passenger's name: ";
					cin>>bus[n].seat[seat/4][(seat%4)-1];
					wa<<"seat no:   "<<seat<<"\t passenger name:   "<<bus[n].seat[seat/4][(seat%4)-1]<<endl;

					wa.close();
					break;
				}
				else
					cout<<"The seat no. is already reserved.\n";
			}
		}
	}while(n > p);
}

void a::empty()
{
	for(int i=0; i<8; i++)
	{
		for(int j=0; j<4; j++)
		{
			strcpy(bus[p].seat[i][j], "Empty");


		}
	}
bus[p].cargowt=0;
}
void a::cargo(char name[]="")
{int cwt,n;
char number[10];
int cargoid;
ofstream cr(name,ios::app);
cout<<"Bus no: ";
		cin>>number;
		for(n=0; n<=p; n++)
		{
			if(strcmp(bus[n].busn, number)==0)
    {




cout<<"enter cargo id\n";
cin>>cargoid;
cout<<"enter weight of cargo\n";
cin>>cwt;
bus[n].cargowt+=cwt;
if(bus[n].cargowt<bus[n].wt)
{cout<<"cargo added\n";
cr<<endl<<"cargo id:  "<<cargoid<<"\t cargo weight:  "<<cwt<<endl;
}
else
    cout<<"cargo cant be added\n";
    break;
    }
}
if(n>p)
    cout<<"enter valid bus no"<<endl;
}

void a::show()
{
	int n;
	char number[5];
	cout<<"Enter bus no: ";
	cin>>number;
	for(n=0; n<=p; n++)
	{
		if(strcmp(bus[n].busn, number)==0)
			break;
	}
	while(n<=p)
	{
		vline('*');
		cout<<"Bus no: \t"<<bus[n].busn
			<<"\nDriver: \t"<<bus[n].driver<<"\t\tArrival time: \t"
			<<bus[n].arrival<<"\tDeparture time:"<<bus[n].depart
			<<"\nFrom: \t\t"<<bus[n].from<<"\t\tTo: \t\t"<<
			bus[n].to<<"\n";
		vline('*');
		bus[0].position(n);
		int a=1;
		for (int i=0; i<8; i++)
		{
			for(int j=0; j<4; j++)
			{
				a++;
				if(strcmp(bus[n].seat[i][j],"Empty")!=0)
					cout<<"\nThe seat no "<<(a-1)<<" is reserved for "<<bus[n].seat[i][j]<<".";
			}
		}
		break;
	}
	if(n>p)
		cout<<"Enter correct bus no: ";
}
void a::position(int l)
{
	int s=0;
   p=0;
	for (int i =0; i<8; i++)
	{
		cout<<"\n";
		for (int j = 0; j<4; j++)
		{
			s++;
			if(strcmp(bus[l].seat[i][j], "Empty")==0)
			{
				cout.width(5);
				cout.fill(' ');
				cout<<s<<".";
				cout.width(10);
				cout.fill(' ');
				cout<<bus[l].seat[i][j];
				p++;
			}
			else
			{
				cout.width(5);
				cout.fill(' ');
				cout<<s<<".";
				cout.width(10);
				cout.fill(' ');
				cout<<bus[l].seat[i][j];
			}
		}
	}
	cout<<"\n\nThere are "<<p<<" seats empty in Bus No: "<<bus[l].busn;
}
void a::avail()
{
	for(int n=0; n<p; n++)
	{
		vline('*');
		cout<<"Bus no: \t"<<bus[n].busn<<"\nDriver: \t"<<bus[n].driver
			<<"\t\tArrival time: \t"<<bus[n].arrival<<"\tDeparture Time: \t"
			<<bus[n].depart<<"\nFrom: \t\t"<<bus[n].from<<"\t\tTo: \t\t\t"
			<<bus[n].to<<"\n";
		vline('*');
		vline('_');
	}
}
void a::dispatch()
{
 int driverID[n],nwaiting=0,rear=-1,front=0,terminate=0;
 char command;
  while(terminate==0)
  {

 cout<<"enter d to accomodate\n c to dispatch \n x to exit"<<endl;
cin>>command;
switch(command){
   case 'd':
     if(nwaiting==n)
        cout<<"queue is full.....no bus can be accommodated. try again later.\n";
     else{
            rear=(rear+1)%n;
            cout<<"enter driver id"<<endl;
      cin>>driverID[rear];
      nwaiting++;
      cout<<"bus accomodated"<<endl;
      int k=front;
      cout<<"available :\n";
      for(int j=0;j<nwaiting;j++)
      {
          cout<<driverID[k]<<"\t";
          k=(k+1)%n;
      }
      cout<<endl;
     }
     break;
  case 'c':
        if(nwaiting==0) cout<<"no bus is available .......try again later\n";

     	else{
     		cout<<"Assigning: " << driverID[front]<<endl;
     		front=(front+1)%n;
     		nwaiting--;
     		int k=front;
      cout<<"available :\n";
      for(int j=0;j<nwaiting;j++)
      {
          cout<<driverID[k]<<"\t";
          k=(k+1)%n;
      }
   cout<<endl;
     	}
     	break;
  case 'x':terminate=1;
  break;
    default: cout <<"illegal command \n";
}
}
}

int main()
{
	system("cls");
	int w;
	int i,j,o;
	char name[20];
	while(1)
	{
//system("cls");
		cout<<"\n\n\n\n\n";
		cout<<"\t\t\t1.Install\n\t\t\t"
			<<"2.Reservation\n\t\t\t"
			<<"3.Show\n\t\t\t"
			<<"4.Buses Available. \n\t\t\t"
			<<"5. Cargo\n\t\t\t"
			<<"6. dispatch\n\t\t\t"
			<<"7.prepare chart\n\t\t\t"

			<<"8.Read chart information from file\n\t\t\t"

			<<"9.Exit";
		cout<<"\n\t\t\tEnter your choice:-> ";
		cin>>w;
		switch(w)
		{
		case 1:
		   bus[p].install();
			break;
		case 2:
		   bus[p].allotment();
			break;
		case 3:
		   bus[0].show();
			break;
		case 4:
		   bus[0].avail();
			break;
			case 5:bus[0].cargo();
			break;
			case 6:bus[0].dispatch();
			break;

		case 7:
			cout<<"enter name of file:"<<endl;
			cin>>name;
			cout<<"enter bus details"<<endl;
			bus[0].install(name);
			cout<<"enter passenger details"<<endl;
			while(1)
			{cout<<"enter passenger number, 999 to stop"<<endl;
			cin>>j;
			if(j==999)
                break;
			bus[0].allotment(name);
			}
            cout<<"enter cargo details"<<endl;
            bus[0].cargo(name);
			break;
		case 8:
		    string str;
		    cout<<"enter name of file"<<endl;
		cin>>name;
		ifstream rinfo(name);
		while(getline(rinfo,str))
            {cout<<str<<endl;
            }
            rinfo.close();
            break;



	}}
	return 0;
}


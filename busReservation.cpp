#include<conio.h>
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<cstdlib>
using namespace std;
int p=0;
class busRes{
    char busno[5],driver[15],arrival[5],departure[5],from[15],to[15],seat[8][4][10];
public:
    void install();
    void allotment();
    void empty();
    void show();
    void avail();
    void position(int i);
} bus[10];
    void vline(char ch){
    for(int i=80;i>0;i--)
        cout<<ch;
}

    void busRes::install(){
        cout<<"Enter bus no.: ";
        cin>>bus[p].busno;
        cout<<"\nEnter driver's name: ";
        cin>>bus[p].driver;
        cout<<"\nEnter arrival time: ";
        cin>>bus[p].arrival;
        cout<<"\nDeparture: ";
        cin>>bus[p].departure;
        cout<<"\n From: ";
        cin>>bus[p].from;
        cout<<"\n To: ";
        cin>>bus[p].to;
        bus[p].empty();
        p++;
    }
    void busRes::allotment(){
        int seat;
        char number[5];
        top:
            cout<<"Bus no. : ";
            cin>>number;
            int n;
            for(n=0;n<=p;n++){
                if(strcmp(bus[n].busno,number)==0)
                    break;
            }
            while(n<=p){
                cout<<"\n Seat number: ";
                cin>>seat;
                if(seat>32){
                    cout<<"\nEnter valid seat number.(seat number must be less than 32)";
                }
                else{
                    if(strcmp(bus[n].seat[seat/4][(seat%4)-1],"Empty")==0){
                            cout<<"Enter Passenger's name: ";
                    cin>>bus[n].seat[seat/4][(seat%4)-1];
                    break;
                    }
                    else{
                        cout<<"The Given Seat Number is already Booked!!."<<endl;
                    }
                }
            }
                if(n>p){
                    cout<<"Enter Correct Bus number."<<endl;
                    goto top;
                }
    }

    void busRes::empty(){
        for(int i=0;i<8;i++){
            for(int j=0;j<4;){
                strcpy(bus[p].seat[i][j],"Empty");
            }
        }
   }

   void busRes::show(){
       int n;
       char number[5];
       cout<<"Enter Bus no.: ";
       cin>>number;
       for(n=0;n<=p;n++){
        if(strcmp(bus[n].busno,number)==0)
            break;
       }
       while(n<=p){
        vline('"');
        cout<<"Bus no:\t"<<bus[n].busno<<"\nDriver:\t"<<bus[n].driver<<"\tArrival Time: "<<bus[n].arrival<<"\tDeparture time:"<<bus[n].departure<<"\nFrom: "<<bus[n].from<<"\n To: "<<bus[n].to<<endl;
        vline('"');
        bus[0].position(n);
        int a=1;
        for(int i=0;i<8;i++){
            for(int j=0;j<4;j++){
                a++;
                if(strcmp(bus[n].seat[i][j],"Empty")!=0)
                    cout<<"\nThe seat no"<<(a-1)<<"is reserved "<<bus[n].seat[i][j]<<".";
            }
        }
         break;
       }
       if(n>p)
        cout<<"Enter correct Bus No.";
   }

   void busRes::position(int){
       int s=0,p=0;
       for(int i=0;i<8;i++){
        cout<<"\n";
        for(int j=0;j<4;j++){
            s++;
            if(strcmp(bus[1].seat[i][j],"Empty")==0){
                cout.width(s);
                cout.fill(' ');
                cout<<s<<".";
                cout.width(10);
                cout.fill(' ');
                cout<<bus[1].seat[i][j];
            p++;
            }
            else{
                cout.width(s);
                cout.fill(' ');
                cout<<s<<".";
                cout.width(10);
                cout.fill(' ');
                cout<<bus[1].seat[i][j];
            }
        }
       }
       cout<<"\nThere are "<<p<<"seats available in Bus:"<<bus[1].busno<<"(bus number)";
   }

   void busRes::avail(){
       for(int n=0;n<p;n++){
        vline('*');
        cout<<"Bus no:\t"<<bus[n].busno<<"\nDriver:\t"<<bus[n].driver<<"\tArrival Time: "<<bus[n].arrival<<
        "\tDeparture time:"<<bus[n].departure<<"\nFrom: "<<bus[n].from<<"\n To: "<<bus[n].to<<endl;
        vline('*');
       }
   }
int main(){
system("cls");
int choice;
while(1){
    cout<<"Enter Your Choice:"<<endl;
    cout<<"1.Installation"<<endl;
    cout<<"2.Reservation"<<endl;
    cout<<"3.Show"<<endl;
    cout<<"4.Buses Available"<<endl;
    cout<<"5.Exit"<<endl;
    cin>>choice;
    switch(choice){
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
    case 5:
        exit(0);
    }
}
return 0;
}

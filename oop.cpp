#include<iostream>
#include<iomanip>
using namespace std;
class Time{
    int h,m,s,sec;
    public:
    void input(){
    cout<<"Enter time:"<<"\nHours? ";
    cin>>h;
    cout<<"Minutes? ";
    cin>>m;
    cout<<"Seconds? ";
    cin>>s;
    }
    void display(){
    cout<<"The time is = "<<setw(2)<<setfill('0')<<h<<":"<<setw(2)<<setfill('0')<<m<<":"<<setw(2)<<setfill('0')<<s;
    }
    void seconds(){
        sec=(h*3600)+(m*60)+s;
        cout<<"\nTime in total seconds: "<<sec;
    }
};
int main(){
    Time t;
    t.input();
    t.display();
    t.seconds();
    return 0;
}

#include<iostream>;
using namespace std;
void check(int n){
    (n>=18)?cout<<"YOU ARE ELIGIBLE TO VOTE!CAST YOUR VOTE:)":cout<<"YOU ARE NOT ELIGIBLE TO VOTE!DON'T WORRY CAST YOUR VOTE AFTER"<<18-n<<"YEAR!";
}
int main(){
    int age;
    cout<<"ENTER YOUR AGE: ";
    cin>>age;
    check(age);
return 0;
}

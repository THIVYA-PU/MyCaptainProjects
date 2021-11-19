#include<iostream>
using namespace std;
int main(){
    int i;
    int *p;
    int arr[5];
    cout<<"Enter elements: ";
    for(i=0;i<5;i++){
        cin>>arr[i];
    }
    p=arr;
    cout<<"\nYou entered: ";
    for(i=0;i<5;i++){
        cout<<*p<<endl;
        p++;
    }
return 0;
}

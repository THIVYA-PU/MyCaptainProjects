#include<iostream>
using namespace std;
int checkPrime(int x){
    for(int i=2;i<x;i++){
        if(x%i==0){
            return 0;
        }
    }
    return 1;
}
int main(){
    int n,a[15],i,j=0,tot=0;
    cout<<"Enter a positive integer:";
    cin>>n;
    for(i=2;i<=n;i++){
    if(checkPrime(i)){
       a[j]=i;
        j++;
        tot++;
        }
    }
    for(i=0;i<tot;i++){
        for(j=i;j<tot;j++){
            if((a[i]+a[j])==n){
                cout<<n<<"="<<a[i]<<"+"<<a[j]<<endl;
        }
    }
    }
return 0;
}


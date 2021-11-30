#include<conio.h>
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<iomanip>
using namespace std;
int main(){
    FILE *ptr1,*ptr2;
    char another,choice;

    struct student{
        char first_name[25],last_name[25];
        char course[20];
        int section;
    };
    struct student e;
    char xfirst_name[25],xlast_name[25];
    long int record_size;
    ptr1=fopen("users.txt","rb+");
    if(ptr1==NULL){
        ptr1=fopen("users.txt","wb+");
        if(ptr1==NULL){
            cout<<"Can't open File";
            return 0;
        }
    }
    record_size=sizeof(e);
    while(1){
        system("cls");
        cout<<"List of operations:"<<endl;
        cout<<"\n1.Add Records";
        cout<<"\n2.List Records";
        cout<<"\n3.Modify Records";
        cout<<"\n4.Delete Records";
        cout<<"\n5.Exit";
        cout<<"\nEnter Your Choice: ";
        fflush(stdin);
        choice=getche();
        switch(choice){
        case '1':
            fseek(ptr1,0,SEEK_END);
            another='Y';
            while(another=='Y'||another=='y'){
                system("cls");
                cout<<"ENTER FIRST NAME:";
                cin>>e.first_name;
                cout<<"ENTER LAST NAME:";
                cin>>e.last_name;
                cout<<"ENTER COURSE:";
                cin>>e.course;
                cout<<"ENTER SECTION:";
                cin>>e.section;
                fwrite(&e,record_size,1,ptr1);
                cout<<"\n DO YOU WANT TO ADD ANOTHER RECORD:"<<endl;
                cout<<"ENTER Y FOR YES, N FOR NO";
                fflush(stdin);
                another=getchar();
            }
            break;
        case '2':
            system("cls");
            rewind(ptr1);
            cout<<"RECORDS IN DATABASE"<<endl;
            while(fread(&e,record_size,1,ptr1)==1){
                cout<<"\n"<<e.first_name<<setw(10)<<e.last_name<<endl;
                cout<<"\n"<<e.course<<setw(8)<<e.section<<endl;;
            }
            system("pause");
            break;
        case '3':
            system("cls");
            another='Y';
            while(another=='Y'||another=='y'){
            cout<<"ENTER LAST NAME OF STUDENT:";
            cin>>xlast_name;
            rewind(ptr1);
            while(fread(&e,record_size,1,ptr1)==1){
                if(strcmp(e.last_name,xlast_name)==0){
                cout<<"ENTER THE NEW FIRST NAME:";
                cin>>e.first_name;
                cout<<"ENTER THE NEW LAST NAME:";
                cin>>e.last_name;
                cout<<"ENTER THE NEW COURSE:";
                cin>>e.course;
                cout<<"ENTER THE NEW SECTION:";
                cin>>e.section;
                fseek(ptr1,-record_size,SEEK_CUR);
                fwrite(&e,record_size,1,ptr1);
                break;
                }
                else
                    cout<<"RECORD NOT FOUND";
            }
            cout<<"\n DO YOU WANT TO MODIFY ANOTHER RECORD:"<<endl;
                cout<<"ENTER Y FOR YES, N FOR NO";
                fflush(stdin);
                another=getchar();
            }
            break;
        case '4':
            system("cls");
            another='Y';
            while(another=='Y'||another=='y'){
                cout<<"ENTER LAST NAME OF STUDENT TO DELETE:";
                cin>>xlast_name;
                ptr2=fopen("temp.dat","wb+");
                rewind(ptr1);
                while(fread(&e,record_size,1,ptr1)==1){
                if(strcmp(e.last_name,xlast_name)!=0){
                        fwrite(&e,record_size,1,ptr2);
                }
                }
                fclose(ptr1);
                fclose(ptr2);
                remove("users.txt");
                rename("temp.dat","users.txt");
                ptr1=fopen("users.txt","rb+");
                cout<<"\n DO YOU WANT TO DELETE ANOTHER RECORD:"<<endl;
                cout<<"ENTER Y FOR YES, N FOR NO";
                fflush(stdin);
                another=getchar();
            }
                break;
        case '5':
            fclose(ptr1);
            exit(0);
        }
    }
    system("pause");
    return 0;
}

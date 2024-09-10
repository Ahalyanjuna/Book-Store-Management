#include<iostream>
#include<fstream>
#include<string>
#include<ctime>
#include<iomanip>
#include"classdefinitions.h"

using namespace std;

int main()
{
    int u,cont;
    Admin a;
    BillingStaff bb;

    do
    {
        system("cls");
        cout<<" -----------------------------------------------------------------------"<<endl;
        cout<<"|                                                                       |"<<endl;
        cout<<"|                                                                       |"<<endl;
        cout<<"|                         BOOK STORE MANAGEMENT                         |"<<endl;
        cout<<"|                                                                       |"<<endl;
        cout<<"|        By  Ahalyanjuna.S 22PD02         Mokshitha.K  22PD17           |"<<endl;
        cout<<"|                                                                       |"<<endl;
        cout<<"|                                                                       |"<<endl;
        cout<<" -----------------------------------------------------------------------"<<endl;
        cout<<"MAIN MENU\n[1]Admin\n[2]Billing staff\nPress -1 to exit\n";
        cout<<"Enter the user\n";
        cin>>u;
        switch(u)
        {
            case 1:
                a.menu1();
                break;
            case 2:
                bb.menu6();
                break;
            case -1:
                cout<<"Exiting........\n";
                exit(1);
            default:
                cout<<"Invalid Entry\n";
                break;
        }
        //cout<<"Do you want to continue in the system?\n[1]Yes\n[2]No\n";
        //cin>>cont;
    }
    while(u!=-1);
}


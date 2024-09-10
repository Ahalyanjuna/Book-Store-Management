#include<iostream>
#include<fstream>
#include<string>
#include<string.h>
#include<chrono>
#include<ctime>
#include<iomanip>
#include<conio.h>
#include"classdefinitions.h"

using namespace std;

struct copysale
{
    int g1,g2,g3;
    long long int a[50];
    float t;
};

struct copypur
{
    int g1,g2,g3;
    int ii;
    long long int a[50];
    float t;
};

//To validate date
int leap(int year)
{
    if (year % 400 == 0)
        return 1;
    else if (year % 100 == 0)
        return 0;
   else if (year % 4 == 0)
        return 1;
   else
        return 0;
}

int isvalidDate(int dd,int mm,int yy)
{
    if(yy>=1900 && yy<=9999)
    {
        if(mm>=1 && mm<=12)
        {
            if((dd>=1 && dd<=31) && (mm==1 || mm==3 || mm==5 || mm==7 || mm==8 || mm==10 || mm==12))
                return 1;
            else if((dd>=1 && dd<=30) && (mm==4 || mm==6 || mm==9 || mm==11))
                return 1;
            else if((dd>=1 && dd<=28) && (mm==2))
                return 1;
            else if(dd==29 && mm==2 && (leap(yy)==1))
                return 1;
            else
                return 0;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}

void Address::read()
{
    cout<<"Enter Address\n";
    cout<<"Door No. : ";
    cin.ignore();
    cin.getline(doorno,5);
    cout<<"Street : ";
    cin.getline(street,15);
    cout<<"Area : ";
    cin.getline(area,30);
    cout<<"City : ";
    cin.getline(city,25);
    cout<<"State : ";
    cin.getline(state,25);
    cout<<"Pin code : ";
    cin>>pincode;
    string p=to_string(pincode);
    if(p.length()!=6)
    {
        do
        {
            cout<<"Invalid Pin code\nEnter valid pin code of length 6\n";
            cin>>pincode;
            p=to_string(pincode);
        }
        while(p.length()!=6);
    }
}

void Address::display()
{
    cout<<"Address\n";
    cout<<"Door No. : "<<doorno<<endl;
    cout<<"Street   : "<<street<<endl;
    cout<<"Area     : "<<area<<endl;
    cout<<"City     : "<<city<<endl;
    cout<<"State    : "<<state<<endl;
    cout<<"Pin code : "<<pincode<<endl;
}

void Book::display()
{
    cout<<"Book ISBN: "<<ISBN<<endl;
    cout<<"Title : "<<bookTitle<<endl;
    cout<<"Author : "<<author<<endl;
    cout<<"Publication : "<<PublicationName<<endl;
    cout<<"Year of Publication : "<<year<<endl;
    cout<<"Cost of a book : Rs."<<unitCost<<endl;
    cout<<"Number of books available : "<<no<<endl;
}

void Book::read()
{
    cout<<"Enter ISBN\n";
    cin>>ISBN;
    string k=to_string(ISBN);
    if(k.length()!=13)
    {
        do
        {
            cout<<"Enter valid ISBN of length 13\n";
            cin>>ISBN;
            k=to_string(ISBN);
        }
        while(k.length()!=13);
    }
    cout<<"Enter Book title\n";
    cin.ignore();
    cin.getline(bookTitle,50);
    cout<<"Enter Author\n";
    cin.getline(author,40);
    cout<<"Enter Publication \n";
    cin.getline(PublicationName,50);
    cout<<"Enter year of publication\n";
    cin>>year;
    if(!(year>=1900 && year<=2023))
    {
        do
        {
            cout<<"Invalid year\nEnter appropriate year\n";
            cin>>year;
        }
        while(!(year>=1900 && year<=2023));
    }
    cout<<"Enter cost of a book\n";
    cin>>unitCost;
    if(unitCost<=0)
    {
        do
        {
            cout<<"Invalid cost\nEnter valid value\n";
            cin>>unitCost;
        }
        while(unitCost<=0);
    }
}


void Customer::display()
{
    cout<<"Customer Details : \n";
    cout<<"Name : ";
    cout<<customerName;
    cout<<endl;
    a.display();
    cout<<"Phone no. : ";
    cout<<phone;
    cout<<endl;
    cout<<"Mail Id : ";
    cout<<email;
    cout<<endl;
}

void Customer::read(long int g)
{
    cout<<"Enter Customer name\n";
    cin.ignore();
    cin.getline(customerName,30);
    for(int i=0;i<strlen(customerName);i++)
        {
            char ch=customerName[i];
            if(!(isalpha(ch))&&(ch!=32&&ch!='.'))
            {
                do
                {
                    cout<<"Enter appropriate name\nEnter name \n";
                    cin.getline(customerName,30);
                    ch=customerName[i];
                }
                while(!(isalpha(ch))&&(ch!=32&&ch!='.'));

            }
        }
    a.read();
    this->set_phone(g);
    cout<<"Enter Mail Id\n";
    cin.ignore();
    cin.getline(email,50);
}

int Customer::isValidcusno(long int c)
{
    fstream file;
    Customer cc;
    int flag=0;
    file.open("customer1.txt",ios::in);
    if(file.eof())
    {
        cout<<"Error in opening file\n";
        return -1;
    }
    file.read((char*)&cc,sizeof(cc));
    while(!file.eof())
    {
        if(c==cc.get_ph())
            flag=1;
        file.read((char*)&cc,sizeof(cc));
    }
    file.close();
    if(flag==0)
        return 1;
    else
        return 0;
}

int Customer::add_customers()
{
    Customer c;
    fstream file;
    long long int ph;
    int get;
    cout<<"Enter phone number of customer\n";
    cin>>ph;
    string p=to_string(ph);
    if(p.length()!=10)
    {
        do
        {
            cout<<"Invalid Phone number\nEnter valid phone number of length 10\n";
            cin>>ph;
            p=to_string(ph);
        }
        while(p.length()!=10);
    }
    get=isValidcusno(ph);
    int fl=0;
    file.open("customer1.txt",ios::in|ios::out);
    if(file.eof())
    {
       cout<<"Cannot open the file"<<endl;
       return 1;
    }
    if(get==1){
    c.read(ph);
    file.seekp(0,ios::end);
    file.write((char*)&c,sizeof(c));}
    else
        cout<<"Customer data is stored already\nYou can proceed to billing\n";
    file.close();
    return 0;
}

void Customer::display_customers()
{
        Customer c;
        int flag=0;
        fstream file;
        file.open("customer1.txt",ios::in);
        if(file.eof())
        {
            cout<<"Error in opening the file"<<endl;
        }
        cout<<"The contents in the file:"<<endl;
        file.read((char*)&c,sizeof(c));

        while(!file.eof())
        {
                flag=1;
                c.display();
                file.read((char*)&c,sizeof(c));
        }
        if(flag==0)
            cout<<"No customer data exits\n";

}

int Customer::csearch()
{
    long long int ph;
    int flag=0;
    Customer c;
    cout<<"Enter the phone no.:";
    cin>>ph;
    string p=to_string(ph);
    if(p.length()!=10)
    {
        do
        {
            cout<<"Invalid Phone number\nEnter valid phone number of length 10\n";
            cin>>ph;
            p=to_string(ph);
        }
        while(p.length()!=10);
    }
    fstream file;
    file.open("customer1.txt",ios::in);
    if(file.eof())
    {
        cout<<"Error in opening the file"<<endl;
    }
    file.read((char*)&c,sizeof(c));
    while(!file.eof())
    {
      if(c.get_ph()==ph)
      {
         cout<<"Found"<<endl;
         c.display();
         flag=1;
        break;
      }
        file.read((char*)&c,sizeof(c));
    }
    file.close();
    if(flag==0)
    {
       cout<<"Not found in the file"<<endl;
    }
    return 1;
}

void Customer::remove_customers()
{
        int flag=0;
        long long int ph;
        Customer s;
        fstream file1("customer1.txt" , ios::binary |ios::in);
        fstream file2("customer_d1.txt" , ios::binary |ios::out);
        file1.seekg(0);
        if(!file1 || !file2)
        {
            cout<<"Error in opening file"<<endl;
        }
        else
        {
            cout<<"Enter Phone no.\n";
            cin>>ph;
            string p=to_string(ph);
            if(p.length()!=10)
            {
                do
                {
                    cout<<"Invalid Phone number\nEnter valid phone number of length 10\n";
                    cin>>ph;
                    p=to_string(ph);
                }
                while(p.length()!=10);
            }
            while( file1.read((char*)&s,sizeof(s)) )
            {
                if(s.get_ph()!=ph)
                {
                    file2.write((char *)&s,sizeof(s));
                }
                else
                {
                    flag=1;
                }
            }
            file1.close();
            file2.close();
            remove("customer1.txt");
            rename("customer_d1.txt","customer1.txt");
        }
        if(flag==0)
        {
            cout<<"Record doesn't exist"<<endl;
        }
}

void Customer::update_customers()
{
        int choice,ch;
        Customer c;
        char another,a1;
        long long int ph;
        cout<<"Enter Phone no\n";
        cin>>ph;
        string p=to_string(ph);
        if(p.length()!=10)
        {
            do
            {
                cout<<"Invalid Phone number\nEnter valid phone number of length 10\n";
                cin>>ph;
                p=to_string(ph);
            }
            while(p.length()!=10);
        }
        int pos, flag = 0;
        fstream fs;
        fs.open("customer1.txt",ios::in |  ios::out);
        if(fs.eof())
        {
            cout<<"Error in opening the file"<<endl;
        }
        while (!fs.eof())
        {
           pos = fs.tellg();
           fs.read((char*)&c, sizeof(Customer));
           if(fs){
                if (ph == c.get_ph())
                {
                    flag = 1;
                    do
                    {
                        cout<<"[1]customer Name\n[2]Address\n[3]Phone number\n[4]Email id\nEnter your choice\n";
                        cin>>choice;
                        switch(choice)
                        {
                        case 1:
                            char n[30];
                            cout<<"Enter customer new name : \n";
                            cin.ignore();
                            cin.getline(n,30);
                            for(int i=0;i<strlen(n);i++)
                            {
                                char ch1=n[i];
                                if(!(isalpha(ch1))&&(ch1!=32&&ch1!='.'))
                                {
                                    do
                                    {
                                        cout<<"Enter appropriate name\nEnter name \n";
                                        cin.getline(n,30);
                                        ch1=n[i];
                                    }
                                    while(!(isalpha(ch1))&&(ch1!=32&&ch1!='.'));

                                }
                            }
                            c.set_customerName(n);
                            break;
                        case 2:
                            do
                            {
                                cout<<"[1]Door no.\n[2]Street\n[3]Area\n[4]City\n[5]State\n[6]Pin code\nEnter your choice\n";
                                cin>>ch;
                                switch(ch)
                                {
                                    case 1:
                                        char aa[5];
                                        cout<<"Enter new door no. \n";
                                        cin.ignore();
                                        cin.getline(aa,5);
                                        c.set_doorno(aa);
                                        break;
                                    case 2:
                                        char bb[15];
                                        cout<<"Enter new Street name\n";
                                        cin.ignore();
                                        cin.getline(bb,15);
                                        c.set_street(bb);
                                        break;
                                    case 3:
                                        char cc[30];
                                        cout<<"Enter new Area name\n";
                                        cin.ignore();
                                        cin.getline(cc,30);
                                        c.set_area(cc);
                                        break;
                                    case 4:
                                        char dd[25];
                                        cout<<"Enter new city name\n";
                                        cin.ignore();
                                        cin.getline(dd,25);
                                        c.set_city(dd);
                                        break;
                                    case 5:
                                        char n1[25];
                                        cout<<"Enter new State name\n";
                                        cin.ignore();
                                        cin.getline(n1,25);
                                        c.set_state(n1);
                                        break;
                                    case 6:
                                        int d;
                                        cout<<"Enter new Pincode\n";
                                        cin>>d;
                                        string p1=to_string(d);
                                        if(p1.length()!=6)
                                        {
                                            do
                                            {
                                                cout<<"Invalid Pin code\nEnter valid pin code of length 6\n";
                                                cin>>d;
                                                p1=to_string(d);
                                            }
                                            while(p1.length()!=6);
                                        }
                                        c.set_pincode(d);
                                        break;
                                }
                                cout<<"Do you want to modify another address detail?[y/n]\n";
                                cin.ignore();
                                cin>>a1;
                            }
                            while(a1=='y'||a1=='Y');
                            break;
                        case 3:
                        {
                            long long int h;
                            cout<<"Enter new Phone number\n";
                            cin>>h;
                            string p=to_string(h);
                            if(p.length()!=10)
                            {
                                do
                                {
                                    cout<<"Invalid Phone number\nEnter valid phone number of length 10\n";
                                    cin>>h;
                                    p=to_string(h);
                                }
                                while(p.length()!=10);
                            }
                            c.set_phone(h);
                            break;}
                        case 4:
                            char n11[50];
                            cout<<"Enter customer new Email id\n";
                            cin.ignore();
                            cin.getline(n11,50);
                            c.set_email(n11);
                            break;
                    }
                    cout<<"Do you want to modify another detail?[y/n]\n";
                    cin>>another;
                }
                while(another=='y'||another=='Y');
                fs.seekp(pos);
                fs.write((char*)&c, sizeof(Customer));
                break;
            }
           }
        }
        fs.close();
    if (flag == 1)
        cout << "\nRecord successfully modified \n";
    else
        cout << "\nRecord not found \n";
}




int Employee::add_employee()
{
    Employee e;
    fstream file;
    file.open("employee4.txt",ios::app);
    if(file.eof())
    {
       cerr<<"Cannot open the file"<<endl;
       return 1;
    }
    e.read();
    file.write((char*)&e,sizeof(e));
    file.seekg(0);
    file.close();
}

void Employee::display_employee()
{
        Employee e;
        fstream file;
        int flag=0;
        file.open("employee4.txt",ios::in);
        if(file.eof())
        {
            cout<<"Error in opening the file"<<endl;
        }
        cout<<"The contents in the file:"<<endl;
        file.read((char*)&e,sizeof(e));
        while(!file.eof())
        {
            flag=1;
            e.display();
            file.read((char*)&e,sizeof(e));
        }
        if(flag==0)
            cout<<"No employee data exists\n";

}

int Employee::esearch()
{
    int empid;
    int flag=0;
    Employee e;
    cout<<"Enter Employee id:";
    cin>>empid;
    fstream file;
    file.open("employee4.txt",ios::in);
    if(file.eof())
    {
        cout<<"Error in opening the file"<<endl;
    }
    file.read((char*)&e,sizeof(e));
    while(!file.eof())
    {
      if(e.get_empid()==empid)
      {
         cout<<"Found"<<endl;
         e.display();
         flag=1;
         break;
      }
        file.read((char*)&e,sizeof(e));
    }
    file.close();
    if(flag==0)
    {
       cout<<"Not found in the file"<<endl;
    }
    return 1;
}

void Employee::remove_employee()
{
        int empid,flag=0;
        Employee e;
        fstream file1("employee4.txt" ,ios::in);
        fstream file2("employee_d4.txt" ,ios::out);
        file1.seekg(0);
        if(!file1 || !file2)
        {
            cout<<"Error in opening file"<<endl;
        }
        else
        {
            cout<<"Enter employee id\n";
            cin>>empid;
            while( file1.read((char*)&e,sizeof(e)) )
            {
                if(e.get_empid()!=empid)
                {
                    file2.write((char *)&e,sizeof(e));
                }
                else
                {
                    flag=1;
                }
            }
            file1.close();
            file2.close();
            remove("employee4.txt");
            rename("employee_d4.txt","employee4.txt");
        }
        if(flag==0)
        {
            cout<<"Record doesn't exist"<<endl;
        }
        else
            cout<<"Record removed successfully\n";
}

void Employee::update_employee()
{
        char another,a1;
        int choice,ch;
        Employee e;
        long int ph;
        cout<<"Enter employee id\n";
        cin>>empid;
        int pos, flag = 0;
        fstream fs;
        fs.open("employee4.txt",ios::in |  ios::out);
        if(fs.eof())
        {
            cout<<"Error in opening the file"<<endl;
        }
        while (!fs.eof())
        {
           pos = fs.tellg();
           fs.read((char*)&e, sizeof(Employee));
           if (fs)
           {
            if (empid == e.get_empid())
            {
                flag = 1;
                do
            {
                cout<<"[1]Employee Name\n[2]Address\n[3]Phone number\n[4]Email id\n[5]Salary\n[6]Date of birth\n[7]Date of joining\nEnter your choice\n";
                cin>>choice;
                switch(choice)
                {
                case 1:
                    char n[30];
                    cout<<"Enter employee new name : \n";
                    cin.ignore();
                    cin.getline(n,30);
                    for(int i=0;i<strlen(n);i++)
                    {
                        char ch1=n[i];
                        if(!(isalpha(ch1))&&(ch1!=32&&ch1!='.'))
                        {
                            do
                            {
                                cout<<"Enter appropriate name\nEnter name \n";
                                cin.getline(n,30);
                                ch1=n[i];
                            }
                            while(!(isalpha(ch1))&&(ch1!=32&&ch1!='.'));
                        }
                    }
                    e.set_empName(n);
                    break;
                case 2:
                            do
                            {
                                cout<<"[1]Door no.\n[2]Street\n[3]Area\n[4]City\n[5]State\n[6]Pin code\nEnter your choice\n";
                                cin>>ch;
                                switch(ch)
                                {
                                    case 1:
                                        char aa[5];
                                        cout<<"Enter new door no. \n";
                                        cin.ignore();
                                        cin.getline(aa,5);
                                        e.set_doorno(aa);
                                        break;
                                    case 2:
                                        char bb[15];
                                        cout<<"Enter new Street name\n";
                                        cin.ignore();
                                        cin.getline(bb,15);
                                        e.set_street(bb);
                                        break;
                                    case 3:
                                        char cc[30];
                                        cout<<"Enter new Area name\n";
                                        cin.ignore();
                                        cin.getline(cc,30);
                                        e.set_area(cc);
                                        break;
                                    case 4:
                                        char dd[25];
                                        cout<<"Enter new city name\n";
                                        cin.ignore();
                                        cin.getline(dd,25);
                                        e.set_city(dd);
                                        break;
                                    case 5:
                                        char ee[25];
                                        cout<<"Enter new State name\n";
                                        cin.ignore();
                                        cin.getline(ee,25);
                                        e.set_state(ee);
                                        break;
                                    case 6:
                                        int d;
                                        cout<<"Enter new Pincode\n";
                                        cin>>d;
                                        string p1=to_string(d);
                                        if(p1.length()!=6)
                                        {
                                            do
                                            {
                                                cout<<"Invalid Pin code\nEnter valid pin code of length 6\n";
                                                cin>>d;
                                                p1=to_string(d);
                                            }
                                            while(p1.length()!=6);
                                        }
                                        e.set_pincode(d);
                                        break;
                                }
                                cout<<"Do you want to modify another address detail?[y/n]\n";
                                cin>>a1;
                            }
                            while(a1=='y'||a1=='Y');
                            break;
                case 3:
                    {long long int h;
                    cout<<"Enter new Phone number\n";
                    cin>>h;
                    string p=to_string(h);
                    if(p.length()!=10)
                    {
                        do
                        {
                            cout<<"Invalid Phone number\nEnter valid phone number of length 10\n";
                            cin>>h;
                            p=to_string(h);
                        }
                        while(p.length()!=10);
                    }
                    e.set_phone(h);
                    break;}
                case 4:
                    char nn[50];
                    cout<<"Enter Employee new Email id\n";
                    cin.ignore();
                    cin.getline(nn,50);
                    e.set_email(nn);
                    break;
                case 5:
                    float b;
                    cout<<"Enter Employee new salary\n";
                    cin>>b;
                    if(b<=0)
                    {
                        do
                        {
                            cout<<"Invalid Amount\nEnter valid salary\n";
                            cin>>b;
                        }
                        while(b<=0);
                    }
                    e.set_bsalary(b);
                    break;
                case 6:
                    int d,m,y;
                    cout<<"Enter Date of birth details:"<<endl;
                    cout<<"Enter date\n";
                    cin>>d;
                    cout<<"Enter month\n";
                    cin>>m;
                    cout<<"Enter year\n";
                    cin>>y;
                    e.set_dob(d,m,y);
                    break;
                case 7:
                    int d1,m1,y1;
                    cout<<"Enter Date of joining details:"<<endl;
                    cout<<"Enter date\n";
                    cin>>d1;
                    cout<<"Enter month\n";
                    cin>>m1;
                    cout<<"Enter year\n";
                    cin>>y1;
                    e.set_doj(d1,m1,y1);
                    break;
                }
                cout<<"Do you want to modify another detail?[y/n]\n";
                //cin.ignore();
                cin>>another;
            }
            while(another=='y'||another=='Y');
            fs.seekp(pos);
            fs.write((char*)&e, sizeof(Employee));
            break;
            }
           }
        }
        fs.close();
        if (flag == 1)
            cout << "\nRecord successfully modified \n";
        else
            cout << "\nRecord not found \n";
}


int Supplier::add_suppliers()
{
    Supplier s;
    fstream file;
    file.open("supplier1.txt",ios::app);
    if(file.eof())
    {
       cerr<<"Cannot open the file"<<endl;
       return 1;
    }
    s.read();
    file.write((char*)&s,sizeof(s));
    file.seekg(0);
    file.close();
}

void Supplier::display_suppliers()
{
        Supplier s;
        fstream file;
        int flag=0;
        file.open("supplier1.txt",ios::in);
        if(file.eof())
        {
            cout<<"Error in opening the file"<<endl;
        }
        cout<<"The contents in the file:"<<endl;
        file.read((char*)&s,sizeof(s));
        while(!file.eof())
        {
            flag=1;
            s.display();
            file.read((char*)&s,sizeof(s));
        }
        if(flag==0)
            cout<<"No supplier data exists\n";

}

int Supplier::ssearch()
{
    int supid;
    int flag=0;
    Supplier s;
    cout<<"Enter Supplier id:";
    cin>>supid;
    fstream file;
    file.open("supplier1.txt",ios::in);
    if(file.eof())
    {
        cout<<"Error in opening the file"<<endl;
    }
    file.read((char*)&s,sizeof(s));
    while(!file.eof())
    {
      if(s.get_supid()==supid)
      {
         cout<<"Found"<<endl;
         s.display();
         flag=1;
         break;
      }
        file.read((char*)&s,sizeof(s));
    }
    file.close();
    if(flag==0)
    {
       cout<<"Not found in the file"<<endl;
    }
    return 1;
}

void Supplier::remove_suppliers()
{
        int supid,flag=0;
        Supplier s;
        fstream file1("supplier1.txt" , ios::binary |ios::in);
        fstream file2("supplier_d1.txt" , ios::binary |ios::out);
        file1.seekg(0);
        if(!file1 || !file2)
        {
            cout<<"Error in opening file"<<endl;
        }
        else
        {
            cout<<"Enter Supplier id\n";
            cin>>supid;
            while( file1.read((char*)&s,sizeof(s)) )
            {
                if(s.get_supid()!=supid)
                {
                    file2.write((char *)&s,sizeof(s));
                }
                else
                {
                    flag=1;
                }
            }
            file1.close();
            file2.close();
            remove("supplier1.txt");
            rename("supplier_d1.txt","supplier1.txt");
        }
        if(flag==0)
        {
            cout<<"Record doesn't exist "<<endl;
        }
        cout<<"Record removed successfully\n";
}

void Supplier::update_suppliers()
{
        char another,a1;
        int choice,ch;
        Supplier s;
        cout<<"Enter supplier id\n";
        cin>>supid;
        int pos, flag = 0;
        fstream fs;
        fs.open("supplier1.txt",ios::in |  ios::out);
        if(fs.eof())
        {
            cout<<"Error in opening the file"<<endl;
        }

        while (!fs.eof())
        {
           pos = fs.tellg();
            fs.read((char*)&s, sizeof(Supplier));
            if(fs){
            if (supid == s.get_supid())
            {
                flag = 1;
                do
                {
                    cout<<"[1]Supplier Name\n[2]Address\n[3]Phone number\n[4]Email id\nEnter your choice\n";
                    cin>>choice;
                    switch(choice)
                    {
                        case 1:
                            char n[30];
                            cout<<"Enter supplier new name : \n";
                            cin.ignore();
                            cin.getline(n,30);
                            for(int i=0;i<strlen(n);i++)
                            {
                                char ch1=n[i];
                                if(!(isalpha(ch1))&&(ch1!=32&&ch1!='.'))
                                {
                                    do
                                    {
                                        cout<<"Enter appropriate name\nEnter name \n";
                                        cin.getline(n,30);
                                        ch1=n[i];
                                    }
                                    while(!(isalpha(ch1))&&(ch1!=32&&ch1!='.'));

                                }
                            }
                            s.set_supName(n);
                            break;
                        case 2:
                            do
                            {
                                cout<<"[1]Door no.\n[2]Street\n[3]Area\n[4]City\n[5]State\n[6]Pin code\nEnter your choice\n";
                                cin>>ch;
                                switch(ch)
                                {
                                    case 1:
                                        char aa[5];
                                        cout<<"Enter new door no. \n";
                                        cin.ignore();
                                        cin.getline(aa,5);
                                        s.set_doorno(aa);
                                        break;
                                    case 2:
                                        char bb[15];
                                        cout<<"Enter new Street name\n";
                                        cin.ignore();
                                        cin.getline(bb,15);
                                        s.set_street(bb);
                                        break;
                                    case 3:
                                        char cc[30];
                                        cout<<"Enter new Area name\n";
                                        cin.ignore();
                                        cin.getline(cc,30);
                                        s.set_area(cc);
                                        break;
                                    case 4:
                                        char dd[25];
                                        cout<<"Enter new city name\n";
                                        cin.ignore();
                                        cin.getline(dd,25);
                                        s.set_city(dd);
                                        break;
                                    case 5:
                                        char ee[25];
                                        cout<<"Enter new State name\n";
                                        cin.ignore();
                                        cin.getline(ee,25);
                                        s.set_state(ee);
                                        break;
                                    case 6:
                                        int d;
                                        cout<<"Enter new Pincode\n";
                                        cin>>d;
                                        string p1=to_string(d);
                                        if(p1.length()!=6)
                                        {
                                            do
                                            {
                                                cout<<"Invalid Pin code\nEnter valid pin code of length 6\n";
                                                cin>>d;
                                                p1=to_string(d);
                                            }
                                            while(p1.length()!=6);
                                        }
                                        s.set_pincode(d);
                                        break;
                                }
                                cout<<"Do you want to modify another address detail?[y/n]\n";
                                cin.ignore();
                                cin>>a1;
                            }
                            while(a1=='y'||a1=='Y');
                            break;
                case 3:
                    {long long int h;
                    cout<<"Enter new Phone number\n";
                    cin>>h;
                    string p=to_string(h);
                    if(p.length()!=10)
                    {
                        do
                        {
                            cout<<"Invalid Phone number\nEnter valid phone number of length 10\n";
                            cin>>h;
                            p=to_string(h);
                        }
                        while(p.length()!=10);
                    }
                    s.set_phone(h);
                    break;}
                case 4:
                    char n11[50];
                    cout<<"Enter supplier new Email id\n";
                    cin.ignore();
                    cin.getline(n11,50);
                    s.set_email(n11);
                    break;

            }
                cout<<"Do you want to modify another detail?[y/n]\n";
                cin>>another;
           }
           while(another=='y'||another=='Y');
           fs.seekp(pos);
           fs.write((char*)&s, sizeof(Supplier));
           break;
        }
            }
        }
        fs.close();
        if (flag == 1)
            cout << "\nRecord successfully modified \n";
        else
            cout << "\nRecord not found \n";
}


void date::display()
{
    cout<<d;
    cout<<"/";
    cout<<m;
    cout<<"/";
    cout<<y;
    cout<<"\n";
}
void date::read()
{
    cout<<"Enter day\n";
    cin>>d;
    cout<<"Enter month\n";
    cin>>m;
    cout<<"Enter year\n";
    cin>>y;
    if(isvalidDate(d,m,y)==0)
    {
        do
        {
            cout<<"Invalid Date\n";
            cout<<"Enter day\n";
            cin>>d;
            cout<<"Enter month\n";
            cin>>m;
            cout<<"Enter year\n";
            cin>>y;
        }
        while(isvalidDate(d,m,y)==0);
    }
}

void Employee::display()
{
    cout<<"Employee Name : ";
    cout<<empName;
    cout<<endl;
    cout<<"Employee Id : ";
    cout<<empid;
    cout<<endl;
    a.display();
    cout<<"Phone no. : ";
    cout<<phone;
    cout<<endl;
    cout<<"Mail Id : ";
    cout<<email;
    cout<<endl;
    cout<<"Basic Salary : ";
    cout<<bsalary;
    cout<<endl;
    cout<<"Date of Birth : ";
    dob.display();
    cout<<endl;
    cout<<"Date of joining : ";
    doj.display();
    cout<<endl;
    cout<<"Years of Experience : ";
    cout<<expyr;
    cout<<endl;
}

int Employee::isValidEmpid(int e)
{
    fstream file;
    Employee ee;
    int flag=0;
    file.open("employee4.txt",ios::in);
    if(file.eof())
    {
        cout<<"Error in opening file\n";
        return -1;
    }
    file.read((char*)&ee,sizeof(ee));
    while(!file.eof())
    {
        if(e==ee.get_empid())
            flag=1;
        file.read((char*)&ee,sizeof(ee));
    }
    file.close();
    if(flag==0)
        return 1;
    else
        return 0;
}


void Employee::read()
{
    cout<<"Enter Employee Name\n";
    cin.ignore();
    cin.getline(empName,30);
    for(int i=0;i<strlen(empName);i++)
    {
        char ch1=empName[i];
        if(!(isalpha(ch1))&&(ch1!=32&&ch1!='.'))
        {
            do
            {
                cout<<"Enter appropriate name\nEnter name \n";
                cin.getline(empName,30);
                ch1=empName[i];
            }
            while(!(isalpha(ch1))&&(ch1!=32&&ch1!='.'));
        }
    }
    cout<<"Enter Employee Id\n";
    cin>>empid;
    if(isValidEmpid(empid)==0)
    {
        do
        {
            cout<<"The entered id exists already\nEnter a unique id\n";
            cin>>empid;
        }
        while(isValidEmpid(empid)==0);
    }
    a.read();
    cout<<"Enter Phone no.\n";
    cin>>phone;
    string p=to_string(phone);
    if(p.length()!=10)
    {
        do
        {
            cout<<"Invalid Phone number\nEnter valid phone number of length 10\n";
            cin>>phone;
            p=to_string(phone);
        }
        while(p.length()!=10);
    }
    cout<<"Enter Mail Id\n";
    cin.ignore();
    cin.getline(email,50);
    cout<<"Enter Basic Salary\n";
    cin>>bsalary;
    if(bsalary<=0)
    {
        do
        {
            cout<<"Invalid Amount\nEnter valid salary\n";
            cin>>bsalary;
        }
        while(bsalary<=0);
    }
    cout<<"Enter Date of birth\n";
    dob.read();
    cout<<"Enter Date of joining\n";
    doj.read();
    cout<<"Enter the years of experience : ";
    cin>>expyr;
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    std::tm* now_tm = std::localtime(&now_c);
    int yr= now_tm->tm_year + 1900;
    if(yr-doj.get_year()!=expyr)
    {
        do
        {
            cout<<"Enter valid number\n";
            cin>>expyr;
        }
        while(yr-doj.get_year()!=expyr);
    }
}

void Supplier::display()
{
    cout<<"Supplier Name : ";
    cout<<supName;
    cout<<endl;
    cout<<"Supplier Id : ";
    cout<<supid;
    cout<<endl;
    a.display();
    cout<<"Phone no. : ";
    cout<<phone;
    cout<<endl;
    cout<<"Mail Id : ";
    cout<<email;
    cout<<endl;
}

int Supplier::isValidSupid(int s)
{
    fstream file;
    Supplier ss;
    int flag=0;
    file.open("supplier1.txt",ios::in);
    if(file.eof())
    {
        cout<<"Error in opening file\n";
        return -1;
    }
    file.read((char*)&ss,sizeof(ss));
    while(!file.eof())
    {
        if(s==ss.get_supid())
            flag=1;
        file.read((char*)&ss,sizeof(ss));
    }
    if(flag==0)
        return 1;
    else
        return 0;
}

void Supplier::read()
{
    cout<<"Enter Supplier Name \n";
    cin.ignore();
    cin.getline(supName,30);
    for(int i=0;i<strlen(supName);i++)
    {
        char ch1=supName[i];
        if(!(isalpha(ch1))&&(ch1!=32&&ch1!='.'))
        {
            do
            {
                cout<<"Enter appropriate name\nEnter name \n";
                cin.getline(supName,30);
                ch1=supName[i];
            }
            while(!(isalpha(ch1))&&(ch1!=32&&ch1!='.'));
        }
    }
    cout<<"Enter Supplier Id\n";
    cin>>supid;
    if(isValidSupid(supid)==0)
    {
        do
        {
            cout<<"The entered id exists already\nEnter a unique id\n";
            cin>>supid;
        }
        while(isValidSupid(supid)==0);
    }
    a.read();
    cout<<"Enter Phone no.\n";
    cin>>phone;
    string p=to_string(phone);
    if(p.length()!=10)
    {
        do
        {
            cout<<"Invalid Phone number\nEnter valid phone number of length 10\n";
            cin>>phone;
            p=to_string(phone);
        }
        while(p.length()!=10);
    }
    cout<<"Enter Mail Id\n";
    cin.ignore();
    cin.getline(email,50);
}

int Book::add_newbooks()
{
    Book b;
    fstream file;
    file.open("bookrecord4.txt",ios::app);
    if(file.eof())
    {
        cerr<<"Cannot open the file"<<endl;
        return 1;
    }
    b.read();
    file.write((char*)&b,sizeof(b));
    file.seekg(0);
    file.close();
}

void Book::display_books()
{
    Book b;
    fstream file;
    int flag=0;
    file.open("bookrecord4.txt",ios::in);
    if(file.eof())
    {
        cerr<<"Cannot open the file"<<endl;
        return;
    }
    cout<<"Records in the file:"<<endl;
    file.seekg(0);
    file.read((char*)&b,sizeof(b));
    while(!file.eof())
    {
        flag=1;
        b.display();
        file.read((char*)&b,sizeof(b));}
    if(flag==0)
        cout<<"No book data exists\n";
}

void Book::remove_books()
{
        long long int bid;
        int flag=0;
        Book b;
        fstream file1("bookrecord4.txt" , ios::in);
        fstream file2("bookrecord_d4.txt" ,ios::out);
        file1.seekg(0);
        if(!file1 || !file2)
        {
            cout<<"Error in opening file"<<endl;
        }
        else
        {
            cout<<"Enter ISBN\n";
            cin>>bid;
            while( file1.read((char*)&b,sizeof(b)) )
            {
                if(b.get_ISBN()!=bid)
                {
                    file2.write((char *)&b,sizeof(b));
                }
                else
                {
                    flag=1;
                }
            }
            file1.close();
            file2.close();
            remove("bookrecord4.txt");
            rename("bookrecord_d4.txt","bookrecord4.txt");
        }
        if(flag==0)
        {
            cout<<"Record doesn't exist "<<endl;
        }
        else
            cout<<"Record removed successfully\n";
}

int Book::bsearch()
{
    long long int bid;
    int flag=0;
    Book b;
    cout<<"Enter ISBN:";
    cin>>bid;
    fstream file;
    file.open("bookrecord4.txt",ios::in);
    if(file.eof())
    {
        cout<<"Error in opening the file"<<endl;
    }
    file.read((char*)&b,sizeof(b));
    while(!file.eof())
    {
      if(b.get_ISBN()==bid)
      {
         cout<<"Found"<<endl;
         b.display();
         flag=1;
         break;
      }
        file.read((char*)&b,sizeof(b));
    }
    file.close();
    if(flag==0)
    {
       cout<<"Not found in the file"<<endl;
    }
    return 1;
}

string BillingStaff::get_currentdate()
{
    // Get the current time as a time_t object
    time_t currentTime = std::time(nullptr);

    // Convert the time_t object to a string representation of the local time
    string dateString = std::ctime(&currentTime);
    return dateString;
}

void BillingStaff::sale_books()
{
    fstream f;
    long long int b1,ba[50];
    int n,na[50],i=0,j=1;
    int k,flag=0;
    char another;
    do
    {
        cout<<"Enter ISBN\n";
        cin>>b1;
        cout<<"Enter no. of books\n";
        cin>>n;
        ba[i]=b1;
        na[i]=n;
        cout<<"Do you want to add another book?[y/n]"<<endl;
        cin.ignore();
        cin>>another;
        i++;
    }
    while(another=='y'||another=='Y');
    cout<<"\t\tAM Book Store\n";
    cout<< left<<setw(7) <<"S.no" << setw(30) << "Name of the book" << setw(15) << "Unit Cost" << setw(17) << "No.of Books " << setw(17) << "Cost"<<endl;
    for(k=0;k<i;k++)
    {
        fstream file;
        file.open("bookrecord4.txt",ios::in|ios::out);
        if(file.eof())
        {
            cout<<"Error in opening the file"<<endl;
        }
        file.seekg(0);
        int pos;
        while(file.read((char*)&b,sizeof(b)))
        {

            if(ba[k]==b.get_ISBN())
            {
                cout<<left<<setw(7)<<j<<setw(30)<<b.get_title()<<setw(15)<< b.get_unitcost()<<setw(17)<<na[k]<<setw(17)<<na[k]*b.get_unitcost()<<endl;
                total += na[k]*(b.get_unitcost());
                flag+=1;
                //b.withdraw(na[k],b.get_ISBN());
                int v=b.get_no()-na[k];
                b.set_no(v);
                file.seekp(-sizeof(b),ios::cur);
                file.write((char*)&b, sizeof(b));
                j++;
            }
            //file.read((char*)&b,sizeof(b));
        }
    }
    if(flag!=0)
    {
        cout<<"\t\tTotal : "<<total;
        cout<<endl<<endl;
        f.open("salerecord4.txt",ios::app);
        struct copysale cs;
        auto now = std::chrono::system_clock::now();

        // Convert the system time to a time_t struct
        std::time_t now_c = std::chrono::system_clock::to_time_t(now);

        // Convert the time_t struct to a std::tm struct
        std::tm* now_tm = std::localtime(&now_c);

        // Extract the date and time components as integers
        cs.g3 = now_tm->tm_year + 1900; // Years since 1900
        cs.g2 = now_tm->tm_mon + 1;    // Months since January (0-11)
        cs.g1 = now_tm->tm_mday;
        for(int z=0;z<50;z++)
            cs.a[z]=0;
        for(int e=0;e<i;e++)
            cs.a[e]=ba[e];
        cs.t=total;
        f.write((char*)&cs,sizeof(cs));
    }
}


void Admin::purchase_books()
{
    fstream f,ff;
    float fl;
    long long b1,ba[50];
    int n,na[50],i=0,j=1,pos;
    int k,flag=0,s1;
    char another;
    cout<<"Enter supplier ID\n";
    cin>>s1;
    do
    {
        cout<<"Enter ISBN\n";
        cin>>b1;
        cout<<"Enter no. of books\n";
        cin>>n;
        ba[i]=b1;
        na[i]=n;
        cout<<"Do you want to add another book?[y/n]"<<endl;
        cin.ignore();
        cin>>another;
        ++i;
    }
    while(another=='y'||another=='Y');
    cout<<"Enter the amount paid to supplier\n";
    cin>>fl;
    ff.open("supplier1.txt",ios::in|ios::out);
    if(ff.eof())
    {
            cout<<"Error in opening the file"<<endl;
    }
    ff.read((char*)&s,sizeof(s));
    while(!ff.eof())
    {
        pos=ff.tellg();
        if(s1==s.get_supid())
        {
            s.set_pay(fl);
            ff.seekp(pos);
            ff.write((char*)&s,sizeof(s));
            break;
        }
        ff.read((char*)&s,sizeof(s));
    }
    k=0;
    while(k<i){
        fstream file;
        file.open("bookrecord4.txt",ios::in|ios::out);
        if(file.eof())
        {
            cout<<"Error in opening the file"<<endl;
        }
        file.seekg(0);
        pos=file.tellg();
        file.read((char*)&b,sizeof(b));
        while(!file.eof())
        {
            if(ba[k]==b.get_ISBN())
            {
                flag = 1;
                int v=b.get_no()+na[k];
                b.set_no(v);
                file.seekp(pos);
                file.write((char*)&b, sizeof(Book));
            }
            pos=file.tellg();
            file.read((char*)&b,sizeof(b));
        }

        k+=1;
    }
    if(flag==1)
            cout<<"Stock Updated..."<<endl;
    if(flag!=0)
    {
        f.open("purchaserecord4.txt",ios::app);
        struct copypur cs1;
        auto now = std::chrono::system_clock::now();

        // Convert the system time to a time_t struct
        std::time_t now_c = std::chrono::system_clock::to_time_t(now);

        // Convert the time_t struct to a std::tm struct
        std::tm* now_tm = std::localtime(&now_c);

        // Extract the date and time components as integers
        cs1.g3 = now_tm->tm_year + 1900; // Years since 1900
        cs1.g2 = now_tm->tm_mon + 1;    // Months since January (0-11)
        cs1.g1 = now_tm->tm_mday;
        cs1.ii=s1;
        for(int z=0;z<50;z++)
            cs1.a[z]=0;
        for(int e=0;e<i;e++)
            cs1.a[e]=ba[e];
        cs1.t=fl;
        f.write((char*)&cs1,sizeof(cs1));
    }
}

void Admin::view_monthlySalesReport()
{
    struct copysale cs1;
    int m;
    cout<<"Enter month to view the sales [mm]\n";
    cin>>m;
    fstream file;
    file.open("salerecord4.txt",ios::in);
    if(file.eof())
    {
        cout<<"Error in opening the file"<<endl;
    }
    file.read((char*)&cs1,sizeof(cs1));
    cout<<"Sales Report\n";
    while(!file.eof())
    {

        if(cs1.g2==m)
        {
            cout<<"Date : "<<cs1.g1<<"/"<<cs1.g2<<"/"<<cs1.g3<<endl;
            cout<<"Books : \n";
            for(int t=0;cs1.a[t]!=0;t++)
                cout<<cs1.a[t]<<"\n";
            cout<<"Total Sales : "<<cs1.t<<endl;

        }
        file.read((char*)&cs1,sizeof(cs1));
    }
}

void Admin::view_monthlypurchaseReport()
{
    struct copypur cs1;
    int m;
    cout<<"Enter month to view the purchase [mm]\n";
    cin>>m;
    fstream file;
    file.open("purchaserecord4.txt",ios::in);
    if(file.eof())
    {
        cout<<"Error in opening the file"<<endl;
    }
    file.read((char*)&cs1,sizeof(cs1));
    cout<<"Purchase Report\n";
    while(!file.eof())
    {
        if(cs1.g2==m)
        {
            cout<<"Date : "<<cs1.g1<<"/"<<cs1.g2<<"/"<<cs1.g3<<endl;
            cout<<"Supplier : "<<cs1.ii<<endl;
            cout<<"Books\n";
            for(int t=0;cs1.a[t]!=0;t++)
                cout<<cs1.a[t]<<endl;
            cout<<"Total Purchase : "<<cs1.t<<endl;

        }
        file.read((char*)&cs1,sizeof(cs1));
    }
}

void Admin::menu1()
{
    char pass[6];
    int con;
    cout<<"Enter password\n";
    for(int i=0;i<5;i++)
    {
        pass[i]=getch();
        putchar('*');
    }
    pass[5]='\0';
    char k[6]={'a','d','m','i','n','\0'};
    if(strcmp(pass,k)==0)
    {
        cout<<"\n\nLogin Successful\n";
        int choice;
        system("cls");
        do
        {

            cout<<"\n\nADMIN MENU\n[1]Go to books menu\n[2]Go to Customer menu\n[3]Go to employee menu\n[4]Go to supplier menu\n[5]Purchased Books\n[6]View monthly purchase report\n[7]View monthly sales report\nPress -1 to return to main menu\n";
            cin>>choice;
            switch(choice)
            {
                case 1:
                    //system("cls");
                    b.menu2();
                    break;
                case 2:
                   // system("cls");
                    c.menu3();
                    break;
                case 3:
                    //system("cls");
                    e.menu4();
                    break;
                case 4:
                    //system("cls");
                    s.menu5();
                    break;
                case 5:
                    //system("cls");
                    purchase_books();
                    break;
                case 6:
                  //  system("cls");
                    view_monthlypurchaseReport();
                    break;
                case 7:
                 //   system("cls");
                    view_monthlySalesReport();
                    break;
                case -1:
                //    system("cls");
                    return;
                default:
                    cout<<"Invalid Choice\n";
                    break;
            }
            //cout<<"Do you want to continue in admin menu?\n[1]Yes\n[2]No\n";
            //cin>>con;

        }
        while(choice!=-1);
    }
    else
    {
        cout<<"\nInvalid Password\n";
        return;
    }
}

void Book::menu2()
{
    int con;
    int choice;
    //system("cls");
    do
    {
        cout<<"\n\nBOOK MENU\n[1]Add new books\n[2]Remove books\n[3]Display Books\n[4]Search for a book\nPress -1 to return to previous menu\n";
        cin>>choice;
        switch(choice)
        {
            case 1:
      //          system("cls");
                add_newbooks();
                break;
            case 2:
        //        system("cls");
                remove_books();
                break;
            case 3:
          //      system("cls");
                display_books();
                break;
            case 4:
            //    system("cls");
                bsearch();
                break;
            case -1:
              //  system("cls");
                return;
            default:
                cout<<"Invalid Entry\n";
                break;
        }
        //cout<<"Do you want to continue in book menu?\n[1]Yes\n[2]No\n";
        //cin>>con;
    }
    while(choice!=-1);
}

void Customer::menu3()
{
    int con;
    int choice;
    //system("cls");
    do
    {

        cout<<"\n\nCUSTOMER MENU\n[1]Remove customers\n[2]Update Customer details\n[3]Display Customer details\n[4]Search for a customer\nPress -1 to return to previous menu\n";
        cin>>choice;
        switch(choice)
        {
            case 1:
                //system("cls");
                remove_customers();
                break;
            case 2:
                //system("cls");
                update_customers();
                break;
            case 3:
                //system("cls");
                display_customers();
                break;
            case 4:
                //system("cls");
                csearch();
                break;
            case -1:
                //system("cls");
                return;
            default:
                cout<<"Invalid Entry\n";
                break;
        }
        //cout<<"Do you want to continue in customer menu?\n[1]Yes\n[2]No\n";
        //cin>>con;
    }
    while(choice!=-1);
}

void Employee::menu4()
{
    int con;
    int choice;
    //system("cls");
    do
    {

        cout<<"\n\nEMPLOYEE MENU\n[1]Add Employee\n[2]Remove Employee\n[3]Update Employee details\n[4]Display Employee details\n[5]Search for an Employee\nPress -1 to return to previous menu\n";
        cin>>choice;
        switch(choice)
        {
            case 1:
                //system("cls");
                add_employee();
                break;
            case 2:
                //system("cls");
                remove_employee();
                break;
            case 3:
                //system("cls");
                update_employee();
                break;
            case 4:
                //system("cls");
                display_employee();
                break;
            case 5:
                //system("cls");
                esearch();
                break;
            case -1:
                //system("cls");
                return;
            default:
                cout<<"Invalid Entry\n";
                break;
        }
        //cout<<"Do you want to continue in employee menu?\n[1]Yes\n[2]No\n";
        //cin>>con;
    }
    while(choice!=-1);
}

void Supplier::menu5()
{
    int con;
    int choice;
    //system("cls");
    do
    {

        cout<<"\n\nSUPPLIER MENU\n[1]Add suppliers\n[2]Remove suppliers\n[3]Update Supplier details\n[4]Display Supplier details\n[5]Search for a Supplier\nPress -1 to return to previous menu\n";
        cin>>choice;
        switch(choice)
        {
            case 1:
                //system("cls");
                add_suppliers();
                break;
            case 2:
                //system("cls");
                remove_suppliers();
                break;
            case 3:
                //system("cls");
                update_suppliers();
                break;
            case 4:
                //system("cls");
                display_suppliers();
                break;
            case 5:
                //system("cls");
                ssearch();
                break;
            case -1:
                //system("clear");
                return;
            default:
                cout<<"Invalid Entry\n";
                break;
        }
        //cout<<"Do you want to continue in supplier menu?\n[1]Yes\n[2]No\n";
        //cin>>con;
    }
    while(choice!=-1);
}

void BillingStaff::menu6()
{
    char pass[6];
    int con;
    cout<<"Enter password\n";
    for(int i=0;i<5;i++)
    {
        pass[i]=getch();
        putchar('*');
    }
    pass[6]='\0';
    char k[6]={'b','i','l','l','s','\0'};
    if(strcmp(pass,k)==0)
    {
        cout<<"\n\nLogin Successful\n";
        int choice;
        system("cls");
        do
        {
            cout<<"\n\nBILLING MENU\n[1]Bill\n[2]Add customer data\nPress -1 to exit\n";
            cin>>choice;
            switch(choice)
            {
                case 1:
                    //system("cls");
                    sale_books();
                    break;
                case 2:
                    //system("cls");
                    c.add_customers();
                    break;
                case -1:
                    //system("cls");
                    return;
                default:
                 cout<<"Invalid Entry\n";
                break;
            }
            //cout<<"Do you want to continue in billing menu?\n[1]Yes\n[2]No\n";
            //cin>>con;
        }
        while(choice!=-1);
    }
    else
    {
        cout<<"\nInvalid Password\n";
        return;
    }
}


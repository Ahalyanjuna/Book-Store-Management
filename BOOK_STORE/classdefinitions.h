#include<string.h>
class Address
{
    private:
        char doorno[5];
        char street[15];
        char area[30];
        char city[25];
        char state[25];
        int pincode;
    public:
        void read();
        void display();
        void set_doorno1(char a[5])
        {
            strcpy(doorno,a);
        }
        void set_street1(char a[15])
        {
            strcpy(street,a);
        }
        void set_area1(char a[30])
        {
            strcpy(area,a);
        }
        void set_city1(char a[25])
        {
            strcpy(city,a);
        }
        void set_state1(char a[25])
        {
            strcpy(state,a);
        }
        void set_pincode1(int p)
        {
            pincode=p;
        }
};

class date
{
    private:
        int d;
        int m;
        int y;
    public:
        void read();
        void display();
        void set_date(int d1,int m1,int y1)
        {
            d=d1;
            m=m1;
            y=y1;
        }
        int get_year()
        {
            return y;
        }
};

class Book
{
    private:
        long long int ISBN;
        char bookTitle[50];
        char author[40];
        char PublicationName[50];
        int year;
        float unitCost;
        int no;
    public:
        Book(){no=0;}
        void menu2();
        int add_newbooks();
        //void refill(int,long int);
        void withdraw(int,long int);
        void remove_books();
        void display_books();
        int bsearch();
        void read();
        void display();
        float get_unitcost()
        {
            return unitCost;
        }
        long long int get_ISBN()
        {
            return ISBN;
        }
        char* get_title()
        {
            return bookTitle;
        }
        int get_no()
        {
            return no;
        }
        void set_no(int o)
        {
            no=o;
        }
};

class Customer
{
    private:
        char customerName[30];
        Address a;
        long long int phone;
        char email[50];
    public:
        void menu3();
        int isValidcusno(long int);
        int add_customers();
        void remove_customers();
        void update_customers();
        void display_customers();
        int csearch();
        void read(long int);
        void display();
        void set_customerName(char a[30])
        {
            for(int i=0;i<=sizeof(a);i++)
                customerName[i]=a[i];
        }
        void set_doorno(char a1[5])
        {
            a.set_doorno1(a1);
        }
        void set_street(char a1[15])
        {
            a.set_street1(a1);
        }
        void set_area(char a1[30])
        {
            a.set_area1(a1);
        }
        void set_city(char a1[25])
        {
            a.set_city1(a1);
        }
        void set_state(char a1[25])
        {
            a.set_state1(a1);
        }
        void set_pincode(int p)
        {
            a.set_pincode1(p);
        }
        void set_phone(long long int a)
        {
            phone=a;
        }
        void set_email(char e[50])
        {
            for(int i=0;i<=sizeof(e);i++)
                email[i]=e[i];
        }
        long long int get_ph()
        {
            return phone;
        }
};

class Supplier
{
    private:
        char supName[30];
        int supid;
        Address a;
        long long int phone;
        char email[50];
        float pay;
    public:
        void menu5();
        int isValidSupid(int);
        int add_suppliers();
        void remove_suppliers();
        void update_suppliers();
        void display_suppliers();
        int ssearch();
        void read();
        void display();
        void set_supName(char e[30])
        {
            for(int i=0;i<=sizeof(e);i++)
                supName[i]=e[i];
        }
        void set_doorno(char a1[5])
        {
            a.set_doorno1(a1);
        }
        void set_street(char a1[15])
        {
            a.set_street1(a1);
        }
        void set_area(char a1[30])
        {
            a.set_area1(a1);
        }
        void set_city(char a1[25])
        {
            a.set_city1(a1);
        }
        void set_state(char a1[25])
        {
            a.set_state1(a1);
        }
        void set_pincode(int p)
        {
            a.set_pincode1(p);
        }
        void set_phone(long long int a)
        {
            phone=a;
        }
        void set_email(char e[50])
        {
            for(int i=0;i<=sizeof(e);i++)
                email[i]=e[i];
        }
        void set_pay(float b)
        {
            pay=b;
        }
        int get_supid()
        {
            return supid;
        }
        float get_pay()
        {
            return pay;
        }
};

class Employee
{
    private:
        char empName[30];
        int empid;
        Address a;
        long long int phone;
        char email[50];
        float bsalary;
        date dob;
        date doj;
        int expyr;
    public:
        void menu4();
        int isValidEmpid(int);
        int add_employee();
        void remove_employee();
        void update_employee();
        void display_employee();
        int esearch();
        void read();
        void display();
        void set_empName(char e[30])
        {
            for(int i=0;i<=sizeof(e);i++)
                empName[i]=e[i];
        }
        void set_doorno(char a1[5])
        {
            a.set_doorno1(a1);
        }
        void set_street(char a1[15])
        {
            a.set_street1(a1);
        }
        void set_area(char a1[30])
        {
            a.set_area1(a1);
        }
        void set_city(char a1[25])
        {
            a.set_city1(a1);
        }
        void set_state(char a1[25])
        {
            a.set_state1(a1);
        }
        void set_pincode(int p)
        {
            a.set_pincode1(p);
        }
        int get_empid()
        {
            return empid;
        }
        void set_phone(long long int a)
        {
            phone=a;
        }
        void set_email(char e[50])
        {
            for(int i=0;i<=sizeof(e);i++)
                email[i]=e[i];
        }
        void set_bsalary(float b)
        {
            bsalary=b;
        }
        void set_dob(int d1,int m1,int y1)
        {
            dob.set_date(d1,m1,y1);
        }
        void set_doj(int d1,int m1,int y1)
        {
            doj.set_date(d1,m1,y1);
        }
};

class BillingStaff
{
    private:
        Book b;
        Customer c;
        float total;
        std::string curdate;
    public:
        BillingStaff()
        {
            curdate=get_currentdate();
            total=0;
        }
        void sale_books();
        void menu6();
        std::string get_currentdate();
};

class Admin
{
    private:
        Book b;
        Customer c;
        Employee e;
        Supplier s;
        std::string cd;
        BillingStaff bs;
    public:
        std::string gett_date()
        {
            cd=bs.get_currentdate();
            return cd;
        }
        void purchase_books();
        void view_monthlypurchaseReport();
        void view_monthlySalesReport();
        void menu1();
};



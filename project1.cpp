#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

class Node{

   public:
       string Emp_id,name,post,department;
       float salary;
       Node* Next_add;

};
class Employee{

  private:
      Node* Head;
  public:
    Employee();
    void introduction();
    void login();
    void control_panel();
    void insert();
    void search_id();
    void edit();
    void del();
    void display();
    void salary_slip();
    void search_dept();

};
     Employee::Employee(){
     Head = NULL;
     }
     void Employee::introduction(){
     system("cls");
     cout<<"\n\n\n\n\n\n\n";
     cout<<"\t\t\t==========================";
     cout<<"\n\t\t\t===========================";
     cout<<"\n\n\t\t\t Employee management system";
     cout<<"\n\n\n\t\t\t\tversion :  1.1";
     cout<<"\n\n\t\t\t============================";
     cout<<"\n\n\t\t\t=============================";
     getch();
     }
   void Employee::login()
   {
       p:
           system("cls");
           string user,pass;
           cout<<"\n\n";
           cout<<"\t\t\t===================";
           cout<<"\n\n\t\t\t\tLogin panel";
           cout<<"\n\n\t\t\t===================";
           cout<<"\n\n\n Enter user name: ";
           cin>>user;
           cout<<"\n\n Enter password: ";
           for(int i = 1;i<=6;i++){
            pass += getch();
            cout<<"*";

           }
           if(user =="mohamed@gmail.com" && pass =="123456"){
            cout<<"\n\n\t\t\tCongratulation Login success";
            cout<<"\n\n\n\t\t\t\tLoading";
            for(int i = 1;i<= 6;i++){
                Sleep(500);
                cout<<".";

            }
            control_panel();
           }
           else if(user !="1234567@gmail.com"&& pass== "123456"){
            cout<<"\n\n\n User name is wrong";
           }
           else if(user == "1234567@gmail.com"&& pass != "123456"){
            cout<<"\n\n\n password is wrong";
           }
           else{
            cout<<"\n\n\n password and user name are wrong";
           }
   }
   void Employee::control_panel()
   {
       p:
           system("cls");
           int x;
           cout<<"\n\n\t\t\t===================";
           cout<<"\n\n\t\t\t employee control panel";
           cout<<"\n\n\t\t\t======================";
           cout<<"\n\n\n 1. Insert record";
           cout<<"\n 2. search record";
           cout<<"\n 3. edit record";
           cout<<"\n 4. delete record";
           cout<<"\n 5. display record";
           cout<<"\n 6. salary slip";
           cout<<"\n 7. search department";
           cout<<"\n 8. exit";
           cout<<"\n your choice: ";
           cin>>x;
           switch(x)
           {
           case 1:
            insert();
            break;
            case 2:
            search_id();
            break;
            case 3:
            edit();
            break;
            case 4:
            del();
            break;
            case 5:
            display();
            break;
            case 6:
            salary_slip();
            break;
            case 7:
            search_dept();
            break;
            case 8:
            exit(0);
            break;
            default:
                cout<<"\n\nerror...try again";
           }
           getch();
           goto p;
   }
   void Employee::insert()
   {
       p:
           system("cls");
           Node* New_node = new Node;
           cout<<"\n\n\t\t\t===================";
           cout<<"\n\n\t\t\t Insert employee record";
           cout<<"\n\n\t\t\t======================";
           cout<<"\n\n Employee ID: ";
           cin>>New_node -> Emp_id;
           cout<<"\n\n Employee Name: ";
           cin>>New_node -> name;
           cout<<"\n\n Employee post: ";
           cin>>New_node -> post;
           cout<<"\n\n Employee department: ";
           cin>>New_node -> department;
           cout<<"\n\n Employee salary: ";
           cin>>New_node -> salary;
           New_node -> Next_add = NULL;
           if(Head == NULL){
            Head = New_node;
           }else
           {
               Node* ptr = Head;
               while(ptr != NULL){

                if(New_node -> Emp_id == ptr ->Emp_id){

                    cout<<"duplicate employee record...";
                    delete New_node;
                    getch();
                    goto p;
                }
                ptr = ptr ->Next_add;
               }
               ptr = Head;
               while(ptr -> Next_add != NULL){

                ptr = ptr ->Next_add;
               }
               ptr ->Next_add = New_node;
           }
           cout<<"\n\n Employee record inserted...";

   }
   void Employee::search_id()
   {
       system("cls");
       int found = 0;
       string Empid;
       cout<<"\n\n\t\t\t======================";
       cout<<"\n\n\t\t\t search employee record";
       cout<<"\n\n\t\t\t======================";
       if(Head == NULL)
       {
           cout<<"\n\n linked list in empty";

       }
       else
       {
           cout<<"\n\n Employee Id for search: ";
           cin>>Empid;
           Node* ptr = Head;
           while (ptr != NULL)
            {

            if(Empid ==ptr -> Emp_id)
            {
                system("cls");
                cout<<"\n\n\t\t\t======================";
                cout<<"\n\n\t\t\t search employee record";
                cout<<"\n\n Employee ID: "<< ptr -> Emp_id;
                cout<<"\n\n Employee Name: "<<ptr -> name;
                cout<<"\n\n Employee post: "<<ptr ->post;
                cout<<"\n\n Employee department: "<<ptr ->department;
                cout<<"\n\n Employee salary: "<<ptr -> salary;
                found++;
            }
            ptr = ptr ->Next_add;
           }
           if(found == 0 )
           {
            cout<<"\n\n Employee not found....";
           }
       }

   }
   void Employee::edit()
   {
       system("cls");
       int found = 0;
       string Empid;
       cout<<"\n\n\t\t\t====================";
       cout<<"\n\n\t\t\t modify Employee record";
       cout<<"\n\n\t\t\t====================";
       if(Head == NULL){
        cout<<"\n\n linked list is empty";
       }
       else
       {
           cout<<"\n\n Employee ID to modify: ";
       cin>>Empid;
       Node* ptr= Head;
       while(ptr != NULL)
          {
        if (Empid == ptr -> Emp_id)
                {
                cout<<"\n\n Employee ID: ";
                cin>> ptr -> Emp_id;
                cout<<"\n\n Employee Name: ";
                cin>>ptr -> name;
                cout<<"\n\n Employee post: ";
                cin>>ptr ->post;
                cout<<"\n\n Employee department: ";
                cin>>ptr ->department;
                cout<<"\n\n Employee salary: ";
                cin>>ptr -> salary;
                cout<<"\n\n Employee record modify";
                found++;
                }
          ptr = ptr->Next_add;
         }
         if(found == 0)
         {
           cout<<"\n\n employee not found";

         }
       }
   }
   void Employee::del()
   {

system("cls");

int found=0;

string Empid;

cout<<"\n\n\t\t\t================";

cout<<"\n\n\t\t\t DELETE EMPLOYEE RECORD";

cout<<"\n\n\t\t\t================";

if(Head == NULL)

{
 cout<<"\n\n *LINKED LIST IS EMPTY";
}

    else
     {

       cout<<"\n\n EMPLOYEE ID FOR DELETION: ";
       cin>>Empid;

       if(Empid== Head -> Emp_id)
        {
        Node* ptr = Head;
        Head = Head -> Next_add;
        delete ptr;
        cout<<"\n\n EMPLOYEE RECORD DELETED";
        }
          else{

    Node* pre = Head;
    Node* ptr = Head;
    while(ptr != NULL)
        {

        if(Empid == ptr -> Emp_id){

            pre -> Next_add = ptr -> Next_add;
            cout<<"\n\n employee record deleted";
            found++;
            break;
        }
     pre = ptr;
     ptr = ptr ->Next_add;
    }
    if(found == 0)
    {
        cout<<"\n\n employee not found";
    }
  }
}}
    void Employee:: display()
    {
        system("cls");
        cout<<"\n\n\t\t\t====================";
        cout<<"\n\n\t\t\t display employee record";
        cout<<"\n\n\t\t\t=====================";
        if(Head == NULL){
            cout<<"\n\n\t\t\t linked list is empty";
        }
        else{
            Node* ptr = Head;
            while(ptr != NULL){
                cout<<"\n\n\t\t\t search employee record";
                cout<<"\n\n Employee ID: "<< ptr -> Emp_id;
                cout<<"\n\n Employee Name: "<<ptr -> name;
                cout<<"\n\n Employee post: "<<ptr ->post;
                cout<<"\n\n Employee department: "<<ptr ->department;
                cout<<"\n\n Employee salary: "<<ptr -> salary;
                cout<<"\n\n=========================";
                ptr = ptr ->Next_add;
            }
        }
    }
    void Employee:: salary_slip(){

        system("cls");
        int found = 0;
        string Empid;
        cout<<"\n\n\t\t\t====================";
        cout<<"\n\n\t\t\t salary slip generator";
        cout<<"\n\n\t\t\t====================";
        if(Head == NULL){
            cout<<"\n\n linked list is empty";
        }
        else{
            cout<<"\n\n employee ID for slip: ";
            cin>>Empid;
            Node* ptr = Head;
            while(ptr != NULL){

                if(Empid == ptr ->Emp_id){
                    system("cls");
                cout<<"\n\t\t\t*****************";
                cout<<" Employee salary slip";
                cout<<"\n\t\t\t*****************";
                cout<<"\n\n Employee ID: "<< ptr -> Emp_id;
                cout<<"\n\n Employee Name: "<<ptr -> name;
                cout<<"\n\n Employee post: "<<ptr ->post;
                cout<<"\n\n Employee department: "<<ptr ->department;
                cout<<"\n\n Employee salary: "<<ptr -> salary;
                cout<<"\n\n=========================";
                cout<<"\n\n=========================";
                found++;
                }
                ptr = ptr ->Next_add;
            }
            if(found ==0){
                cout<<"\n\n employee not found";
            }
        }
    }
    void Employee::search_dept(){
         system("cls");
         int found = 0;
         string dept;
         cout<<"\n\n\t\t\t=====================";
         cout<<"\n\n\t\t\t search department record";
         cout<<"\n\n\t\t\t=====================";
         if(Head == NULL){
            cout<<"\n\n\t\t\t linked list is empty";
         }
         else{
            cout<<"\n\n department name for search: ";
            cin>>dept;
            Node* ptr = Head;
            while(ptr != NULL){
                if(dept == ptr->department){
                cout<<"\n\n Employee ID: "<< ptr -> Emp_id;
                cout<<"\n\n Employee Name: "<<ptr -> name;
                cout<<"\n\n Employee post: "<<ptr ->post;
                cout<<"\n\n Employee department: "<<ptr ->department;
                cout<<"\n\n Employee salary: "<<ptr -> salary;
                cout<<"\n\n=========================";
                cout<<"\n\n=========================";
                found++;
                }
                ptr = ptr ->Next_add;
            }
            if(found == 0){
                cout<<"\n\n department name not found";
            }
            else{
                cout<<"\n\n total employee found: "<<found;
            }
         }
    }
    main(){
    Employee obj;
    obj.introduction();
    obj.login();
    }

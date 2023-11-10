#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

void login();
void registration();
void forgot();

int main()
{
    int c;
    cout<<"\t\t\t_______________________________________________________________________________________________\n\n\n";
    cout<<"\t\t\t                              Login Page                                                        \n\n\n";
    cout<<"\t\t\t______________________________      Menu      ___________________________________________________\n\n";
    cout<<"                                                                                                        \n\n";
    cout<<"\t|Press  to LOGIN                      |"<<endl;
    cout<<"\t|Press 2 to REGISTER                  |"<<endl;
    cout<<"\t|Press 3 if you Forgot Your PASSWORD  |"<<endl;
    cout<<"\t|Press 4 to EXIT                      |"<<endl;
    cout<<"\n\t\t\t Please enter your choice :  ";
    cin>>c;
    cout<<endl;

    switch(c)
    {
             case 1:
                  login();
                  break;
             case 2:
                  registration();
                  break;
             case 3:
                  forgot();
                  break;
             case 4:
                  cout<<"\t\t\t  ThankYou!!  \n";
                  break;
             default:
                  system("cls");
                  cout<<"\t\t\t Please Enter The Given Option Above \n"<<endl;
                  main();
    }

}

    void login()
    {
         int count;
         string userId, password, id, pass;
         system("cls");
         cout<<"\t\t\t Please enter The username and password : "<<endl;
         cout<<"\t\t\t USERNAME ";
         cin>>userId;
         cout<<"\t\t PASSWORD ";
         cin>>password;

         ifstream input("records.txt");
         while(input>>id>>pass)
         {
                          if(id==userId && pass==password)
                          {
                                        count=1;
                                        system("cls");
                          }
         }
         input.close();
         if(count==1)
         {
            cout<<userId<<"\n Your LOGIN is Successfull \n Thanks For Logging In!! \n";
            main();
         }
         else{
              cout<<"\n LOGGING ERROR! \n Please Renter Your Details \n";
              main();
         }
}

    void registration()
    {
         string ruserid, rpassword,rid,rpass;
         system("cls");
         cout<<"\t\t\t Enter the UserName : ";
         cin>>ruserid;
         cout<<"\t\t\t Enter The Password ; ";
         cin>>rpassword;

         ofstream f1("records.txt", ios::app);
         f1<<ruserid<<' '<<rpassword<<endl;
         system("cls");
         cout<<"\n\t\t Registration is successfull! \n";
         main();

         }
         void forgot()
         {
          int option;\
          system("cls");
          cout<<"\t\t\t  If You Forgot Your password? \n";
          cout<<"Press 1 to search your id by username"<<endl;
          cout<<"Press 2 to go back to the main menu "<<endl;
          cout<<"\t\t\t Enter Your Choice :";
          cin>>option;
          switch(option)
          {
               case 1:
               {
                    int count=0;
                    string suserid,sid,spass;
                    cout<<"\n\t\t Enter The UserID You Remember :";
                    cin>>suserid;

                    ifstream f2("records.txt");
                    while(f2>>sid>>spass)
                    {
                         if(sid==suserid)
                         {
                            count=1;
                         }
                    }
                    f2.close();
                    if(count==1)
                    {
                      cout<<"\n\n Your Account Has Been Found! \n";
                      cout<<"\n\n Your password is: "<<spass;
                      main();
                    }
                    else{
                         cout<<"\t\n Sorry Your Account is Not found! \n";
                         main();
                    }
                    break;
               }
               case 2:
                    {
                          main();
                          }
                     default:
                           cout<<"\t\t\t Wrong Choice ! Please Try Again" <<endl;
                           forgot();

          }
}

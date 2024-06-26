#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;
int main()
{
	int a, i=0;
	string text, old, password1, password2,pass, name, password0, age, user, word, word1;
	string creds[2],cp[2];
	cout<<"        Security System  "<<endl;
	
	cout<< "_____________________________"<<endl<<endl;
	cout<<"|         1. Register         |"<<endl;
	cout<<"|         2. Login            |"<<endl;
	cout<<"|         3. Change Password  |"<<endl;
	cout<<"|_________4. End Program______|"<<endl<<endl;
	
	do{
		cout<<endl<<endl;
		cout<<"Enter your choice:  ";
		cin>>a;
		switch(a)
		{
			case 1:{
				cout<<"___________________________"<<endl;
				cout<<"|---------Register--------|"<<endl;
				cout<<"|_________________________|"<<endl<<endl;
				cout<<" Please Enter Username:- ";
				cin>>name;
				cout<<" Please Enter the Password:- ";
				cin>>password0;
				cout<<" Please Enter your Age:- ";
				cin>>age;
				
			
			//storing in some file
			//file handling operations
			ofstream of1;
			of1.open("ssimar.txt");
			if(of1.is_open()){
				of1<<name<<"\n";
				of1<<password0;
				cout<<" Registration successful "<<endl;
				
			}
				break;
			}
			
			case 2:{
				i=0;
				cout<<"________________________"<<endl;
				cout<<"|---------Login--------|"<<endl;
				cout<<"|______________________|"<<endl<<endl;
				
				//file handling
				//reading from file
				ifstream of2;
				of2.open("ssimar.txt");
				cout<<"Please Enter the Username:- ";
				cin>>user;
				cout<<" Please Enter the Password:- ";
				cin>> pass;
				
				if(of2.is_open())
				{
					while(!of2.eof())
					{
						while(getline(of2, text))//read the file line by line
						{
							istringstream iss(text);// stream the string and store it using extraction operator
						    iss>>word;
							creds[i]=word;
							i++;	
						}//checking credentials
						if(user==creds[0] && pass==creds[1])
						{cout<<" ----Login Successfull----"<<endl<<endl;
						cout<<" Details: "<<endl;
						cout<<"Username: "+name<<endl;
						cout<<"Password: "+pass<<endl;
						cout<<"Age: "+age<<endl;
						}
						
						else{
							cout<<endl<<endl;
							cout<<" Incorrect Credentials "<<endl;
							cout<< " 1. Press 2 to login  "<<endl;
							cout<< " 2. Press 3 to change password "<< endl;
							break;
						}
					}
				}
				
				break;
			}
			
			case 3:
				{
				i=0;
				cout<<"---------change password--------"<<endl;
				ifstream of0;
				of0.open("ssimar.txt");
				cout<<"Enter the Old password:- ";
				cin>>old;
				if(of0.is_open())
			{			
					while(of0.eof())
					{
						while(getline(of0, text)){
							istringstream iss(text);
							iss>>word1;
							cp[i]=word1;
							i++;
							
						}
						if(old==cp[1])
						{
							of0.close();
							ofstream of1;
							of1.open("ssimar.txt");
							if(of1.is_open())
							{
								cout<<" Enter your new password:- ";
								cin>>password1;
								cout<<"Enter your password again:- ";
								cin>>password2;
								if(password1==password2)
								{
									of1<<cp[0]<<"\n";
									of1<<password1;
									cout<<"Password changed successfully"<<endl;
									
								}
								else{
									of1<<cp[0]<<"\n";
									of1<<old;
									cout<<"password do not match"<<endl;
								}
							}
						}
						else{
							cout<<" please enter a valid password "<<endl;
							break;
						}
					}
					}	
			 
					break;
				}
			case 4:{
				cout<<"--------------Thankyou!-------------\n";
				cout<<"Now press 5 to exit ";
								
				break;
			}
			case 5:
				{
					exit(a);
				}
			default:
				
				cout<<"Enter a valid choice ";
		}
	}
	while(a!=5);
	return 0;
}

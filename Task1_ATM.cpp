#include<iostream>
using namespace std;

class ATM
{
	int pin;
	double balance;
	string name;

	public:
	       ATM(int userPin, double initialBalance)
	       {
		       pin=userPin;
		       balance=initialBalance;
	       }

	       bool authenticate(int enterPin)
	       {
		       if(enterPin==pin)
			       return 1;
		       else
			       return 0;
	       }

	       void PrintMenu()
	       {
		       cout<<"********  ATM MENU  ********"<<endl;
		       cout<<" 1: Show Balance "<<endl;
		       cout<<" 2: Withdraw Money "<<endl;
		       cout<<" 3: Deposite Money "<<endl;
		       cout<<" 4: Change PIN "<<endl;
		       cout<<" 5: Check current PIN NO "<<endl;
		       cout<<" 6: Exit "<<endl;
		       cout<<"****************************"<<endl;
	       }
		      		      		      
	       void showBalance()
	       {
                      cout<<"Your current balance is: $ "<<balance<<endl;
	       }

	       void withdraw(double amount)
	       {
		       if(amount > balance ||amount<=0)
		       {
			       if(amount<=0)
				       cout<<"Amount must be greater than zero. "<<endl;
			       else
			       	       cout<<"Transaction declined. Insufficient balance!"<<endl;
		       }
		       else
		       {
			       balance -= amount;
			       cout<<"Withdrawal successful!..Your new balance is: $ "<<balance<<endl;

		       }
	       }

	       void deposit(double amount)
	       {
		       if(amount <= 0)
		       {
			       cout<<"Invalid amount. Please enter a valid deposit amount."<<endl;
		       }
		       else
		       {
			       balance += amount;
			       cout<<"Deposit successful!..Your new balance is: $ "<<balance<<endl;
		       }
	       } 

	       void ChangePIN(int oldpin, int newpin)
	       {
		       if(pin==oldpin)
		       {
		       	     pin=newpin;
			     cout<<"PIN changed successfully!... "<<endl;
		       }
		       else
		       {
			       cout<<"Incorrect old pin "<<endl;
		       }
	       }

	       void CheckPIN()
	       {
		       cout<<"Your current PIN: "<<pin<<endl;
	       }

};

int main()
{

	int userPin=1111;
	double initialBalance=1000;

	int enterPin,cnt;
	int choice;
	double amount;
	int op;

	ATM atm(userPin, initialBalance);

        do{
		cout<<"**** WELCOME TO THE ATM! ****"<<endl;
		PIN:
		cout<<"Please enter your 4_digit ATM PIN: ";
		cin>>enterPin;

		if(atm.authenticate(enterPin)==0)
		{
			cnt++;
			cout<<"____Incorrect PIN... Enter correct PIN___ "<<endl;
			if(cnt==3)
			{
				cout<<"Your card is temporarily blocked. Try again after 24 hours or contact your bank."<<endl;
				return 0;
			}
			goto PIN;
		}
		else
		{
			cnt=0;
			cout<<"___ Authentication successful! ___"<<endl;
		}
  
	        MENU:
		atm.PrintMenu();

	        cout<<"Enter your choice: ";
	        cin>>choice;

		if(choice > 6 || choice < 1)
		{
			cnt++;
			if(cnt==3)
			{
				cout<<"You have chosen the wrong options. Better luck next time!"<<endl;
				return 0;
			}
		     cout<<"Invalid input choice. Please enter correct option(1 to 6):"<<endl;
		     goto MENU;
		}
		else
		{
			cnt=0;
		}

		switch(choice)
		{
			
			case 1:
			       atm.showBalance();
			       break;

			case 2:
			       cout<<"Enter the amount to withdraw : "<<endl;
			       cin>>amount;
		               atm.withdraw(amount);
			       break;

			case 3:
			       cout<<"Enter the amount to deposite : "<<endl;
			       cin>>amount;
			       atm.deposit(amount);
			       break;

			case 4:
		 	       int oldpin,newpin;
		 	       cout<<"Please Enter old PIN: ";
			       cin>>oldpin;
			       cout<<"Please Enter New PIN: ";
			       cin>>newpin;
			       atm.ChangePIN(oldpin, newpin);	       
			       break;

			case 5:
			       atm.CheckPIN();
			       break;

			case 6:
			       cout<<"Thank you for using our ATM. Have a good day. "<<endl;
			       exit(1);
			       break;

		       default:
			       cout<<"Please select a correct option."<<endl;
		}
		
		cout<<"You want to try another[Yes or No]: "<<endl;
		cout<<" 1: yes : "<<endl;
		cout<<" 0: No  : "<<endl;
		TRY:
		cin>>op;

		if(op==1 ||op==0)
		{
			cnt=0;
			if(op)
			        cout<<"Continue with another transaction...  "<<endl;
			else
				cout<<"...Have a good day..."<<endl;
		}
		else if(op!=1 && op!=0)
		{
			cnt++;
			if(cnt==3)
			{
				cout<<"Thank you for using our ATM!..Have a good day!.."<<endl;
				return 0;
			}
			cout<<"Select option either 1 or 0: "<<endl;
			goto TRY;
		}
	}
	while(op);
	return 0;	
}
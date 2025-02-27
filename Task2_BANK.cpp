#include<iostream> 
#include<vector> 
using namespace std; 
class BankAccount
{ 
    private: 
        string name; 
        int accountNum; 
        double balance; 
    public: 
        BankAccount(string n, int ac, double bal)
        { 
            name= n; 
            accountNum = ac; 
            balance = bal; 
        } 
        string getName()
        { 
            return name; 
        } 
        int getAccountNum()
	{ 
            return accountNum; 
        } 
        double getBalance()
	{ 
            return balance; 
        } 
        void deposit(double amount)
	{ 
            balance = balance + amount; 
        } 
	int withdraw(double amount)
	{ 
            if(balance >= amount)
	    { 
                balance = balance - amount;  
		return 1;
            }
	    else
	    { 
                cout<<"**** Insufficient Balance ****"<<endl; 
		return 0;
            } 
        }
}; 

class BankManagement
{ 
    private: 
        vector<BankAccount> accounts; 
    public:
        void transferMoney(int fromAccount, int toAccount, double amount);	
        void AddAccount(string name, int accountNum, double balance )
	{ 
            accounts.push_back(BankAccount(name,accountNum,balance)); 
        } 
        void showAllAccounts()
	{ 
            cout<<"---- All Account Holders ----"<<endl; 
            for(int i = 0; i<accounts.size();i++)
	    { 
                cout<<"Acct Holder Name : "<<accounts[i].getName()<<"\nAccount Number   : "<<accounts[i].getAccountNum()<<"\nCurrent Balance  : ₹"<<accounts[i].getBalance()<<endl; 
                cout<<endl;
	    } 
        } 
        void searchAccount(int account)
        { 
            cout<<"---- Account Holder ----"<<endl; 
            for(int i = 0; i<accounts.size();i++)
	    { 
                if(accounts[i].getAccountNum()==account)
 		{ 
                  cout<<"Acct Holder Name : "<<accounts[i].getName()<<"\nAccount Number   : "<<accounts[i].getAccountNum()<<"\nCurrent Balance  : ₹"<<accounts[i].getBalance()<<endl;
		  cout<<endl; 
                } 
            } 
        } 
	BankAccount* findAccount(int accountNum)
   	{ 
            for(int i = 0; i<accounts.size();i++)
	    { 
                if(accounts[i].getAccountNum()==accountNum)
		{ 
                    return &accounts[i]; 
                } 
            } 
            return nullptr;
	} 
}; 

void BankManagement::transferMoney(int fromAccount, int toAccount, double amount)
{
	BankAccount* sender = findAccount(fromAccount);
        BankAccount* receiver = findAccount(toAccount);

        if(sender == nullptr)
        {
             cout<<"**** Sender Account Not Found ****"<<endl;
             return;
        }
        if(receiver == nullptr)
        {
             cout<<"**** Receiver Account Not Found ****"<<endl;
             return;
        }
        if(sender->getBalance() >= amount)
        {
             sender->withdraw(amount);
             receiver->deposit(amount);
             cout<<"₹"<<amount<<" Transferred Successfully...."<<endl;
        }
        else
        {
             cout<<"**** Insufficient Balance ****"<<endl;
        }
}

int main()
{ 
    BankManagement bank; 
    int choice;
    while(true)
    { 
        cout<<"====== Online Banking System ======"<<endl; 
        cout<<"---------- Main Menu -----------"<<endl; 
        cout<<"1. Create New Account"<<endl; 
        cout<<"2. Show All Account"<< endl; 
        cout<<"3. Search Account"<<endl; 
        cout<<"4. Deposit Money"<<endl; 
        cout<<"5. Withdraw Money"<<endl; 
	cout<<"6. Transfer Money"<<endl;
        cout<<"7. Exit"<<endl;	
        cout<<"--------------------------------"<<endl; 
        cout<<"Enter Your Choice : "; 
        cin>>choice; 
        switch(choice)
	{ 
            case 1:
	    { 
                string name; 
                int accountNum; 
                double balance; 
                cout<<"Enter Acct Holder Name : "; 
                cin>>name; 
                cout<<"Enter Account Number   : "; 
                cin>>accountNum; 
                cout<<"Enter Initial Balance  : "; 
                cin>>balance; 
                bank.AddAccount(name,accountNum,balance); 
                cout<<"Account Created Successfully..."<<endl; 
                break; 
            } 

            case 2:
	    { 
                bank.showAllAccounts(); 
                break; 
            } 

            case 3:
	    { 
                int accountNum; 
                cout<<"Enter Account Number : "; 
                cin>>accountNum; 
                bank.searchAccount(accountNum); 
                break; 
            } 

            case 4:
	    { 
                int accountNum; 
                double amount; 
                cout<<"Enter Account Number to Deposit Money : "; 
                cin>>accountNum; 
                BankAccount* account =  bank.findAccount(accountNum);

		if(account != NULL)
		{ 
                    cout<<"Enter Amount to Deposit : "; 
                    cin>>amount; 
		    if(amount<=0)
		    {
			    cout<<"**** Invalid Amount ****"<<endl;
			    break;
		    }
                    account->deposit(amount); 
                    cout<<"₹"<<amount<<" Deposit Successfully...."<<endl;  
                }
  		else
	  	{ 
                    cout<<"**** Account Not Found ****"<<endl; 
                } 
                break; 
            } 

            case 5:
	    { 
                int accountNum; 
                double amount; 
                cout<<"Enter Account Number to Withdraw Money : "; 
                cin>>accountNum; 
                BankAccount* account =  bank.findAccount(accountNum); 
                if(account != NULL)
		{ 
                    cout<<"Enter Amount to Withdraw : "; 
                    cin>>amount; 
		    if(amount<=0)
                    {
                            cout<<"**** Invalid Amount ****"<<endl;
                            break;
                    }
		    if(account->withdraw(amount))
		    { 
		            cout<<"₹"<<amount<<" Withdraw Successfully...."<<endl;
		    }
                }
		else
		{ 
                    cout<<"**** Account Not Found ****"<<endl; 
                } 
                break; 
            } 

	    case 6:
	    {
    		int fromAccount, toAccount;
    		double amount;
    		cout<<"Enter Sender Account Number   : ";
    		cin>>fromAccount;
    		cout<<"Enter Receiver Account Number : ";
    		cin>>toAccount;
    		cout<<"Enter Amount to Transfer      : ";
    		cin>>amount;
		if(amount<=0)
		{
			cout<<"**** Invalid Amount ****"<<endl;
			break;
		}
    		bank.transferMoney(fromAccount, toAccount, amount);
    		break;
	    }

            case 7: 
	    { 
		cout<<"Thank You!... Have a Good Day!..."<<endl;    
                exit(1);      
            } 
        } 
    }
}
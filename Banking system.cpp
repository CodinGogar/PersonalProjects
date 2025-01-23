#include <iostream>
#include <cmath>
using namespace std;
#include <fstream> 
#include <string>
#include <vector>
vector<char> customer_details = {} ;

void file_writer(string a, b, int balance = 0){
	ofstream file;
	 file.open("reciept.txt");
	  file<<"---------------------------CHIMDI BANKS PLC---------------------------------------------------"<<endl;
	  file<<a<<"TRANSACTOR: "<<endl;
    file<<b<<"PHONE NUMBER: "<<endl;
    file<<"BALANCE:"<<balance<<endl;
	    
	
}


int create(){
	start:
	char name;
	cout<<"NAME:"<<endl;
	cin>>name;
	
	char age;
	cout<<"AGE:"<<endl;
	cin>>age;
	
	string phone, BVN;
	cout<<"PHONE NUMBER:"<<endl;
	cin>>phone;
	
   begin:
	cout<<"BANK VERIFICATION NUMBER:"<<endl;
	cin>>BVN;
	
	
	int count = 0;
	for (char i  : bvn){
		++count;
      
	}
	
	if (count != 11){
		cout<<"invalid BVN"<<endl;
		goto begin;	
	}
	customer_details.push_back(name);
	customer_details.push_back(age);
	customer_details.push_back(phone);
	customer_details.push_back(BVN);
	
	loop:
	char user_response;
	cout << "HERE ARE YOUR DETAILS, ARE THEY CORRECT?  (Y/N)"<<endl;
	cin>>user_response;
	for (char i : customer_details){
	
		cout<<i<<endl;
		}
	if (user_response == 'y'){
		cout << "OKAY"<<endl;
      file_writer(name,phone );
		
	}
	else if (user_response == 'n'){
		customer_details.clear();
		goto start;
		
	}
	else if (user_response != 'y' || user_response != 'n' ){
		cout << "PLEASE USE EITHER Y/N"
			  goto loop;
	}
	else {
		goto loop;
	}
}
int deposit(){
	int amount;
	 cout << "ENTER AMOUNT TO BE DEPOSITED"<<endl;
	  cin >> amount;
	    
     
	    
		     
   
}
int withdraw(){
	
}
int close_acc(){
	
}
int bal_inq(){
	
}





int main(){
	// greetings  and  operations
	string name;
	
	cout<<"what's  your name?";
	cin>>name;
	cout<<"Good day."<<name<<endl;
	cout<<"What would you love to do?"<<endl;
	
	int user_choice;
	cout<<"1. CREATE ACCOUNT, 2. DEPOSIT, 3. WITHDRAW, 4. CLOSE ACC, 5. BALANCE INQ";
	cin>>user_choice;
	
	
	switch (user_choice){
		case 1:
			  	create();
		case 2:
			  	deposit();
		case 3:
			  	withdraw();
		case 4:
			  close_acc();
		case 5:
			  bal_inq();
			
	}
}



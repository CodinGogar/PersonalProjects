#include<iostream>
#include<string> //for strings
#include<vector> //for  vectors
#include<cctype> //for .lower()
#include<algorithm> //for  transform()
using namespace std;
/*Making derived classes  like student and librarian would help but storage would  be an issue*/
/*user requirements
3. Library Management System
Build a system to manage a small library. Key functionalities might include:

*Adding, deleting, and *searching for books
*Checking books in and out
Managing user accounts
*request to add book
Generating overdue notices*/

vector<string> add_notifications{};
class book{
	public:

	string title, author, plot;
	int date_published;
	float price;
	
    void display() {
        cout << "Title: " << title << "\n"
                  << "Author: " << author << "\n"
                  << "Year published: " << date_published << "\n"
                  << "Price: $" << price << "\n"
                  << "Plot:"<<plot<<endl;
    }
};
vector<book> book_storage{};
	
class user{
	private :
		string user_type 
		int user_pin;
	 	public:
	 string name, user_name;
			
	//constructor			 
	public:
    User(string r,string person_name,string s, int pin) {  
        user_type = r;  
        name = person_name;
        user_name = s;
        user_pin = pin;
 }
	   
 public:
 	void display(){ // fn to display the menu for users
 		cout<<"\nPRESS 1 TO DISPLAY THE MENU"
 			<<"\nPRESS 2 TO SEARCH FOR BOOKS"
			 <<"\nPRESS 3 TO ADD A BOOK"
			 <<"\nPRESS 4 TO DELETE A BOOK"
			 <<"\nPRESS 5 TO MANAGE USERS"
			 <<"\nPRESS 6 TO GENERATE OVERDUE NOTICE FOR A USER";	
	 }
	   //all user can search for books
  public:
  	virtual void search_books(string Title, string Author){ // virtual allows a method to be overidden (i can change its function) 
  		
  		transform(Title.begin(),Title.end(), Title.begin(),::tolower);
  		transform(Author.begin(),Author.end(), Author.begin(),::tolower);	
		  							 
  		for ( auto it = book_storage.begin(); it != book_storage.end();++it ){
  			 	if ((*it).title == Title || (*it).author == Author){
			  	 	cout<<"BOOK FOUND"<<endl;
					it->display();
								  	  
					while (true){
					 				 	  
					cout << "\nWOULD YOU LIKE TO CHECK OUT THIS BOOK AND READ IT? [y/n]"<<endl; 
					char user_response;
  	  				user_response.tolower();
  					switch (user_response){
  						case 'y':
						  	cout<<""(*it).title<<"BY "<<(*it).author<<"HAS BEEN SUCCESSFULLY CHECKED OUT"<<endl;
							break;	 				  			   		 
						case 'n':
							  cout<<"OKAY";
							  	break;	   	
  						default:
						  cout<<"NOT A VALID INPUT";
						  true;	  	  	
					           }
				          }
				 	
					}

		 		
  	}
  	 				else 
					cout<<"SORRY,WE CURRENTLY DONT HAVE THAT BOOK. PLEASE CHECK BACK LATER.";	
							 		
	  }
	    
   public:
   	void request_addbook(){
   		 if (user_type == "Author"){
   		 	 string user_req;
   			 cout<<"PLEASE ENTER THE BOOK TITLE AND AUTHOR IN THE FOLLOWING FORMAT: BOOK_TITLE-BY-AUTHOR "<<endl;
	 					getline(cin,user_req);
						add_notifications.push_back(user_req); 		  
				 cout<<"THE LIBRARIAN  HAS BEEN NOTIFIED, THE BOOK WOULD BE ADDED TO OUR DATABASE"<<endl;  
   		  
   		  
		}
		 else
		 	  cout<<"THIS FEATURE IS RESERVED FOR AUTHORS ONLY";
	}
	
	public:
		void add_books(){
			  	char user_resp;
				  user_resp.tolower();
			  	if (user_type == "Librarian"){
					cout<<"YOU HAVE "<<add_notifications.size()<<"NOTIFICATIONS. TO  VIEW THEM PRESS V"
					if (user_resp == 'v'){
						for (int i = 0; i<= add_notifications.size() - 1; i++)
							 cout<<i; 	
					}  	
		}
		     else
		 	     cout<<"THIS FEATURE IS RESERVED FOR THE LIBRARIAN ONLY";
	}
	
	       
};

// this derived class is for  the guest
class guest : private user {  /*Private inheritance: Everything in Parent is now private and outside code
cant access these features */  
public:
    using user::search_books;  // The only method that can be used
    void search_books(string Title, string Author) override{
    	
  		transform(Title.begin(),Title.end(), Title.begin(),::tolower);
  		transform(Author.begin(),Author.end(), Author.begin(),::tolower);	
		  							 
  		for ( auto it = book_storage.begin(); it != book_storage.end();++it ){
  			 	if ((*it).title == Title || (*it).author == Author){
			  	 	cout<<"BOOK FOUND"<<endl;
					it->display();
  	  
	 }
	  cout<<"TO CHECKOUT AND READ THIS BOOK, REGISTER AND BECOME A USER";
};

vector<user> user_vec{};
user* int login(){

	string resp;
	cout<<"ENTER YOUR PIN PLEASE"<<endl;
	getline(cin,resp);
	
	//type cast resp(the users response) into an integer
	int user_resp;
	while (true){
		try {
        user_resp = stoi(resp);// stoi is  fn to conv string to  int
  		  break;
    } catch (exception& e) {// use a reference of the exception gotten
        cout << "INVALID PIN FORMAT!" << endl;
        getline(cin, resp);  // Get new input from the user
    }
			
	}
	for (auto it = user_vec.begin(); it  != user_vec.end(); it++){
		if (it->user_pin == user_resp){
				return &(*it); // give us the address  of that user
		}
	 		}
	 cout<<"PIN NOT FOUND"
	return nullptr;
}
void instantiator(){
	//instantiate the book class and add some books to book_storage
	book myBook;

    myBook.title = "c++ programming";
    myBook.author = "bjarne stroustrup";
    myBook.date_published = 1985;
    myBook.price = 49.99;
    myBook.plot = "Learn the basics of C++ with Bjarne Stroustrup";
    book_storage.push_back(myBook);
    
  book sec_book;  
    sec_book.title = "basic economics";
    sec_book.author = "kolawole bankole";
    sec_book.date_published = 2005;
    sec_book.price = 12.99;
    sec_book.plot = "Explore and learn basic concepts in economics such as demand and supply, marketing and so much more ";
   book_storage.push_back(sec_book);
   
   //instantiate and add some objects to the user_vec
  user first_user(string("Librarian"),string("Chinedu"),string("chinedu@1"),111234);
  user_vec.push_back(first_user);
  
  user sec_user(string("Student"),string("Gerald"),string("gerald@2"),222345);
  user_vec.push_back(sec_user);
  
  user third_user(string("Author"),string("Sofia"),string("sofia@1"),333456);
  user_vec.push_back(third_user);
   
}

int main(){
	
   int user_choice;
	
	cout<<"ARE YOU AN EXSISTING USER, IF YES, PRESS 1 TO LOGIN\n"
	<<"TO CONTINUE AS A GUEST, PRESS 3\n"; //guests can only search, they cant check out. If they try to, they should register
	cin>> user_choice;
	
	if (user_choice == 1){
		value = login(); 
		if (value == nullptr){
				cout<<"YOU ARE NOT A USER";
				cout<<"\nDO YOU WANT TO CONTINUE AS A GUEST [y\n]"; 
				while (true){
					char user_choice;
					 switch (user_choice){
					 	case 'y':
						 guest new_guest;	
						 	
						 new_guest.search_books();	 	
					 }	 	
				}					 		
	 		   				
		}
	 	else 
		 	  // i need to derefrence this iterator &(*it) and use it
	}
	
}
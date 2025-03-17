#include  <iostream>//for inputs and outputs
#include <string>// for strings and string::npos and find(). used chatgpt for this
#include <algorithm>//for  begin and end
#include <cctype>//for tolower fn

#include <cstdlib>//for the exit() and rand(). used chatgpt for the exit
using namespace std;

//global variables
string word_arr[] = {"james", "tracy", "chimdi", "david", "john",  "solomon"};
int user_score;
int get_correct_letter_attempt = 0; 

//fn to re arrange the word
string scramble (const string& text){
	string chars = text;
	for (int i = 0; i<chars.length(); i++){
		int  j = rand() % chars.length(); // to randomize the  indexes
			  char temp = chars[i];
			  chars[i] = chars[j];
			  chars[j] = temp; 
}
	return chars;
}

// fn to display the rules
void rules(){
   
	cout << "\nUSER MANUAL"<<endl;
	cout <<"TRY AND GUESS THE  WORD BY ENTERING CHARACTERS FROM THE KEYBOARD"<<endl;
	cout <<"PRESS N TO SKIP TO THE NEXT QUESTION. ONCE PRESSED, ALL ATTEMPT WOULD BE FOREFIETED AND THE CORRECT WORD WOULD BE SHOWN"<<endl;
	cout <<"PRESS H TO ACTIVATE AND  GET A HINT"<<endl;
	cout <<"YOU HAVE 5 ATTEMPTS TO REVEAL A LETTER FROM THE SCRAMBLED WORD. PRESS G TO ACTIVATE. ONCE EXHAUSTED YOU CANT USE IT AGAIN"<<endl;
	
	
}
 // fn for the get correct letter
void get_correct_letter(string text){
	int i = 0;
	int  j = rand() % text.length(); 
	for (i = 0; i<text.length(); ++i){
		if (i == j){
			cout << ""<< text[i]<<"\t";
				  	  //++i;
		}
		 else{
 		     cout << "-\t"; 	
 			  		    //++i;  
		 }
		
	}
}


//fn for hint
void hint (string text){
	char user_char;
	cout << "ENTER A CHARACTER TO RECIEVE A CLUE ABOUT IT"<<endl;
	cin>>user_char;
   
   //string::npos returns a constant that means not found
   //find() searches the string for a character. returns the index of the first occurrence
   
    if (text.find(user_char) != string::npos) { // if the find fn returns a value that isnt equal to string::npos
        cout << "Character " << user_char << " is in the word." << endl;
    } else { //the value is equal
        cout << "Character " << user_char << " is not in the word." << endl;
    }

    
}
	
// fn to change user inputs to lower case 
void lower_input (string a){
	transform(a.begin(), a.end(), a.begin(), ::tolower);
	
	
}
int main(){
	 cout << "---------------------------------------GUESS THE WORD --------------------------------------------"<<endl;
  int proceed;
  cout << "PRESS 1 TO PROCEED OR 2 TO EXIT THE PROGRAM" << endl;
  cin >> proceed;
         
  
   if (proceed == 1) {
   	rules();
    // display the scrambled word and accept user input	
   
	  for (int k = 0; k<=5;){
 		string scrambled = scramble(word_arr[k]);
  	   string user_input;
  		   
			loop:
			
	      cout << "\nWHAT IS THIS WORD?" << "\t\t\t\t\tGET CORRECT LETTER POINTS: "<< get_correct_letter_attempt <<endl;
	      cout << scrambled << endl;
         cin >> user_input;
	      lower_input(user_input);
     
	  	   if ( word_arr[k] == user_input){
            cout << "Correct! You spelt the word correctly"<< endl;
			   ++user_score; 
				++get_correct_letter_attempt;   
				++k;   
		   }
	      else if (user_input == "n" ){
    	      cout << "THE WORD >>> "<<word_arr[k]<<endl;
	          ++k; 
				 	
			}
	      
	      else if (user_input == "h"){
			      	hint(word_arr[k]);
			}
	      else if (user_input == "g"){  	
						if (get_correct_letter_attempt == 0){
						   cout << "SORRY, YOU DONT HAVE ANY ATTEMPT POINTS";	 		  	
						}	
						else{
					      get_correct_letter(word_arr[k]);
				         --get_correct_letter_attempt; 	  	
						}	  
			}
     
		   else {
		      cout << "try again"<<  endl;
			 	goto loop;
				 }
			 }

	
	
	 

}
     else  if (proceed == 2){
     	   exit(0);
	  }
	    else{
		     	cout<<"WRONG CHARACTER ENTERD";
		 }
}

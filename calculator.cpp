#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

std::vector<char> word_vector; // vector to store words
int add(int a, int b){
	return a+b;
}
int subtract(int a, int b){
	return a-b;
	
}
int multiply(int a, int b){
	return a*b;
}
int division(int a, int b){
	return a/b;
}
int power(int a, int  b){
	return std::pow(a,b);
}
int sqrt(int a){
	return std::sqrt(a);
}
void splitSentence(const std::string& sentence) {
	 for (char i : sentence){
	  	word_vector.push_back(i);
	 }
    
    
}
int main(){
	std::cout<<"What do  you want to calculate";
	
	std::string question;
	std::cin>>question;
	splitSentence(question);// split  the sentence
	int num1 = question[0]-'0';//convert from ascii
	int num2 = question[2]-'0';
	
 	std::string x = "+-*/^" ;
	 if (std::find(word_vector.begin(), word_vector.end(), x[0]) != word_vector.end()) // std;;find searches the vector from its beginning to its end and returns an  iterator pointing to the 1st obj if found and points to 
	  //the last obj if  not found
	 {
  	  		int result = add(num1, num2);
 			std::cout<<result;
	 }
	  else if (std::find(word_vector.begin(), word_vector.end(), x[1]) != word_vector.end()) 
	 
	 {
  	  		int result = subtract(num1, num2);
 			std::cout<<result;
	 }
	   else if (std::find(word_vector.begin(), word_vector.end(), x[2]) != word_vector.end()) 
	 
	 {
  	  		int result = multiply(num1, num2);
 			std::cout<<result;
	 }
	   else if (std::find(word_vector.begin(), word_vector.end(), x[3]) != word_vector.end()) 
	 
	 {
  	  		int result = division(num1, num2);
 			std::cout<<result;
	 }
	   else if (std::find(word_vector.begin(), word_vector.end(), x[4]) != word_vector.end()) 
	 
	 {
  	  		int result = power(num1, num2);
 			std::cout<<result;
	 }
	  else{
	    	std::cout<<"I dont support that operation";
	  }
}
/*std::istringstream stream(sentence);// allows me to extract words
    char word; // variable that will be used to store extracted words
    while (stream >> word) {  // Reads space-separated words into 'word'
        word_vector.push_back(word);*/
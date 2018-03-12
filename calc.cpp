//calc.cpp
//Aaron Nicanor
//anicanor

//Libraries included
#include<iostream>
#include<string>
#include<sstream>
#include<stdlib.h>
#include<iomanip>
#include<math.h>
#include<cctype>

//Including stacks
#include"dstack.h"

using namespace std;

//Function declarations. Check their definitions for info on what they do
void error();
bool checkIfDecimal(double);
void popTwo(double&, double&);

//Function declarations for various operators
void multiply(double, double);
void divide(double, double);
void add(double, double);
void subtract(double, double);
void exponent(double, double);

//Declare a stack object
Dstack collec;

int main(){

//Variable declaration
char char_variable;
//next is the next input, value 1 and 2 are used in the functions, result is what is pushed to the stack
double input, next, value1 = 0, value2 = 0;

//While loop which handles the white space and utilizes cin.peek
while(cin.peek() != EOF){

	cin >> ws; //The ws stands for white space
	next = cin.peek();
	if( isdigit(next) || cin.peek() == '.'){
  
    	cin>>input;
    	if(cin.good()){
      
        	collec.push(input);
        	if(cin.peek() == '.'){
          
            	error();
        	}
     	}
      else{
      
        	error();
     	}
 	}
//ispunct() is from the cctype library. Basically just checks if the input is a punctuation character. Makes life easier
else if(ispunct(next)){

	cin>>char_variable;
  
	//These bits handle the operators
  if(char_variable == '*' && collec.size() >= 2){ //Multiply
  
    	multiply(value1, value2);
	}
  	else if (char_variable == '/' && collec.size() >= 2){ //Divide
	
    	divide(value1, value2);
	}
	else if(char_variable == '+' && collec.size() >= 2){ //Add

    	add(value1, value2);
	}
  else if (char_variable == '-' && collec.size() >= 2){ //Subtract
  
    	subtract(value1, value2);
	}
	else if(char_variable == '^' && collec.size() >= 2){ //Exponent
  
      exponent(value1, value2);
	}
  //Sends error if the stack is not large enough use any of the operators
	else if (collec.size() < 2){
  
    	error();
	}
 }
 //Sends error if a letter is entered
 else if (isalpha(next)){
 
	error();
 }
}
if(collec.size() >= 2){

	error();
}
//Prints out the stack
collec.print();
return 0;
}


//Defining functions

//Multiply function. This along with the following functions operate generally the same.
void multiply(double value1, double value2){
      
      double result;
    	popTwo(value1, value2);
    	result = value1 * value2;
    	collec.push(result);
}
//Divide function
void divide(double value1, double value2){

      double result;
    	popTwo(value1, value2);
    	if(value2 == 0){ //Stops division by 0
      
        	error();
    	}
    	result = value1 / value2;
    	collec.push(result);
}
//Add function
void add(double value1, double value2){

      double result;
    	popTwo(value1, value2);
    	result = value1 + value2;
    	collec.push(result);
}
//Subtract function
void subtract(double value1, double value2){
 
      double result;
    	popTwo(value1, value2);
    	result = value1 - value2;
    	collec.push(result);
}
//Exponent function. Unlike the other operator functions, this one has to deal with a few more error checks
void exponent(double value1, double value2){

      double result;
    	popTwo(value1, value2);
    	if(value1 < 0 && checkIfDecimal(value2)){
      
        	error();
    	}
    	result = pow(value1, value2);
    	if(isinf(result)){
      
        	error();
    	}
    	collec.push(result);
}

//Function that creates the error message. Used often so I decided to make it a function.
void error(){

	cerr << "Error: Invalid expression."<<endl;
	exit(1);
}

//Function that checks if the value was decimal. True if it was, false if it wasn't
bool checkIfDecimal(double input){

  //Used online resources to help check this stuff, and I used them as reference
	ostringstream changer;
 	string num;
	changer << input;
	num = changer.str();
	int numLength = num.length();
  
		for(int i = 0; i < numLength; i++){
    			if(num[i] == '.'){ //Looks for any period, returns true if there is (confirms it's a decimal). If not, false
    	
        			return true;
    			}
		}
	return false;
}

//Function that removes the two inputed values from the stack
void popTwo(double &value1, double &value2){

	collec.pop(value2);
	collec.pop(value1);
}

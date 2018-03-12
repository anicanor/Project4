//dstack.cpp
//Aaron Nicanor
//anicanor
#include<iostream>
#include<string>

#include"dstack.h"

using namespace std;

//constructor
Dstack::Dstack(){
        
        top = NULL;
}

//destructor
Dstack::~Dstack(){
        
        Node *ptr = top;
        while (ptr != NULL){
                
                Node *temp;
                temp = ptr;
                ptr = ptr->m_next;
                delete temp;
        }
}
//Removes from the stack
bool Dstack::pop (double &value){
        
        if (top==NULL){
                
                return false;
        }
        if (top->m_next==NULL){
                
                Node*temp = top;
                value = temp->m_value;
                top = temp->m_next;
                delete temp;
                return true;
        }
        Node *temp = top;
        value = temp->m_value;
        top = temp ->m_next;
        delete temp;
        return true;
}
//Adds to the stack
void Dstack::push (double value){
        
        top = new Node (value, top );
}
//Gives the stack's size
int Dstack::size(){
        
        int num = 0;
        if (top==NULL){
                
                return num;
        }
        Node *ptr = top;
        while (ptr!=NULL){
                
                ptr = ptr->m_next;
                num++;
        }
        return num;
}
//Clears out the stack
bool Dstack::empty(){
        
        if (top==NULL){
                
                return true;
        }else{
                
                return false;
        }
}
//Prints the top of the stack. Chose to do this since in this project, I should only be printing out one value
void Dstack::print(){
        
        Node *ptr = top;
        cout<<ptr->m_value<<endl;
}

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
        while (ptr != NULL)
        {
                Node *temp;
                temp = ptr;
                ptr = ptr->m_next;
                delete temp;
        }
}

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

void Dstack::push (double value){
        
        top = new Node (value, top );
}

int Dstack::size(){
        
        int num = 0;
        if (top==NULL)
        {
                return num;
        }
        Node *ptr = top;
        while (ptr!=NULL)
        {
                ptr = ptr->m_next;
                num++;
        }
        return num;
}

bool Dstack::empty(){
        
        if (top==NULL){
                
                return true;
        }else{
                
                return false;
        }
}

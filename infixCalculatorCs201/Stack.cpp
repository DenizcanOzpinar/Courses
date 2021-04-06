

    #include "Stack.h"
    Stack::Stack(){
        head = 0;
    }

    void Stack::push(StackItem *q){
        if(head == 0){
            head = q ;
            q->next = 0;
        }else {
            q->next=head ;
            head=q ;
        }
    }

    StackItem* Stack::pop(){
        StackItem *tmp = 0;
        if(head != 0) {
            tmp = head;
            head=tmp->next;
            
        }
        return tmp;
        
    }

    StackItem* Stack::top(){
        return head ;
    }

    Stack::~Stack(){
        while ( !this->isEmpty()) {
            delete this->pop();
        }
        
    }

    bool Stack::isEmpty(){
        if(head==0){
             return true ;
        }
        else{
            return false ;
            }
    }


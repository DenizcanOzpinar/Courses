                    #include "Calculator.h"



                    Calculator::Calculator(string infixExpression ){
                        s = new Stack();
                        string a;
                        string token;
                        istringstream iss(infixExpression);
                        iss >> token;
                        while(token.compare(";") != 0) {
                            StackItem *item = new StackItem(token) ;
                            if(item->isOperator == false){
                                a+=item->toString() + " " ;
                                
                            }
                            else if (item->isOperator == true){
                                if (item->op==0) {
                                    s->push(item);
                                    
                                }
                                else if (item->op==1){
                                    while (s->isEmpty()==false && (s->top()->op!=0)) {
                                        
                                            a+=s->pop()->toString() + " " ;
                                        
                                    }
                                    s->pop();
                                }
                                else if (item->op==5  || item->op==4 || item->op==3 || item-> op==2){
                                     while ((!s->isEmpty() && s->top() != 0) && (item->op <= s->top()->op)) {
                                       
                                        StackItem* temp1 = s->pop();
                                         
                                         
                                        a+=temp1->toString() + " ";
                                        
                                             delete temp1;
                                        
                                    }
                                    
                                    if (s->isEmpty()==true) {
                                        s->push(item);
                                       
                                    }
                                    
                                    if (s->isEmpty()==false && item->op > s->top()->op) {
                                        
                                        s->push(item) ;
                                        
                                    }
                                    
                                }
                            }
                            iss >> token;
                        }
                        while(s->isEmpty() == false) {
                            StackItem *tmp = s->pop();
                            a += tmp->toString() + " " ;
                            
                            delete tmp;
                        }
                        a += ";";
                        postfixExpression = a ;
                        
                    }
                     string Calculator::getPostfix(){
                         return postfixExpression;
                    }

                int Calculator::calculate(){
                    s = new Stack();
                    istringstream iss(postfixExpression);
                    string token;
                    string tmp;
                    iss >> token;
                    
                    while(token.compare(";") != 0) {
                        StackItem *item = new StackItem(token) ;
                        if(item->isOperator==false){
                            s->push(item);
                        }
                        else{
                            if(item->op==5){
                                int inttmp;
                                int inttmp2;
                            StackItem *tmp1 = s->pop();
                                inttmp = tmp1->n;
                            
                            StackItem *tmp2 = s->pop();
                                inttmp2 = tmp2->n;
                                
                                int result = inttmp2 * inttmp;
                                s->push(new StackItem(false,result));
                   
                                delete tmp1;
                                delete tmp2;
                            
                                
                            }
                            else if(item->op==4){
                                int inttmp;
                                int inttmp2;
                                StackItem *tmp1 = s->pop();
                                inttmp = tmp1->n;
                                
                                StackItem *tmp2 = s->pop();
                                inttmp2 = tmp2->n;
                                
                                int result = inttmp2 / inttmp;
                                s->push(new StackItem(false,result));
                                
                                delete tmp1;
                                delete tmp2;
                                
                            }
                            else if(item->op==3){
                                int inttmp;
                                int inttmp2;
                                StackItem *tmp1 = s->pop();
                                inttmp = tmp1->n;
                                
                                StackItem *tmp2 = s->pop();
                                inttmp2 = tmp2->n;
                                
                                int result = inttmp2 + inttmp;
                                s->push(new StackItem(false,result));
                                
                                delete tmp1;
                                delete tmp2;
                                
                            }
                            else if(item->op==2){
                                int inttmp;
                                int inttmp2;
                                StackItem *tmp1 = s->pop();
                                inttmp = tmp1->n;
                                
                                StackItem *tmp2 = s->pop();
                                inttmp2 = tmp2->n;
                                
                                int result = inttmp2 - inttmp;
                                s->push(new StackItem(false,result));
                                
                                delete tmp1;
                                delete tmp2;
                                
                            }
                        }
                        
                        iss >> token;
                    
                    }
                    int finalresult;
                    StackItem *tmpfinal = s->pop();
                    finalresult = tmpfinal->n;
                    delete tmpfinal;
                    return finalresult;
                }


            Calculator::~Calculator(){
                delete s ;
                    }



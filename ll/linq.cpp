#include<iostream>
using namespace std;
struct node{
int data;
struct node *next;
};
class q	{
    private:
        node *r;
        node *f;
    public:
        q();
        void enq();
        void dq();
        void display();
};
q::q(){
    r = NULL;
    f = NULL;
}
void q::enq(){
    int data;
    node *t = new node;
    cout<<"Enter the data to enq: ";
    cin>>data;
    t->data = data;
    t->next = NULL;
    if(f == NULL){
        f = t;
    }else{
        r->next = t;
    }
    r = t;
}
void q::dq(){
    node *t = new node;
    if(f == NULL){
        cout<<"\nq is Emtpty\n";
    }else{
        t = f;
        f = f->next;
        cout<<"The data dqd is "<<t->data;
        delete t;
    }
}
void q::display(){
    node *p = new node;
    p = f;
    if(f== NULL){
        cout<<"\nq is empty\n";
    }else{
        while(p!=NULL){
            cout<<endl<<p->data;
            p = p->next;
        }
    }
}
int main(){
    q q;int l=1;
    int c;
    while(l){
    cout<<"\n1.Enq\n2. dq\n3. Display\n 4.Quit";
    cout<<"\nEnter your choice: ";
    cin>>c;
    switch(c){
    case 1:q.enq();break;
    case 2:q.dq();break;
    case 3:q.display();break;
    case 4:l=0;break;}
    }
    return 0;
}

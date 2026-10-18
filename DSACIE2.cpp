
#include<iostream>
#include<string>
using namespace std;

class node{
    public:
        int empid;
        string name,dep,des;
        double sal;
        node *next;
        node *prev;
};

class dll{
    node *head;
    public:
        void create();
        void display();
        void insertst();
        void insertend();
        void insertbet();
        void del();
        int search();

        // Quick Sort functions
        node* gettail(node*);
        node* partition(node*,node*);
        void quicksort(node*,node*);
        void quicksort();

        dll(){
            head=NULL;
        }
};

void dll::create(){
    int n;
    cout<<"Enter number of employee data you want to store=";
    cin>>n;
    node *p,*q=NULL;

    for(int i=0;i<n;i++){
        p=new node;
        cout<<"Enter employee id=";
        cin>>p->empid;
        cout<<"Enter employee name=";
        cin>>p->name;
        cout<<"Enter employee department=";
        cin>>p->dep;
        cout<<"Enter employee designation=";
        cin>>p->des;
        cout<<"Enter employee salary=";
        cin>>p->sal;

        p->next=NULL;
        p->prev=NULL;

        if(head==NULL){
            head=p;
        }else{
            q->next=p;
            p->prev=q;
        }
        q=p;
    }
}

void dll::insertst(){
    node *p;
    p=new node;

    cout<<"Enter employee id=";
    cin>>p->empid;
    cout<<"Enter employee name=";
    cin>>p->name;
    cout<<"Enter employee department=";
    cin>>p->dep;
    cout<<"Enter employee designation=";
    cin>>p->des;
    cout<<"Enter employee salary=";
    cin>>p->sal;

    p->prev=NULL;
    p->next=head;

    if(head==NULL){
        head=p;
    }else{
        head->prev=p;
        head=p;
    }
}

void dll::insertend(){
    node *p,*q=head;
    p=new node;

    cout<<"Enter employee id=";
    cin>>p->empid;
    cout<<"Enter employee name=";
    cin>>p->name;
    cout<<"Enter employee department=";
    cin>>p->dep;
    cout<<"Enter employee designation=";
    cin>>p->des;
    cout<<"Enter employee salary=";
    cin>>p->sal;

    p->next=NULL;

    if(head==NULL){
        head=p;
        p->prev=NULL;
    }else{
        while(q->next!=NULL){
            q=q->next;
        }
        q->next=p;
        p->prev=q;
    }
}

void dll::insertbet(){
    if(head==NULL){
        cout<<"Dataset is empty.\n";
        return;
    }

    int val;
    cout<<"Enter empid after which you have to insert data=";
    cin>>val;

    node *q=head;

    while(q!=NULL && q->empid!=val){
        q=q->next;
    }

    if(q==NULL){
        cout<<"Employee ID not found.\n";
        return;
    }

    node *p=new node;

    cout<<"Enter employee id=";
    cin>>p->empid;
    cout<<"Enter employee name=";
    cin>>p->name;
    cout<<"Enter employee department=";
    cin>>p->dep;
    cout<<"Enter employee designation=";
    cin>>p->des;
    cout<<"Enter employee salary=";
    cin>>p->sal;

    p->next=q->next;
    p->prev=q;

    if(q->next!=NULL){
        q->next->prev=p;
    }

    q->next=p;
}

void dll::del(){
    if(head==NULL){
        cout<<"Dataset is empty.\n";
        return;
    }

    int val;
    cout<<"Enter empid you want to delete=";
    cin>>val;

    node *p=head;

    while(p!=NULL && p->empid!=val){
        p=p->next;
    }

    if(p==NULL){
        cout<<"Employee ID not found.\n";
        return;
    }

    if(p->prev!=NULL){
        p->prev->next=p->next;
    }else{
        head=p->next;
    }

    if(p->next!=NULL){
        p->next->prev=p->prev;
    }

    delete p;
    cout<<"Employee deleted successfully.\n";
}

void dll::display(){
    if(head==NULL){
        cout<<"Dataset is empty.\n";
        return;
    }

    node *p=head;

    while(p!=NULL){
        cout<<"\nEmployee ID="<<p->empid;
        cout<<"\nEmployee Name="<<p->name;
        cout<<"\nEmployee Department="<<p->dep;
        cout<<"\nEmployee Designation="<<p->des;
        cout<<"\nEmployee Salary="<<p->sal<<endl;

        p=p->next;
    }
}

// Find last node
node* dll::gettail(node *cur){
    while(cur!=NULL && cur->next!=NULL){
        cur=cur->next;
    }
    return cur;
}

// Partition according to salary in descending order
node* dll::partition(node *low,node *high){
    double pivot=high->sal;
    node *i=low->prev;

    for(node *j=low;j!=high;j=j->next){
        if(j->sal>=pivot){
            i=(i==NULL)?low:i->next;

            swap(i->empid,j->empid);
            swap(i->name,j->name);
            swap(i->dep,j->dep);
            swap(i->des,j->des);
            swap(i->sal,j->sal);
        }
    }

    i=(i==NULL)?low:i->next;

    swap(i->empid,high->empid);
    swap(i->name,high->name);
    swap(i->dep,high->dep);
    swap(i->des,high->des);
    swap(i->sal,high->sal);

    return i;
}

// Recursive Quick Sort
void dll::quicksort(node *low,node *high){
    if(low==NULL || high==NULL ||
       low==high || low==high->next){
        return;
    }

    node *p=partition(low,high);

    if(p!=low){
        quicksort(low,p->prev);
    }

    if(p!=high){
        quicksort(p->next,high);
    }
}

// Call Quick Sort
void dll::quicksort(){
    if(head==NULL){
        cout<<"Dataset is empty.\n";
        return;
    }

    node *tail=gettail(head);
    quicksort(head,tail);

    cout<<"Employees sorted by salary in descending order.\n";
}

int dll::search(){
    if(head==NULL){
        cout<<"Dataset is empty.\n";
        return -1;
    }

    int val;
    cout<<"Enter employee id you want to search=";
    cin>>val;

    // Linear search works even after sorting by salary
    node *p=head;

    while(p!=NULL){
        if(p->empid==val){
            cout<<"Employee found successfully\n";
            cout<<"Id="<<p->empid<<endl;
            cout<<"Name="<<p->name<<endl;
            cout<<"Department="<<p->dep<<endl;
            cout<<"Designation="<<p->des<<endl;
            cout<<"Salary="<<p->sal<<endl;
            return p->empid;
        }
        p=p->next;
    }

    cout<<"Employee with id "<<val<<" not found.\n";
    return -1;
}

int main(){
    dll d1;
    int n;

    d1.create();
    d1.display();

    do{
        cout<<"\nEnter 1 to insert employee data at starting.\n";
        cout<<"Enter 2 to insert employee data at ending.\n";
        cout<<"Enter 3 to insert employee data in between.\n";
        cout<<"Enter 4 to delete data.\n";
        cout<<"Enter 5 to search employee data.\n";
        cout<<"Enter 6 to sort salaries from highest to lowest.\n";
        cout<<"Enter 7 to exit.\n";
        cout<<"Enter your choice=";
        cin>>n;

        switch(n){
            case 1:
                d1.insertst();
                d1.display();
                break;

            case 2:
                d1.insertend();
                d1.display();
                break;

            case 3:
                d1.insertbet();
                d1.display();
                break;

            case 4:
                d1.del();
                d1.display();
                break;

            case 5:
                d1.search();
                break;

            case 6:
                d1.quicksort();
                d1.display();
                break;

            case 7:
                cout<<"Exiting program.\n";
                break;

            default:
                cout<<"Invalid number choice. Try again.\n";
        }

    }while(n!=7);

    return 0;
}

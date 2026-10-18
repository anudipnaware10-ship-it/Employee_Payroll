#include<iostream>
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
		dll(){
			head=NULL;
		}
};
void dll::create(){
	int n;
	cout<<"Enter number of emplyoee data you want to store=";
	cin>>n;
	node *p,*q;
	for(int i=0;i<n;i++){
		p=new node;
		cout<<"Enter emplyoee id=";
		cin>>p->empid;
		cout<<"Enter emplyoee name=";
		cin>>p->name;
		cout<<"Enter emplyoee department=";
		cin>>p->dep;
		cout<<"Enter emplyoee designation=";
		cin>>p->des;
		cout<<"Enter emplyoee salary=";
		cin>>p->sal;
		p->next=NULL;
		p->prev=NULL;
		if(head==NULL){
			head=p;
			q=p;
		}else{
			q->next=p;
			p->prev=q;
			q=p;
		}
	}
}
void dll::insertst(){
	node *p;
	p=new node;
	cout<<"Enter emplyoee id=";
	cin>>p->empid;
	cout<<"Enter emplyoee name=";
	cin>>p->name;
	cout<<"Enter emplyoee department=";
	cin>>p->dep;
	cout<<"Enter emplyoee designation=";
	cin>>p->des;
	cout<<"Enter emplyoee salary=";
	cin>>p->sal;
	if(head==NULL){
		head=p;
		p->next=NULL;
		p->prev=NULL;
	}else{
		p->next=head;
		head->prev=p;
		head=p;
	}
}
void dll::insertend(){
	node *p,*q=head;
	p=new node;
	cout<<"Enter emplyoee id=";
	cin>>p->empid;
	cout<<"Enter emplyoee name=";
	cin>>p->name;
	cout<<"Enter emplyoee department=";
	cin>>p->dep;
	cout<<"Enter emplyoee designation=";
	cin>>p->des;
	cout<<"Enter emplyoee salary=";
	cin>>p->sal;
	if(head==NULL){
		head=p;
		p->next=NULL;
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
	node *p,*q=head;
	p=new node;
	cout<<"Enter emplyoee id=";
	cin>>p->empid;
	cout<<"Enter emplyoee name=";
	cin>>p->name;
	cout<<"Enter emplyoee department=";
	cin>>p->dep;
	cout<<"Enter emplyoee designation=";
	cin>>p->des;
	cout<<"Enter emplyoee salary=";
	cin>>p->sal;
	int val;
	cout<<"Enter empid after which you have to insert data=";
	cin>>val;
	if(head==NULL){
		head=p;
		p->next=NULL;
		p->prev=NULL;
	}else{
		while(q->data!=val){
			q=q->next;
		}
		p->next=q->next;
		q->next=p;
		p->prev=q;
		(q->next)->prev=p;
	}	
}
void dll::del(){
	node *p=head,*q=head;
	int val;
	cout<<"Enter empid you want to delete=";
	cin>>val;
	if(head->empid==val){
		p=head;
		head=head->next;
		delete p;
	}else{
		while(p->empid!=val){
			q=p;
			p=p->next;
		}
		q->next=p->next;
		if(p->next!=NULL){
		(p->next)->prev=q;
	}
		delete p;
	}
}
void dll::display(){
	
}
int dll::search(){
	if(head==NULL){
		cout<<"dataset is empty\n";
		return -1;
	}
	int val;
	cout<<"Enter emplyoee id you want to search=";
	cin>>val;
	node *low=head;
	node *high=head;
	while(high->next!=NULL){
		high=high->next;
	}
	while(low!=NULL && high!=NULL && high!=low->prev){
		//slow fast approach to find mid value
		node *slow=low;
		node *fast=high;
		while(fast!=slow && fast->next!=slow){
			slow=slow->next;//moves slow 1 step forward
			fast=fast->prev;//moves fast 1 step backward
		}
		node *mid=slow;
		if(mid->empid==key){
			cout<<"Emplyoee found successfully\n";
			cout<<"Id="<<mid->empid<<endl;
			cout<<"Name="<<mid->name<<endl;
			cout<<"Departmet="<<mid->dep<<endl;
			cout<<"Designation="<<mid->des<<emdl;
			cout<<"Salary="<<mid->sal<<endl;
			return mid->empid;
		}else if(mid->empid<key){
			low=mid->next;
		}else{
			high=mid->prev;
		}
	}
	cout<<"Emplyoee with id "<<key<<"not found.\n";
	return -1;
}
int main(){
	dll d1;
	int n;
	d1.create();
	d1.display();
	do{
		cout<<"Enter 1 to insert emplyoee data at starting.\n";
		cout<<"Enter 2 to insert emplyoee data at ending.\n";
		cout<<"Enter 3 to insert emplyoee data in between.\n";
		cout<<"Enter 4 to delete data.\n";
		cout<<"Enter 5 to search emplyoee data.\n";
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
			default:
				cout<<"Invalid number choice.Try again.";
		}
	}while(n!=6);
}
#include <iostream> 
#include <vector>
#include <cstdlib>
using namespace std;

struct Node{
	int data;
	Node *next = NULL;
	Node *random = NULL;
	Node(int val){
		data = val;
		next = NULL;
		random = NULL;
	}
};

Node *add(Node *head,int val){
	if(head == NULL){
		return head = new Node(val);
	}
	Node* temp;
	for(temp = head;temp->next != NULL; temp = temp->next);
	
	temp->next = new Node(val);
	return head;
}

void display(Node *head){
	for(Node*temp = head;temp!=NULL;temp = temp->next)
		cout<<temp->data<<" ";
	cout<<endl;
}

Node *getNode(Node *head,int index){
//	cout<<index<<endl;
	Node *temp = head;
	for(int i=0;i<index;i++)
		temp = temp->next;
	return temp;
}

void randomize(Node *head,int size){
	Node *temp = head;
	while(temp!=NULL){
		int random_num = rand()%size-1;
		temp->random = getNode(head,random_num);
		temp = temp->next;
	}
	return;
}
int main(){
	Node *head = NULL;
	head = add(head,1);
	head = add(head,2);
	head = add(head,5);
	head = add(head,10);
	randomize(head,4);
	cout<<head->next->next->random->data<<endl;
}
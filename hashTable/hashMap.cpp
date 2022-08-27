#include <iostream>
#include <type_traits>
using namespace std;

template<typename T>
class Node{
	public:
	 T data;
	 Node* next = NULL;
	 Node(T n){
	 	this->data = n;
	 }
}; 

template<typename P>
class Linklist{
	Node<P>* head = NULL;
	public:
	 inline bool isEmpty(){
	 	return this->head == NULL;
	 }
	 
	 void add(P value){
	 	Node<P>* temp = this->head;
	 	if(Linklist::isEmpty()){
	 		head = new  Node<P>(value);
	 		return;
	 	}
	 	
	 	while(temp->next != NULL){
	 		temp = temp->next;
	 	}
	 	temp->next = new Node<P>(value);
	 	return;
	 }
	 
	 void display(){
	 	Node<P>* temp = this->head;
	 	cout<<"[";
	 	while(temp != NULL){
	 		cout<<temp->data;
	 		if(temp->next != NULL)
	 		 cout<<",";
	 		temp = temp->next;
	 	}
	 	cout<<"]"<<endl;	
	 }
	 
	 Node<P>* get(P value){
	 	Node<P>* temp = this->head;
	 	while(temp != NULL){
	 		if (value == temp->data)
	 			return temp;
	 		temp = temp->next;
	 	}
	 	return NULL;
	 }
	 Node<P>* getHead(){
	 	return this->head;
	 }
};

template<typename P,typename Q>
class HashMap{
	Linklist<P>* hash;
	size_t size;
	int getIndex(P key){
		int index = 0;
		for(auto i : key)
			index += int(i);

		index = index%this->size;
		return index;
	}
	public:
	 HashMap(int n){
	 
	 	this->hash = new Linklist<P>[n];
	 	this->size = n;
	 };
	 
	 
	 void insert(P key,Q val){
	 	int index = HashMap::getIndex(key);
	     this->hash[index].add(val);
	 } 
	 
	 Q get(P key){
	 	int index = HashMap::getIndex(key);
	 	Node<Q>* node = this->hash[index].getHead();
	 	return node->data;
	 }
};



int main(){
	 HashMap<string,string> map(10);
	 map.insert("name","harshal mahapure");
	 map.insert("age","23");
	 cout<<map.get("name");
	 cout<<endl<<map.get("age");
}

	
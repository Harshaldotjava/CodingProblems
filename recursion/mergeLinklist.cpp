#include <iostream>
using namespace std;

int merge(Node *arr1[],int Node* arr2[]){
	if(arr1 == NULL)
		return arr2;
	if(arr2 == NULL)
		return arr1;
		
	if(arr1->data <= arr2->data){
		arr1->next = merge(arr1->next,arr2);
		return arr1;
	}
	else {
		arr2->next = merge(arr1,arr2->next);
		return arr2;
}


int main(int argc, char *argv[])
{
	
}
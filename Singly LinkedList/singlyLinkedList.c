/**
 * Author: Abdullah Ahmed
 * Date: 7th July 2024
 * Version: 1.0.0
 *
 * C implementation for Integer singly linked list with the below features (Functions)
 * 
 * Insert at the head of the list
 * Insert after known Node
 * Insert at the tail of the list
 * Find (Search) Node by value
 * Delete first Node
 * Delete last Node
 * Return Integer Sum of list elements
 * Return Floating Point Average of list elements
 *
 */

#include <stdio.h>
#include <stdlib.h>



struct node {
	int value;
	struct node *next;

};

typedef struct node node_i;

node_i *createNode(int value){
	node_i *newNode = malloc(sizeof(node_i));
	
	if(!newNode){
		return NULL;
	}
	newNode->value = value;
	newNode->next = NULL;
	return newNode;

}

node_i *insertAtHead(node_i *head, node_i *insertedNode){
	
	insertedNode->next = head;
	return insertedNode;
	
}

void insertAfterNode(node_i *nodeToInsertAfter, node_i *insertedNode){
		
	insertedNode->next = nodeToInsertAfter->next;
	nodeToInsertAfter->next = insertedNode;
}

void insertAtTail(node_i *head, node_i *insertedNode){
	node_i *temp = head;
	
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = insertedNode;
	insertedNode->next = NULL;
	
}

node_i *findNode(node_i *head, int value){
	
	node_i *tmp = head;
	while(tmp->next != NULL){
		
		if(tmp->value == value){
			return tmp;
		}
		tmp = tmp->next;
	}
	return NULL;

}

void deleteFirstNode(node_i *head){
	node_i *temp;
	temp = head;

	head = head->next;
	free(temp);

}

void deleteLastNode(node_i *head){
	node_i *current = head;
	node_i *prev = NULL;

	while(current->next != NULL){
		prev = current;
		current = current->next;
	}
	prev->next = NULL;
	free(current);
}

void printList(node_i *head){
	node_i *temp = head;

	while(temp != NULL){
		printf("%d - ", temp->value);
		temp = temp->next;
	}
	printf("\n");

}

long int integerSum(node_i *head){
	node_i *temp = head;
	int sum = 0;

	while(temp->next != NULL){
		sum = sum + temp->value;
		temp = temp->next;
	}
	return sum;
}

double floatingAverage(node_i *head){
	node_i *temp = head;
	double average = 0;
	double counter = 0;

	while(temp->next != NULL){
		average += (double) temp->value;
		counter++;
		temp = temp->next;
	}
	return average / counter;

}


int main(){
	
	node_i *head = NULL;
	node_i *tmp;

	for(int i = 0; i < 10; i++){
		tmp = createNode(i);
		tmp->next = head;
		head = tmp;
	}

	head = insertAtHead(head, createNode(1000));

	insertAfterNode(head, createNode(2000));
	deleteLastNode(head);
	printList(head);
	insertAtTail(head, createNode(3000));
	printList(head);
	deleteLastNode(head);
	printList(head);

	long int sum = integerSum(head);
	printf("List elements sum = %ld \n", sum);
	double average = floatingAverage(head);
	printf("List elements floating point average = %lf \n", average);
	printf("We found the node with the value = %d\n", findNode(head, 1000)->value);
	return 0;
}

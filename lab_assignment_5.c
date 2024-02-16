#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char letter;
	struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
{
	int count = 0;

	while(head != NULL){
		head = head->next;
		count++;
	}

	// returns the number of nodes counted
	return count;
}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head)
{
	// get the list length
	int len = length(head);

	// memory for the string
	char *res = malloc((len + 1)*sizeof(char));

	int i = 0;

	// going to traverse the list and copy char to the string
	while(head != NULL){
		res[i]=head->letter;
		head=head->next;
		i++;
	}

	// terminate the string using NULL
	res[len]= '\0';

	// returns the string
	return res;
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
	// new node allocation
	node* newNode = (node*)malloc(sizeof(node));

	newNode->letter = c;
	newNode->next = NULL;

	// makes the new node become the head if the list is emtpy
	if(*pHead == NULL){
		*pHead = newNode;
	}
	else{
		node* current = *pHead;

		while(current->next != NULL){
			current=current->next;
		}
		current->next=newNode;
	}
}

// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
	while(*pHead != NULL){
		node* temp= *pHead;
		*pHead = (*pHead)->next;

		free(temp);
	}
	*pHead = NULL;
}

int main(void)
{
	int i, strLen, numInputs;
	node* head = NULL;
	char* str;
	char c;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &strLen);
		for (i = 0; i < strLen; i++)
		{
			fscanf(inFile," %c", &c);
			insertChar(&head, c);
		}

		str = toCString(head);
		printf("String is : %s\n", str);

		free(str);
		deleteList(&head);

		if (head != NULL)
		{
			printf("deleteList is not correct!");
			break;
		}
	}

	fclose(inFile);
}
/*
-------------------------------------------------------------------------------------------------------------------------------------------|
|		Rev No			|			Author			|			Date			| 					Description							   |
-------------------------------------------------------------------------------------------------------------------------------------------|
|						|							|							|														   |
|		001				|		Faculy, UPES		|	17. Nov. 16				|	Linked list implementation for adding elements		   |
|						|							|							|	to the list and printing all the elements of the list. |
-------------------------------------------------------------------------------------------------------------------------------------------|
|						|							|							|														   |
|		002				|		Faculy, UPES		|	18. Nov. 16				|	1. insert() method renamed to insertAtEnd()		   |
|						|							|							|	2. added searching functionlity {search()} in the list
|						|							|							|	3. program is now menu driven
-------------------------------------------------------------------------------------------------------------------------------------------|
*/

worked

#include<stdio.h>
#include<stdlib.h>

struct Node
{
        char data;
        struct Node * next;
};

void insertAtEnd(struct Node**, char);       // insertAtEndAtEnd data to list at the end
int search(struct Node *, char *);		// searches for any word in the list
void printList(struct Node*);   // function should be declared only after declar
int getStrLength(char *);

int main()
{
        struct Node *myList;
        myList = NULL;          // initializing list to be NULL initially
        char searchFor[20];
        char yourText[140];
        int i = 0, choice;

        do
        {
        	puts("Please provide your choice");
        	puts("1: Insert at the end to the list");
        	puts("2: searching a word to the list");
        	puts("3: print the data of the list");
        	puts("4: Exit the program");
        	scanf("%d", &choice);
        	switch(choice)
        	{
        	case 1:
                puts("Enter the text(of max size 140) to be inserted to the list");
                gets(yourText);

                while(yourText[i] != '\0')
                	insertAtEnd(&myList, yourText[i++]);

                break;

        	case 2:
                puts("Enter the word of maximum length 20 to be searched in the list");
                gets(searchFor);
                if( search(myList, searchFor))	// if search() returns 1 meaning word found
                	puts("given word is present in the list");
                else
                	puts("Given word is not present in the list");

                break;

        	case 3:
        		printList(myList);

        		break;

        	default:
        		puts("Invalid choice provided");
        	}
        }while(choice != 4);
}

void insertAtEnd(struct Node **p_list, char ch)
{
        struct Node *tmp, *last_node; // last_node is taken so that p_list should not refer to last node at the end

		// the tmp node will store the information temporarily before it is insertedto the end of the list
        tmp = (struct Node *)malloc( sizeof(struct Node) );
        tmp->data = ch;
        tmp->next = NULL;

        if( *p_list == NULL )
        {
                *p_list = tmp;
                return;
        }

        last_node = *(p_list);	// assigning last_node the address of first node of the list
        while( (last_node)->next != NULL)
        	last_node = last_node->next;	// at the end of the iteration last_node will point to the last node of the list

        last_node->next = tmp;
}

/*		returns 1 if word is found in the list else returns 0		*/
int search(struct Node *p_list, char *searchFor)
{
		int i = 0, length, matchCount = 0;
		char letter;

		length = getStrLength(searchFor);
		if(length == 0)
			return 0;

		while(p_list != NULL)
		{
			letter = searchFor[i++];
			if( letter == '\0')
				break;
			else if( letter == p_list->data)
				matchCount++;
			else
			{
				matchCount = 0;
				i = 0;
			}
			p_list = p_list->next;
		}

		if( matchCount == length)
			return 1;
		else
			return 0;
}

void printList(struct Node *p_list)
{
        int i = 1;
        while( p_list != NULL )
        {
                printf("\n  Data at Node %d = %c", i++, p_list->data);
                p_list = p_list->next;
        }
}

/*		returns the length of the string passed		*/
int getStrLength(char *searchFor)
{
		int len = 0, i = 0;
		while(*(searchFor + i++) != 0)
			len++;
		return len;
}

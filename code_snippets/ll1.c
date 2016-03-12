#include<stdio.h>
#include<stdlib.h>
/* lets define structures here */
typedef struct node {
    int value;
    struct node *next; 
} _node;

 void insert_element( _node **head, int value) {
    if (*head == NULL) {
    /*EMPTY LIST*/
            printf("inside empty list \n");
	    _node * new_node = (_node*)malloc(sizeof(_node));
	    new_node->value = value;
	    new_node->next = NULL;
	    *head = new_node;
	    return;  
    } else {
	    _node * new_node = (_node*)malloc(sizeof(_node));
	    new_node->value = value;
	    new_node->next = *head;
	    *head = new_node;
	    return;
    }

return;
}

void display_list(_node *head) {
    int value = 1;
    if(head == NULL) {
        printf("nothing to display");
        return;
    } else {
        printf("displaying the list\n");
        while(head) {
		printf("value of node value %d = %d\n",value,head->value);
		head = head->next;
		value++;
        }
        return;
    }
}

void delete_node( _node **head, int value) {
    if(*head == NULL) {
    //NOTHING TO DELETE
    return;
    } else {
        if((*head)->value == value) {
        _node *temp = *head;
        *head = (*head)->next;
        free(temp);
        } else {
            _node *temp = *head;
            _node *temp_next  = NULL;
            while (temp->next) {
                if (temp->next->value == value ) {
                // found the node
                temp_next = temp->next;
                temp->next = temp->next->next;
                free(temp_next); 
                break; 
                } 
                temp = temp->next;
            } 
           
        }
         
    }
    
}

int main(int argc, char* argv[])
{
printf("Let us formulate the problem statement to understand the deletion process. Given a key, delete the first occurrence of this key in linked list.\nTo delete a node from linked list, we need to do following steps.\n1) Find previous node of the node to be deleted.\n2) Changed next of previous node.\n3) Free memory for the node to be deleted.\nSince every node of linked list is dynamically allocated using malloc() in C, we need to call free() for freeing memory allocated for the node to be deleted.\n");
//struct node *head = NULL;
//head = (struct node*)malloc(sizeof(_node));
    _node *head = NULL;
    insert_element(&head,1);
    insert_element(&head,2); 
    display_list(head);
    insert_element(&head,7);
    insert_element(&head,8);
    insert_element(&head,9);
    insert_element(&head,12);
    insert_element(&head,111);
    display_list(head);
    delete_node(&head,111);
    display_list(head);
    delete_node(&head,1);
    display_list(head);
    delete_node(&head,12);
    display_list(head);
    delete_node(&head,8);
    display_list(head);
return 0;
}

#include<stdio.h>
#include<stdlib.h>
//#include<stdibool.h>

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
    _node *temp = head;
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
	int count = count_nodes(temp);
	printf(" number of nodes = %d\n",count);
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

int count_nodes( _node *head) {
    if( head == NULL) {
        return 0;
    } else {
        int count = 0;
        while(head) {
        //printf("increased count\n ");
        count++;
        head = head->next;
        }
        return count;
    }
      
}

int detect_loop(_node *head) {
	_node* slow = head;
	_node* fast = head;  
            if(slow == fast->next || slow->next == fast->next->next) {
            printf("yes there is a loop\n");
            return 1;
            }
        //else
        slow = slow->next;
        fast = fast->next->next;
         
         while (fast && fast->next) {
            if(slow == fast || slow->next == fast->next) {
            printf("yes there is a loop\n");
            return 1;
            }
        slow = slow->next;
        fast = fast->next->next;
        } //while (fast || fast->next);
        printf("no loop\n");
        return 0;
}

/*void pairwise_swap(_node *head) {

if (!(head) || !(head->next))
	    return;

        _node * temp = head->next->next;

        _node * temp2 = head->next;
        head->next->next = head;

        head = temp2;
        head->next = temp;
    

        pairwise_swap(temp);
}*/

void pairwise_swap_wrapper(_node **head ) {


    if(!(*head) || !((*head)->next))
    	return;

    _node* prev = NULL;
    _node *curr = (*head);
    _node *next = (*head)->next;
    (*head) = next;

    


    while(curr) {

    if(prev && curr->next) {
    prev->next = curr->next;
    }
    if(next ) {
    curr->next = next->next;
    next->next = curr;
    prev = curr;
    }
    if(curr->next) {
    next = curr->next->next;
    } 
     

    curr= curr->next;
    display_list(*head);
    }


    //pairwise_swap(temp2);

    //(*head) = curr;

}

/*void pairwise_swap(_node *head) {

if (!(head) && !(head->next))
    return;

        _node * temp = head->next->next;

	head->next->next = head;

	head->next = temp;

	pairwise_swap(temp);
}*/



 

int main(int argc, char* argv[])
{
printf("Let us formulate the problem statement to understand the deletion process. Given a key, delete the first occurrence of this key in linked list.\nTo delete a node from linked list, we need to do following steps.\n1) Find previous node of the node to be deleted.\n2) Changed next of previous node.\n3) Free memory for the node to be deleted.\nSince every node of linked list is dynamically allocated using malloc() in C, we need to call free() for freeing memory allocated for the node to be deleted.\n");
//struct node *head = NULL;
//head = (struct node*)malloc(sizeof(_node));
/*  	
Pairwise swap elements of a given linked list

Given a singly linked list, write a function to swap elements pairwise. For example, if the linked list is 1->2->3->4->5 then the function should change it to 2->1->4->3->5, and if the linked list is 1->2->3->4->5->6 then the function should change it to 2->1->4->3->6->5.

*/
    _node *head = NULL;
    //insert_element(&head,9);
    insert_element(&head,8); 
   // display_list(head);
   // printf(" number of nodes = %d");
    insert_element(&head,7);
    insert_element(&head,6);
    insert_element(&head,5);
    insert_element(&head,4);
    insert_element(&head,3);
   // display_list(head);
    //delete_node(&head,111);
    //display_list(head);
    insert_element(&head,2);
    insert_element(&head,1);
    display_list(head);
    pairwise_swap_wrapper(&head);
    display_list(head);
    //head->next->next->next->next->next->next = head->next->next;
    //int give_answer = detect_loop(head);
    //delete_node(&head,1);
    //display_list(head);
    //delete_node(&head,12);
    //display_list(head);
    //delete_node(&head,8);
    //display_list(head);
return 0;
}

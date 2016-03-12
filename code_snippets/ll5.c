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

//Given two lists sorted in increasing order, create and return a new list representing the intersection of the two lists. The new list should be made with its own memory — the original lists should not be changed.

//For example, let the first linked list be 1->2->3->4->6 and second linked list be 2->4->6->8, then your function should create and return a third list as 2->4->6.

void intersect_list(_node **head_ref,_node *head1, _node *head2) {

  	_node *temp = NULL;

         
}

void print_reverse(_node * temp, int tmp) {
     static int count = 0;
     if (!temp)
         return;
     count++;
     print_reverse(temp->next,count);

     printf("value of node %d =  %d \n",count,temp->value);
     count--;
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
 

int main(int argc, char* argv[])
{
//struct node *head = NULL;
//head = (struct node*)malloc(sizeof(_node));

    _node *head = NULL;
    insert_element(&head,1);
    insert_element(&head,2); 
    display_list(head);
   // printf(" number of nodes = %d");
    insert_element(&head,7);
    insert_element(&head,8);
    insert_element(&head,9);
    insert_element(&head,12);
    insert_element(&head,111);
    display_list(head);
    //delete_node(&head,111);
    display_list(head);
    insert_element(&head,13);
    insert_element(&head,15);
    //head->next->next->next->next->next->next = head->next->next;
    int give_answer = detect_loop(head);
    print_reverse(head,0); 
    //delete_node(&head,1);
    //display_list(head);
    //delete_node(&head,12);
    //display_list(head);
    //delete_node(&head,8);
    //display_list(head);
return 0;
}

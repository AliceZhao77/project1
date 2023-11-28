#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
    struct node* next;
    int          data;
};

struct node* reverse(struct node* head);
struct node* array_to_list(int len, int array[]);
void print_list(struct node* head);

// DO NOT CHANGE THIS MAIN FUNCTION
#define MAX_INIT_LIST_LEN 100
/*
int main() {
    // Need to read in a number of ints into an array
    printf("How many numbers in list?: ");
    int list_size = 0;
    scanf("%d", &list_size);
    int initial_elems[MAX_INIT_LIST_LEN] = { 0 };
    int n_read = 0;
    while (n_read < list_size && scanf("%d", &initial_elems[n_read])) {
        n_read++;
    }

    // create linked list from first set of inputs
    struct node* head = NULL;
    if (n_read > 0) {
        // list has elements
        head = array_to_list(n_read, initial_elems);
    }

    struct node* new_head = reverse(head);
    print_list(new_head);

    return 0;
}
*/
//
// Place the list pointed to by head into reverse order.
// The head of the list is returned.
//
struct node* reverse(struct node* head) {
    // PUT YOUR CODE HERE (change the next line!)
    struct node* prev = NULL;
    struct node* next = NULL;
    if (head != NULL){
        next = head->next;
    }
    
    while (head!=NULL) {
        head->next=prev;
        prev = head;

        head = next;            //head向后移动一个
        if (head != NULL) {
            next = next->next;  //next向后移动一个
        }
    }
    return prev;
}
struct node* reverse1(struct node* head) {
    // PUT YOUR CODE HERE (change the next line!)
    struct node* pre = NULL;
    struct node* next = NULL;
    struct node* cur = head;
    
    while (cur)
    {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return pre;

}

// DO NOT CHANGE THIS FUNCTION
// create linked list from array of strings
/*
struct node* array_to_list(int len, int array[]) {
    struct node* head = NULL;
    int i = len - 1;
    while (i >= 0) {
        struct node* n = malloc(sizeof(struct node));
        assert(n != NULL);
        n->next = head;
        n->data = array[i];
        head = n;
        i -= 1;
    }
    return head;
}
*/
// DO NOT CHANGE THIS FUNCTION
// print linked list
/*
void print_list(struct node* head) {
    printf("[");

    for (struct node* n = head; n != NULL; n = n->next) {
        // If you're getting an error here,
        // you have returned an invalid list
        printf("%d", n->data);
        if (n->next != NULL) {
            printf(", ");
        }
    }
    printf("]\n");
}
*/

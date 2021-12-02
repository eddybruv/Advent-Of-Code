#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *add(struct node *, int);
void check(struct node *list);


int main(void){
    struct node *head;
    head = NULL;
    int i = 0, n;
    while (i < 2001){
        scanf("%d", &n);
        head = add(head, n);
        i++;
    }    
    check(head);
    return 0;
}

struct node *add(struct node *list, int n){
    struct node *new_node;
    new_node = malloc(sizeof(struct node));

    new_node->data = n;

    if(list == NULL){
        new_node->next = NULL;
        return new_node;
    }

    new_node->next = list;
    return new_node;
}

void check(struct node *list){
    int count = 0;
    
    list = list->next;
    while(list->next != NULL){
        if(list->data > list->next->data)
            count++;
        list = list->next;
    }
    printf("Count: %d", count);
}
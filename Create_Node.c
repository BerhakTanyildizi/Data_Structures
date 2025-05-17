#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
    int data ;
    struct Node* next;
}Node;

Node* create_node(int data){
    Node* new_node = (Node*)malloc(sizeof(Node));
    if(new_node == NULL){
        printf("Memory allocation failed\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}
void print_node(Node* node){
    while(node != NULL){
        printf("%d\n",node->data);
        node = node->next;
    }
    }


int main(){
    Node* node1 = create_node(3);
    Node* node2 = create_node(5);
    Node* node3 = create_node(13);
    Node* node4 = create_node(2);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    print_node(node1);

    // Free the memory
    free(node1);
    free(node2);
    free(node3);
    free(node4);
}

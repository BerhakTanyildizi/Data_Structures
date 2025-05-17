#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int Find_Lowest(struct Node* head){
    int min_value = head->data;
    struct Node* current_node = head->next;
    while(current_node != NULL){
        if(current_node->data < min_value){
            min_value = current_node->data;
        }
    current_node = current_node->next;
    
    }
    return min_value;
}
int main(){
    struct Node* node1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* node2 = (struct Node*) malloc(sizeof(struct Node));
    struct Node* node3 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* node4 = (struct Node*)malloc(sizeof(struct Node));

    node1->data = 56;
    node2->data = 20;
    node3 ->data =30;
    node4 ->data =40;

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = NULL ;

    printf("%d is the lowest node",Find_Lowest(node1));

}   
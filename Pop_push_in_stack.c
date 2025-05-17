#include<stdlib.h>
#include<stdio.h>

struct Node{
    char value;
    struct Node *next ;
};

struct Stack{
    struct Node *head;
    int size ; 
};

struct Stack *create_stack(){

    struct Stack *s = malloc(sizeof(struct Stack));
    s->head = NULL ;
    s->size = 0 ;
    return s ;
}

void push(struct Stack *s , char newvalue){
    struct Node *newNode = malloc(sizeof(struct Node));

    newNode->value = newvalue ;
    newNode->next = s->head;
    s->head = newNode ;
    s->size++ ;
}
char pop(struct Stack *s) {
    if (s->size == 0) {
        return ' ';
    }
    struct Node *popped = s->head;
    s->head = s->head->next;
    char poppedValue = popped->value;
    free(popped);
    s->size--;
    return poppedValue;
}
char peek(struct Stack *s){
    if(s->size == 0)
    return ' ';
    else{
        return s->head->value;
    }
}
        

int main(){
    struct Stack *myStack = create_stack();
    push(myStack,'A');
    push(myStack,'B');
    push(myStack,'C');

    pop(myStack);

    printf("Peek: %c\n", peek(myStack));


}

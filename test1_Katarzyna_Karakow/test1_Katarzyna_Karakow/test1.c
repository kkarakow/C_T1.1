#include<stdio.h>
#include<stdlib.h>
#include "Node.h"

void user_input(void);

int main()
{
    user_input();
}

// Print the biggest/max value among the numbers
void print_max_value(struct node* obj) {

    struct node* current = obj;
    int max = 0;
    printf("\nThe biggest/max value among the numbers: ");
    while (current != NULL) {
        max = current->value > max ? current->value : max;
        current = current->next;
    }
    printf("%d", max);
}

// Print the numbers back out in reverse sequence
void walk_list(struct node* start)
{
    struct node* current = start;

    printf("Reverse order: ");
    while (current != NULL) {
        printf(" %d ", current->value);
        current = current->next;
    }
}
// Ask the user to enter some integers 
void user_input() {

    struct node* start = NULL;
    struct node* tmp = NULL;

    int userInput = 0;

    while (userInput >= 0) {

        printf("Enter some integer:\n");
        scanf_s("%d", &userInput);

        if (userInput < 0) break; 
        tmp = (struct node*)malloc(sizeof(struct node));
        tmp->value = userInput;
        tmp->next = start;
        start = tmp;
    }

    walk_list(start);
    print_max_value(start);
    // Free up all the memory allocated with malloc()
    free(tmp);
}

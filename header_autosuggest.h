// Including the required libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Defining constants
#define MAX 50
char s[20];
// Defining the structure for a node of ternary search tree
struct Node
{
    char data;//to store the character of a word
    unsigned isEndOfString: 1;// True if this character is last character of one of the words
    struct Node *left, *eq, *right;//Left pointer, Right pointer and Equality pointer
};
//Defing functions used to implement auto-suggestion feature
struct Node* newNode(char data);
void insert(struct Node** root, char *word);
void traverseTSTUtil(struct Node* root, char* buffer, int depth);
void traverseTST(struct Node* root);
int searchTST(struct Node *root, char *word);

// C program to demonstrate Ternary Search Tree (TST) insert, travese
// and search operations
#include <stdio.h>
#include <stdlib.h>
#define MAX 50
char s[20];
// A node of ternary search tree
struct Node
{
    char data;

    // True if this character is last character of one of the words
    unsigned isEndOfString: 1;

    struct Node *left, *eq, *right;
};

// A utility function to create a new ternary search tree node
struct Node* newNode(char data)
{
    struct Node* temp = (struct Node*) malloc(sizeof( struct Node ));
    temp->data = data;
    temp->isEndOfString = 0;
    temp->left = temp->eq = temp->right = NULL;
    return temp;
}

// Function to insert a new word in a Ternary Search Tree
void insert(struct Node** root, char *word)
{
    // Base Case: Tree is empty
    if (!(*root))
        *root = newNode(*word);

    // If current character of word is smaller than root's character,
    // then insert this word in left subtree of root
    if ((*word) < (*root)->data)
        insert(&( (*root)->left ), word);

    // If current character of word is greate than root's character,
    // then insert this word in right subtree of root
    else if ((*word) > (*root)->data)
        insert(&( (*root)->right ), word);

    // If current character of word is same as root's character,
    else
    {
        if (*(word+1))
            insert(&( (*root)->eq ), word+1);

        // the last character of the word
        else
            (*root)->isEndOfString = 1;
    }
}

// A recursive function to traverse Ternary Search Tree
void traverseTSTUtil(struct Node* root, char* buffer, int depth)
{
    if (root)
    {
        // First traverse the left subtree
        traverseTSTUtil(root->left, buffer, depth);

        // Store the character of this node
        buffer[depth] = root->data;
        char c=root->data;
        printf("c=%c\n",c);
        if (root->isEndOfString)
        {
            buffer[depth+1] = '\0';
	        printf("s=%s  ",s);
            printf("buffer=%s\n",buffer);
        }
        // Traverse the subtree using equal pointer (middle subtree)
        traverseTSTUtil(root->eq, buffer, depth);
        // Finally Traverse the right subtree
        traverseTSTUtil(root->right, buffer, depth);
    }
}

// The main function to traverse a Ternary Search Tree.
// It mainly uses traverseTSTUtil()
void traverseTST(struct Node* root)
{
    char buffer[MAX];
    traverseTSTUtil(root, buffer, 0);
}

// Function to search a given word in TST
int searchTST(struct Node *root, char *word)
{
    if (!root)
        return 0;

    if (*word < (root)->data)
        return searchTST(root->left, word);

    else if (*word > (root)->data)
        return searchTST(root->right, word);

    else
    {
        if (*(word+1) == '\0')
        {//return root->isEndOfString;
	    //changes mde:
	    char t[20];
	    printf("word=%s\n",word);
	    printf("root->data=%c\n",(root)->data);

	   // traverseTST(root->right);
	    //traverseTST(root->left);
	    traverseTST(root->eq);
        }

        return searchTST(root->eq, word+1);
    }
}

// Driver program to test above functions
int main()
{
    struct Node *root = NULL;
    FILE* file = fopen("demotxt.txt", "r"); /* should check the result */
    char line[256];

    while (fgets(line, sizeof(line), file)) {
        /* note that fgets don't strip the terminating \n, checking its
           presence would allow to handle lines longer that sizeof(line) */
	int len=strlen(line);
	if(line[len-1]=='\n')
	{
		line[len-1]=0;
	}

         insert(&root,line);
    }
    /* may check feof here to make a difference between eof and io failure -- network
       timeout for instance */

    fclose(file);
    printf("root =%c",root->data);
    printf("Enter your text: ");
    scanf("%s",&s);
    //printf("Following is traversal of ternary search tree\n");
    //traverseTST(root);

    //printf("\nFollowing are search results for %s",);
    printf("Value of s before entering searchTST s=%s",s);
    searchTST(root, s);//? printf("Found\n"): printf("Not Found\n");
    return 0;
}


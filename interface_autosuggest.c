#include "header_autosuggest.h"
#include "implementation_autosuggest.c"
int main()
{
    struct Node *root = NULL;//root set to NULL
    FILE* file = fopen("Dataset/word_list.txt", "r"); //Open the txt file
    char line[256];

    while (fgets(line, sizeof(line), file)) {//read each line from the text file
        /* note that fgets don't strip the terminating \n, checking its
           presence would allow to handle lines longer that sizeof(line) */
	int len=strlen(line);
	if(line[len-1]=='\n')
	{
		line[len-1]=0;
	}

         insert(&root,line);//start inserting each word from the text file
    }
    fclose(file);//close the file here
    int exit = 0;
    while(!exit)
    {
        printf("Enter your text or Enter 0 to exit: ");//take the text from user
        scanf("%s",s);
        if(strcmp("0",s)!=0)
        {
          searchTST(root, s)? printf("\nNot Found\n"): printf("\n");
        }
        else
        {
          break;
        }

    }

    return 0;
}

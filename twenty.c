#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

struct node* create_game_tree()
{
    struct node* root = NULL;
    
    root = insert(root, 100, "Does it grow underground?", "");
    insert(root, 50, "Is it long in shape?", "");
    insert(root, 25, "Is it orange in color?", "");
    insert(root, 15, "", "It's a carrot!");
    insert(root, 35, "", "It's a parsnip!");
    insert(root, 75, "Is it red in color?", "");
    insert(root, 65, "", "It's a radish!");
    insert(root, 85, "", "It's a potato!");
    insert(root, 150, "Does it grow on a tree?", "");
    insert(root, 125, "Is it red in color?", "");
    insert(root, 115, "", "It's an apple!");
    insert(root, 135, "", "It's a peach!");
    insert(root, 175, "Is it red in color?", "");
    insert(root, 165, "", "It's a tomato!");
    insert(root, 185, "", "It's a pea!");
    
    return root;
}

void play_game(struct node* current)
{
    if (current == NULL)
    {
        return;
    }
    
    char answer;
    
    if (strlen(current->guess) > 0)
    {
        printf("%s\n", current->guess);
        printf("y/n: ");
        scanf(" %c", &answer);
        
        if (answer == 'y' || answer == 'Y')
        {
            printf("I win!\n");
        }
        else
        {
            printf("You win!\n");
        }
        return;
    }
    
    printf("%s\n", current->question);
    printf("y/n: ");
    scanf(" %c", &answer);
    
    if (answer == 'y' || answer == 'Y')
    {
        play_game(current->left);
    }
    else
    {
        play_game(current->right);
    }
}

int main()
{
    struct node* game_tree = create_game_tree();
    
    printf("Welcome! Press 'q' to quit or any other key to continue:\n");
    
    char c;
    scanf(" %c", &c);
    
    while (c != 'q' && c != 'Q')
    {
        printf("You think of a fruit or vegetable and I will try to guess it!\n");
        play_game(game_tree);
        
        printf("Press 'q' to quit or any other key to continue:\n");
        scanf(" %c", &c);
    }
    
    printf("Bye Bye!\n");
    
    return 0;
}
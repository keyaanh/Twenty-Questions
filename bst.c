#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

struct node* create_node(int data, char* question, char* guess)
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->question = (char*)malloc(strlen(question) + 1);
    strcpy(new_node->question, question);
    new_node->guess = (char*)malloc(strlen(guess) + 1);
    strcpy(new_node->guess, guess);
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

struct node* insert(struct node* root, int data, char* question, char* guess)
{
    if (root == NULL)
    {
        return create_node(data, question, guess);
    }
    
    if (data < root->data)
    {
        root->left = insert(root->left, data, question, guess);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data, question, guess);
    }
    
    return root;
}
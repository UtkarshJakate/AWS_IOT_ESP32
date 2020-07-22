#include <stdio.h>
#include <stdlib.h>

typedef struct node TreeNode;

struct node
{
    int data;
    struct node *left, *right;
};

//A function to create a new BST node
TreeNode *createNode(int item)
{
    TreeNode *temp =  (TreeNode *)malloc(sizeof(TreeNode));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

// A function to do inOrder traversal of BST 
void inOrder(TreeNode *root)
{
    
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ->", root->data);
        inOrder(root->right);
    }
}

// A function to do preOrder traversal of BST
void preOrder(TreeNode *root)
{
    
    if (root != NULL)
    {
        printf("%d ->", root->data);
        inOrder(root->left);
        inOrder(root->right);
    }
}

// A function to do postOrder traversal of BST
void postOrder(TreeNode *root)
{
    
    if (root != NULL)
    {
        inOrder(root->left);
        inOrder(root->right);
        printf("%d ->", root->data);
    }
}

// A function to insert a new node with given key in BST
TreeNode* insertNode(TreeNode* node, int data)
{
    if (node == NULL) return createNode(data);
    if (data < node->data)
        node->left  = insertNode(node->left, data);
    else if (data > node->data)
        node->right = insertNode(node->right, data);
    return node;
}


// To find min value in a tree
TreeNode * minValueNode(TreeNode* node)
{
    TreeNode* current = node;
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

// To find max value in a tree
TreeNode * maxValueNode(TreeNode* node)
{
    TreeNode* current = node;
    while (current && current->right != NULL)
        current = current->right;
    return current;
}

//To delete a node
TreeNode* deleteNode(TreeNode* root, int data)
{
    if (root == NULL) return root;

    if (data < root->data)
        root->left = deleteNode(root->left, data);

    else if (data > root->data)
        root->right = deleteNode(root->right, data);

    else
    {
        if (root->left == NULL)
        {
            TreeNode *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            TreeNode *temp = root->left;
            free(root);
            return temp;
        }

        TreeNode* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Driver Program to test above functions
int main()
{
    TreeNode *root = NULL;
    int ch, value;
    printf("\nMenu: Choose Suitable Option");
    printf("\n1 - Insert an element into tree\n");
    printf("2 - Delete an element from the tree\n");
    printf("3 - InOrder Traversal\n");
    printf("4 - preOrder Traversal\n");
    printf("5 - postOrder Traversal\n");
    printf("6 - Exit\n");
    while(1)
    {
        printf("\nEnter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", value);
            root = insertNode(root, value);
            break;
        case 2:
            printf("Enter value to be deleted: ");
            scanf("%d",&value);
            root = deleteNode(root,value);
            break;
        case 3:
            printf("InOrder Traverse: ");
            inOrder(root);
            break;
        case 4:
            printf("PretOrder Traverse: ");
            preOrder(root);
            break;
        case 5:
            printf("PosttOrder Traverse: ");
            postOrder(root);
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("Choose Different Option");
            break;
        }
    }
    return 0;
}

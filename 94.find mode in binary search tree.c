/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define HASH_SIZE 1000

struct hash_node
{
    int val;
    int freq;
    struct hash_node * next;
};

struct hash_node * hash_table[HASH_SIZE] = {NULL};

int hash_index(int val)
{
    if(val < 0)
        return ((-1 * val) % HASH_SIZE);
    
    return (val % HASH_SIZE);
}

void hash_insert(int val, int * mode)
{
    int index = hash_index(val);

    if(hash_table[index] == NULL)   //No node in the index
    {
        struct hash_node * new_node = (struct hash_node *)malloc(sizeof(struct hash_node));
        new_node->val = val;
        new_node->freq = 1;
        new_node->next = NULL;
        hash_table[index] = new_node;

        if(new_node->freq >= *mode)
        {
            *mode = new_node->freq;
        }
    }
    else
    {
        struct hash_node * trav = hash_table[index];
        struct hash_node * prev = NULL;
        while(trav && trav->val != val)
        {
            prev = trav;
            trav = trav->next;
        }

        if(trav == NULL)
        {
            struct hash_node * new_node = (struct hash_node *)malloc(sizeof(struct hash_node));
            new_node->val = val;
            new_node->freq = 1;
            new_node->next = NULL;
            prev->next = new_node;   

            if(new_node->freq >= *mode)
            {
                *mode = new_node->freq;
            }      
        }
        else if(trav->val == val)
        {
            trav->freq += 1;
            if(trav->freq >= *mode)
            {
                *mode = trav->freq;
            }
        }

    }
}

void traversal(struct TreeNode * root, int * mode)
{
    if(root)
    {
        hash_insert(root->val, mode);
        traversal(root->left, mode);
        traversal(root->right, mode);
    }
    return;
}

int count(struct TreeNode * root)
{
    if(root)
    {
        int lchild = count(root->left);
        int rchild = count(root->right);
        return (lchild + rchild + 1);
    }
    return 0;
}

int* findMode(struct TreeNode* root, int* returnSize) 
{
    int mode = INT_MIN;
    int i=0;
    for(i=0; i<HASH_SIZE; i++)
    {
        hash_table[i] = NULL;
    }

    traversal(root, &mode);
    int num_nodes = count(root);
    int * ret_arr = (int *)malloc(sizeof(int) * (num_nodes)); 
    int ret_arr_index = 0;

    for(i=0; i<HASH_SIZE; i++)
    {
        if(hash_table[i] != NULL)
        {
            struct hash_node * trav = hash_table[i];
            while(trav)
            {
                if(trav->freq == mode)
                {
                    ret_arr[ret_arr_index++] = trav->val;
                }
                trav = trav->next;
            }
        }
    }

    *returnSize = ret_arr_index;
    return ret_arr;
    
}

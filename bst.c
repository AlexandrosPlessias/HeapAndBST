#include <stdio.h>
#include <stdlib.h>
#include "header.h"


TreeNode *insertToBinaryTree(TreeNode *root, double x){

    TreeNode *currNode = root;  // currNode = current Tree node
    TreeNode *parentNode = NULL; // parentNode = parent of Current Node

    while (currNode != NULL){

        parentNode = currNode;
        if (x < currNode->val){
            currNode=currNode->left;
        }
        else if (x > currNode->val){
            currNode=currNode->right;
        }
        //Already exist check in MAIN.

    }

    TreeNode *tmp= (TreeNode*)malloc(sizeof(TreeNode));

    tmp->val=x;
    tmp->left=tmp->right=NULL;

    if (root != NULL){

        if (x < parentNode->val)
            parentNode->left=tmp;
        else
            parentNode->right=tmp;
    }
    else
        root=tmp;

    return root; // return root tree
}

void inorder(TreeNode *treeNode){

	if (treeNode != NULL) {
		inorder(treeNode->left);
        printf("<%.2f> ",treeNode->val);
		inorder(treeNode->right);
	}

	return;
}

double printBstMax(TreeNode *treeNode){

	if( treeNode == NULL){
        // NEVER HAPPEN.
		printf("Tree is Empty\n");
        exit(0);
	}

    while( treeNode->right != NULL ){

		treeNode=treeNode->right;
	}

	return treeNode->val;
}

void destroyBst(TreeNode *treeNode){

	if( treeNode != NULL){
		destroyBst(treeNode->left);
		destroyBst(treeNode->right);
		free(treeNode);
	}
}

int searchBst(TreeNode **root,double key){

    TreeNode *currNode = *root;// currNode = current Tree node (root of tree)
    TreeNode *parentNode = NULL; // parentNode = parent of Current Node
    int count=0;

    // search key in tree
    while(currNode!=NULL){

        count++;// increase count
        if (key < currNode->val){
            parentNode=currNode;
            currNode=currNode->left; // go to the left subtree
        }
        else if (key > currNode->val){
            parentNode=currNode;
            currNode=currNode->right; // go to the right subtree
        }
        else if(key == currNode->val){
            break;  // found
        }

    }//end of while

    return count;
}

TreeNode*removeBstd (TreeNode **root){

    TreeNode *currNode = *root;// currNode = current Tree node (root of tree)
    TreeNode *parentNode = NULL; // parentNode = parent of Current Node

    double key= printBstMax(* root); // element of tree node i want to delete

    /* A.Case delete tree root ex. 50 here

        (50)
         /
       (30)
    */
    if(currNode->val == key){ // if root is max
        *root=currNode->left;
        free(currNode);
    }
    /*B.Case delete pivot(akmi).
                OR
      C.Case delete leaf.
    */
    else{
        // Search key in tree
        while(currNode->right!=NULL)
        {
            if (key < currNode->val)
            {
                parentNode=currNode;
                currNode=currNode->left; // go to the left subtree
            }
            else if (key > currNode->val)
            {
                parentNode=currNode;
                currNode=currNode->right; // go to the right subtree
            }
            else if(key == currNode->right->val)
            {
                parentNode=currNode;
                break;  // found
            }

        }//end of while

        /* B.Case delete pivot with one child ex. 84 here
            (62)
            /  \
          (03) (81)
                 \
                (84)
                 /
               (82)
        */
        if((parentNode->right->left!=NULL) && (parentNode->right->val==key))
        {
            TreeNode *temp = parentNode->right; //old right node for free
            parentNode->right=parentNode->right->left;
            temp->right=NULL;
            free(temp);
        }
        /* C.Case delete leaf ex. 1854 here
            (62)
            /  \
          (03) (81)
                 \
               (1854)
        */
        else{
            parentNode->right=NULL;
            free(parentNode->right);
        }
    }
    return *root;
}

TreeNode* isValidRotation(TreeNode **root, double key){

    TreeNode *currNode = *root;// currNode = current Tree node (root of tree)
    TreeNode *parentNode = NULL; // parentNode = parent of Current Node

    // search key in tree
    while(currNode!=NULL){

        if (key < currNode->val){
            parentNode=currNode;
            currNode=currNode->left; // go to the left subtree
        }
        else if (key > currNode->val){
            parentNode=currNode;
            currNode=currNode->right; // go to the right subtree
        }
        else if(key == currNode->val){
            break;  // found
        }

    }//end of while

    if((currNode->left == NULL)&&(currNode->right == NULL)){    // Can't rotate.
        printf("->Can't Rotate element %.2f .\n",key);
        return *root;
    }
     else if(currNode->left != NULL)    // Right Rotation.
    {
        printf("->Element %.2f can perform Right Rotation.\n",key);
        return rotationsBst(root,key,0);
    }
    else if (currNode->right != NULL){  // Left Rotation.
        printf("->Element %.2f can't perform Right Rotation but can perform Left Rotation.\n",key);
        return rotationsBst(root,key,1);
    }
    else{
        printf("Something go wrong...\n");
        exit(0);
    }
}

TreeNode* rotationsBst(TreeNode **root, double key,int rotateID){

    TreeNode *currNode = *root;// currNode = current Tree node (root of tree)
    TreeNode *parentNode = NULL; // parentNode = parent of Current Node

    // Root case
    if(currNode->val == key)
    {
        if(rotateID == 0){
            *root=rightRotation(currNode);
        }
        else{
            *root=leftRotation(currNode);
        }
    }
    else{
        // search key in tree
        while(currNode!=NULL)
        {

            if (key < currNode->val)
            {
                parentNode=currNode;
                currNode=currNode->left; // go to the left subtree
            }
            else if (key > currNode->val)
            {
                parentNode=currNode;
                currNode=currNode->right; // go to the right subtree
            }
            else if(key == currNode->val)
            {
                break;  // found
            }

        }//end of while


        // Pivot case don't change root...
        // case parent with rotate left child.
        if(rotateID == 0){
            if((parentNode->left!=NULL)&&(parentNode->left->val==key)){
                parentNode->left=rightRotation(currNode);
            }else{
                parentNode->right=rightRotation(currNode);
            }
        }
        else{
            if((parentNode->right!=NULL)&&(parentNode->right->val==key)){
                parentNode->left=leftRotation(currNode);
            }else{
                parentNode->right=leftRotation(currNode);
            }
        }
    }

    return *root;
}

TreeNode *rightRotation(TreeNode *currNode){

    TreeNode *node;
    node = currNode->left;
    currNode->left = node->right;
    node->right= currNode;

    return node;
}

TreeNode *leftRotation(TreeNode *currNode){

    TreeNode *node;
    node = currNode->right;
    currNode->right = node->left;
    node->left= currNode;

    return node;
}

typedef struct TreeNode{
    double val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;


//---------------  utilities.c  -------------------
void displayTextArt();
int inputCheck();
double randomGenerator(double min, double max);
void swap(double *A,double *B);
int isFoundAgain(double num,int N,double *heap);
//-------------------------------------------------


//---------------  heap.c --------------------------
void insertToHeap(double key,int currentSize,int N,double *h);
double deleteMaxHeap(double *heap,int currentSize,int N);
double maxNumberOfHeap(double *);
void destroyHeap(double *);
void printHeap(int ,double *);
//-------------------------------------------------


//---------------  bst.c --------------------------
TreeNode* insertToBinaryTree(TreeNode *root, double x);
void inorder(TreeNode *treeNode);
double printBstMax(TreeNode *treeNode);
void destroyBst(TreeNode *treeNode);
int searchBst(TreeNode **root,double key);
TreeNode* removeBstd (TreeNode **root);
TreeNode* isValidRotation(TreeNode **root, double key);
TreeNode* rotationsBst(TreeNode **root, double key,int rotateID);
TreeNode* rightRotation(TreeNode *currNode);
TreeNode* leftRotation(TreeNode *currNode);
//-------------------------------------------------

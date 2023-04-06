/*
Given a Matrix mat of N*N size, the task is to complete the function constructLinkedMatrix(), that constructs a 2D linked list representation of the given matrix.

Input : 2D matrix 
1 2 3
4 5 6
7 8 9

Output :
1 -> 2 -> 3 -> NULL
|    |    |
v    v    v
4 -> 5 -> 6 -> NULL
|    |    |
v    v    v
7 -> 8 -> 9 -> NULL
|    |    |
v    v    v
NULL NULL NULL
Input:
The fuction takes 2 argument as input, first the 2D matrix mat[][] and second an integer variable N, denoting the size of the matrix.
There will be T test cases and for each test case the function will be called separately.

Output:
The function must return the reference pointer to the head of the linked list.

Constraints:
1<=T<=100
1<=N<=150

Example:
Input:
2
3
1 2 3 4 5 6 7 8 9
2
1 2 3 4
Output:
1 2 3 4 5 6 7 8 9
1 2 3 4

Note:The Input/Ouput format and Example given are used for system's internal purpose, and should be used by a user for Expected Output only. As it is a function problem, hence a user should not read any input from stdin/console. The task is to complete the function specified, and not to write the full code.
*/


/*structure of the node of the linked list is as
struct Node
{
	int data;
	Node* right, *down;
	
	Node(int x){
	    data = x;
	    right = NULL;
	    down = NULL;
	}
};
*/
// n is the size of the matrix
// function must return the pointer to the first element 
// of the in linked list i.e. that should be the element at arr[0][0]
Node* constructLinkedMatrix(int mat[MAX][MAX], int n)
{
    Node *leftCorner=NULL;
    Node *prevRow=NULL;
    for(int i=0;i<n;i++){
        Node *cpr=prevRow;
        Node *curRow=NULL,*curRowT=NULL;
        for(int j=0;j<n;j++){
            Node *node=new Node(mat[i][j]);
            //build cur row
            if(!curRow){
                curRow=curRowT=node;
            }else{
                curRowT->right=node;
                curRowT=node;
            }
            ////////////////////////////////
            if(cpr){//link prev row to cur row
                cpr->down=node;
                cpr=cpr->right;
            }
            if(!leftCorner){
                leftCorner=node;
            }
        }
        prevRow=curRow;
    }
    return leftCorner;
}
/*
DFS即Depth First Search.其过程简要来说是对每一个可能的分支路径深入到不能再深入为止，而且每个
节点只能访问一次.深度优先搜索可以从多点发起.如果将每个节点在深度优先搜索过程中的"结束时间"排
序（具体做法是创建一个list，然后在每个节点的相邻节点都已被访问的情况下，将该节点加入list结尾
，然后逆转整个链表)，则我们可以得到所谓的"拓扑排序",即topological sort.
*/

#include <iostream>
#include <stack>

using namespace std;

//#define maxn 1000
//
//int mazeArr[maxn][maxn];
//int stepArr[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
//int visit[maxn][maxn];
//int n;
//
struct Node {
	int value;
	Node *left; 
	Node *right;
//	Node(int val):value(val), left(NULL), right(NULL) {}
};
//

//非递归 
/*
void DFS_Iteration() {
	const int TREE_SIZE = 9;
	stack<Node*> visited, unvisited;
	Node nodes[TREE_SIZE];
	Node *current;
	for( int i=0; i<TREE_SIZE; i++) //初始化树
 	{
    	nodes[i].value = i;
    	int child = i*2+1;
     	if( child<TREE_SIZE ) //Left child
        	nodes[i].left = &nodes[child];
     	else
        	nodes[i].left = NULL;
     	child++;
     	if( child<TREE_SIZE ) //Right child    
    		nodes[i].right = &nodes[child];
     	else
    		nodes[i].right = NULL;
 	}
 	
 	unvisited.push(&nodes[0]);
 	
 	while(!unvisited.empty()) {
 		current = unvisited.top();
 		unvisited.pop();
 		
 		if (current->right != NULL)	//把右边压入 因为右边的访问次序是在左边之后
 			unvisited.push(current->right);
 		
 		if (current->left != NULL)
 			unvisited.push(current->left);
 		
 		cout << current->value << endl;
 		
 		visited.push(current);
 	}
}
*/
//递归 
void DFS(Node *cur) {
	cout << cur->value << endl; 
	if (cur->left != NULL)
		DFS(cur->left);
	if (cur->right != NULL)
		DFS(cur->right);
}


int main(int argc, char *argv[])
{
	const int TREE_SIZE = 9;
	stack<Node*> visited, unvisited;
	Node nodes[TREE_SIZE];
	Node *current;
		
	for( int i=0; i<TREE_SIZE; i++) //初始化树
	{
	    nodes[i].value = i;
	    int child = i*2+1;
	    if( child<TREE_SIZE ) //Left child
	       	nodes[i].left = &nodes[child];
	    else
	       	nodes[i].left = NULL;
	    child++;
	    if( child<TREE_SIZE ) //Right child    
	    	nodes[i].right = &nodes[child];
	    else
	    	nodes[i].right = NULL;
	}
	
	current = &nodes[0];
	DFS(current);
	return 0;
}

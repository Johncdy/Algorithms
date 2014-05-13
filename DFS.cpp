/*
DFS��Depth First Search.����̼�Ҫ��˵�Ƕ�ÿһ�����ܵķ�֧·�����뵽����������Ϊֹ������ÿ��
�ڵ�ֻ�ܷ���һ��.��������������ԴӶ�㷢��.�����ÿ���ڵ�������������������е�"����ʱ��"��
�򣨾��������Ǵ���һ��list��Ȼ����ÿ���ڵ�����ڽڵ㶼�ѱ����ʵ�����£����ýڵ����list��β
��Ȼ����ת��������)�������ǿ��Եõ���ν��"��������",��topological sort.
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

//�ǵݹ� 
/*
void DFS_Iteration() {
	const int TREE_SIZE = 9;
	stack<Node*> visited, unvisited;
	Node nodes[TREE_SIZE];
	Node *current;
	for( int i=0; i<TREE_SIZE; i++) //��ʼ����
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
 		
 		if (current->right != NULL)	//���ұ�ѹ�� ��Ϊ�ұߵķ��ʴ����������֮��
 			unvisited.push(current->right);
 		
 		if (current->left != NULL)
 			unvisited.push(current->left);
 		
 		cout << current->value << endl;
 		
 		visited.push(current);
 	}
}
*/
//�ݹ� 
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
		
	for( int i=0; i<TREE_SIZE; i++) //��ʼ����
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

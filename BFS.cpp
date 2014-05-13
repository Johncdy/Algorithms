/*
BFS��Breadth First Search�� BFS����ʹ�þ��鷨���㷨�����㷨�Ĺ۵㣬������Ϊչ���ڵ���õ�����
�ڵ㶼�ᱻ�ӽ�һ���Ƚ��ȳ��Ķ����С�һ���ʵ������ھӽڵ���δ��������Ľڵ�ᱻ������һ����
��Ϊ open �������У�������л�������������������Ľڵ��򱻷����ڱ���Ϊ closed �������С�
��open-closed��
*/

#include <iostream>
#include <queue>

using namespace std;

#define maxn 1000

/*����һ 
int mazeArr[maxn][maxn];
int stepArr[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
int visit[maxn][maxn];
int n;

struct Node {
	int x;
	int y;
	int step;
	Node(int x, int y, int step):x(x), y(y), step(step) {}
};

int BFS() {
	Node node(0, 0, 0);
	queue<Node> que;
	que.push(node);
	
	while(!que.empty()) {
		node = que.front();
		que.pop();
		if (node.x == n-1 && node.y == n-1) {
			return node.step;
		}
		visit[node.x][node.y] = 1;
		for (int i = 0; i < 4; i++) {
			int x = node.x + stepArr[i][0];
			int y = node.y + stepArr[i][1];
			if (x >= 0 && y >= 0 && x < n && y < n
				&& visit[x][y] == 0 && mazeArr[x][y] == 0) {
				visit[x][y] = 1;
				Node next(x, y, node.step+1);
				que.push(next);	
			}
		}
	}
	return -1;
}
*/
//��ʽ���� 

struct Node {
	int value;
	Node *left;
	Node *right;
};

void BFS() {
	const int TREE_SIZE = 9;
	queue<Node*> visited, unvisited;
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
		current = unvisited.front();
		
		if (current->left != NULL)
			unvisited.push(current->left);
			
		if (current->right != NULL)
			unvisited.push(current->right);
			
		visited.push(current);
		cout << current->value << endl;
		unvisited.pop();
	}
}

int main(int argc, char *argv[])
{
	BFS();
	return 0;
}

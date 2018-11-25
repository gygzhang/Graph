#define _CRT_SECURE_NO_WARNINGS 0
#include<stdio.h>
#include<iostream>
using namespace std;
#define INT_MAX _CRT_INT_MAX
#define MAX_VERTEX_NUM 20
//数组的方式
typedef enum {DG,DN,UDG,UDN}GraphKind;
typedef void* InfoType;
typedef double VertexTpye;
typedef int  VRType;
typedef struct ArcCell {
	VRType adj;
	InfoType info;
}ArcCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef struct {
	VertexTpye vexs[MAX_VERTEX_NUM];
	AdjMatrix arcs;
	int vexnum, arcnum;
	GraphKind kind;
}MGraph;

typedef struct ArcNode {
	int adjvex;
	int weight;
	struct ArcNode*nextarc;
	InfoType *info;
}ArcNode;
typedef struct VNode {
	VertexTpye data;
	ArcNode *firstarc;
}VNode,AdjList[MAX_VERTEX_NUM];
typedef struct {
	AdjList vertices;
	int vexnum, arcnum;
	int kind;
}ALGraph;

typedef struct QQueue {
	double *data;
	int front, rear;
};

void InitQueue(QQueue* Q) {
	Q->data = (double*)malloc(20 * sizeof(double));
	Q->front = Q->rear = 0;
}

void EnQueue(QQueue* Q, double data) {
	Q->data[Q->rear++] = data;
}

void DeQueue(QQueue *Q, double *v) {
	*v = Q->data[Q->front++];
}

bool QueueIsEmpty(QQueue Q) {
	return Q.front == Q.rear;
}

int LOC(MGraph G, double a) {
	for (int i = 0; i < G.vexnum; i++) {
		if (a == G.vexs[i]) return i;
	}
}

int LOC(ALGraph G, double a) {
	for (int i = 0; i < G.vexnum; i++) {
		if (a == G.vertices[i].data) return i;
	}
}

ArcNode* GetTail(ArcNode *AD) {
	ArcNode *a = AD;
	while (a->nextarc != NULL) {
		a = a->nextarc;
	}
	return a;
}

void CreateUDN(ALGraph *G) {
	scanf("%d %d", &G->vexnum, &G->arcnum);
	for (int i = 0; i < G->vexnum; i++) {
		scanf("%lf", &G->vertices[i].data);
		G->vertices[i].firstarc = NULL;
	}
	double a, b;
	//for (int i = 0; i < G->vexnum; i++) {
	while (true)
	{
		scanf("%lf %lf", &a, &b);
		if (a == 0 && b == 0) {
			//G->vertices[LOC(G,)].firstarc = NULL;
			return;
		}
		if (G->vertices[LOC(*G, a)].firstarc == NULL)
		{
			G->vertices[LOC(*G, a)].firstarc = (ArcNode*)malloc(sizeof(ArcNode));
			int m = LOC(*G, b);
			G->vertices[LOC(*G, a)].firstarc->adjvex = m;
			G->vertices[LOC(*G, a)].firstarc->info = NULL;
			G->vertices[LOC(*G, a)].firstarc->nextarc = NULL;
		}
		else {
			ArcNode* A = GetTail(G->vertices[LOC(*G, a)].firstarc);
			A->nextarc = (ArcNode*)malloc(sizeof(ArcNode));
			int m = LOC(*G, b);
			A->nextarc->adjvex = m;
			A->info = NULL;
			A->nextarc->nextarc = NULL;
		}
	}

	//}

}

void CreateDN(ALGraph *G) {
	scanf("%d %d", &G->vexnum, &G->arcnum);
	for (int i = 0; i < G->vexnum; i++) {
		scanf("%lf", &G->vertices[i].data);
		G->vertices[i].firstarc = NULL;
	}
	double a, b,w;
	//for (int i = 0; i < G->vexnum; i++) {
	while (true)
	{
		scanf("%lf %lf %lf", &a, &b,&w);
		if (a == 0 && b == 0&&w==0) {
			//G->vertices[LOC(G,)].firstarc = NULL;
			return;
		}
		if (G->vertices[LOC(*G, a)].firstarc == NULL)
		{
			G->vertices[LOC(*G, a)].firstarc = (ArcNode*)malloc(sizeof(ArcNode));
			int m = LOC(*G, b);
			G->vertices[LOC(*G, a)].firstarc->adjvex = m;
			G->vertices[LOC(*G, a)].firstarc->weight = w;
			G->vertices[LOC(*G, a)].firstarc->info = NULL;
			G->vertices[LOC(*G, a)].firstarc->nextarc = NULL;
		}
		else {
			ArcNode* A = GetTail(G->vertices[LOC(*G, a)].firstarc);
			A->nextarc = (ArcNode*)malloc(sizeof(ArcNode));
			int m = LOC(*G, b);
			A->nextarc->adjvex = m;
			A->nextarc->weight = w;
			A->info = NULL;
			A->nextarc->nextarc = NULL;
		}
	}

	//}

}

void CreateDG(ALGraph *G) {
	scanf("%d %d",&G->vexnum,&G->arcnum);
	for (int i = 0; i < G->vexnum; i++) {
		scanf("%lf",&G->vertices[i].data);
		G->vertices[i].firstarc = NULL;
	}
	double a,b;
	//for (int i = 0; i < G->vexnum; i++) {
		while (true)
		{
			scanf("%lf %lf", &a, &b);
			if (a == 0 && b == 0) {
				//G->vertices[LOC(G,)].firstarc = NULL;
				return; 
			}
			if (G->vertices[LOC(*G, a)].firstarc == NULL)
			{
				G->vertices[LOC(*G, a)].firstarc = (ArcNode*)malloc(sizeof(ArcNode));
				int m = LOC(*G, b);
				G->vertices[LOC(*G, a)].firstarc->adjvex = m;
				G->vertices[LOC(*G, a)].firstarc->info = NULL;
				G->vertices[LOC(*G, a)].firstarc->nextarc = NULL;
			}
			else {
				ArcNode* A = GetTail(G->vertices[LOC(*G, a)].firstarc);
				A->nextarc = (ArcNode*)malloc(sizeof(ArcNode));
				int m = LOC(*G, b);
				A->nextarc->adjvex = m;
				A->info = NULL;
				A->nextarc->nextarc = NULL;
			}
		}
		
	//}

}

void CreateUDG(MGraph *G) {
	scanf("%d %d", &G->vexnum, &G->arcnum);
	//getchar();
	for (int i = 0; i < G->vexnum; i++) scanf("%lf",&(G->vexs[i]));
	for (int i = 0; i < G->vexnum; i++) 
		for (int j = 0; j < G->vexnum; j++) {
			G->arcs[i][j].adj = INT_MAX;
			G->arcs[i][j].info = NULL;
	}
	double a, b, w; int i, j;
	for (int k = 0; k < G->arcnum; k++) {
		scanf("%lf %lf %lf", &a,&b,&w);
		i = LOC(*G, a); j = LOC(*G,b);
		G->arcs[i][j].adj = w;
		G->arcs[j][i] = G->arcs[i][j];
	}
}

void CreateDN(MGraph *G) {
	scanf("%d %d", &G->vexnum, &G->arcnum);
	//getchar();
	for (int i = 0; i < G->vexnum; i++) scanf("%lf", &(G->vexs[i]));
	for (int i = 0; i < G->vexnum; i++)
		for (int j = 0; j < G->vexnum; j++) {
			G->arcs[i][j].adj = INT_MAX;
			G->arcs[i][j].info = NULL;
		}
	double a, b, w; int i, j;
	for (int k = 0; k < 2*G->arcnum; k++) {
		scanf("%lf %lf %lf", &a, &b, &w);
		//if (a == b == w == 0) return;
		if (a == 0&&0 == w&&b == 0) return;
		i = LOC(*G, a); j = LOC(*G, b);
		G->arcs[i][j].adj = w;
		//G->arcs[j][i] = G->arcs[i][j];
	}
}

void CreateGraph(MGraph *G) {
	scanf("%d", G->kind);
	switch (G->kind)
	{
		//case DG:return CreateDG(G); break;
		//case DN:return CreateDN(G); break;
		//case UDG:return CreateUDG(G); break;
	//case UDN:return CreateUDN(G); break;
	default:perror("err");
	}
}

void Print(double v) {
	cout << v;
}

bool visited[20];
void (*V) (double v);

double FristAdjVex(MGraph G, double v) {
	int row = LOC(G, v);
	//cout << row;
	for (int col = 0; col <= G.vexnum; col++) {
		//cout << G.arcs[row][col].adj;
		if (G.arcs[row][col].adj != INT_MAX) 
			return G.vexs[col];
	}
	return -1;
}

double NextAdjVex(MGraph G, double v, double w) {
	int row = LOC(G, v);
	for (int col = LOC(G, w)+1; col < G.vexnum; col++) {
		if (G.arcs[row][col].adj != INT_MAX) return G.vexs[col];
	}
	return -1;
}

void DFS(MGraph G, double v) {
	cout << v;
	visited[LOC(G, v)] = true;
	//为什么会出错？？？
	/*visited[LOC(G, v)] = false;
	V(v);*/
	bool isdone=true;
	for (int i = 0; i < G.vexnum; i++) {
		//==!!!!!!!!!
		if (visited[i] == false) isdone = false;
	}
	
	if (isdone == true) return;

	for (double w = FristAdjVex(G, v); w >= 0; w = NextAdjVex(G, v, w)) {
		if (!visited[LOC(G,w)]) 
			DFS(G, w);
	}
}

void DFSTraverse(MGraph G, void(*visit)(double v)) {
	V = visit;
	for (int i = 0; i < G.vexnum; i++) visited[i] = false;
	for (int i = 0; i < G.vexnum; i++) {
		if (!visited[i]) DFS(G, G.vexs[i]);
	}
}

void BFSTraverse(MGraph G,void(*visit)(double v)) {
	QQueue Q; double w,u;
	for (int i = 0; i < G.vexnum;i++) visited[i] = false;
	InitQueue(&Q);
	for (int i = 0; i < G.vexnum; i++) {
		if (!visited[i]) {
			visit(G.vexs[i]);
			visited[i] = true;
			EnQueue(&Q, G.vexs[i]);
			while (!QueueIsEmpty(Q)) {
				DeQueue(&Q, &w);
				for (u = FristAdjVex(G, w); u >= 0; u = NextAdjVex(G, w,u)) {
					if (!visited[LOC(G, u)]) {
						visit(u);
						visited[LOC(G, u)] = true;
						EnQueue(&Q, u);
					}
				}
			}
		}
	}
}

void BFSTraverse(ALGraph AG, void(*visit)(double v)) {
	V = visit;
	QQueue Q; double w;
	for (int i = 0; i < AG.vexnum; i++) visited[i] = false;
	InitQueue(&Q);
	for (int i = 0; i < AG.vexnum; i++)
	{
		if (!visited[i]) {
			V(AG.vertices[i].data);
			visited[i] = true;
			EnQueue(&Q, AG.vertices[i].data); 
			while (!QueueIsEmpty(Q)) {
				DeQueue(&Q, &w);
				ArcNode* an = AG.vertices[LOC(AG, w)].firstarc;
				while (an!= NULL) {
					if(!visited[an->adjvex]){
						V(AG.vertices[an->adjvex].data);
						visited[an->adjvex] = true;	
						EnQueue(&Q, AG.vertices[an->adjvex].data);
					}
					an = an->nextarc;
				}
			}
		}
	}
}

void DFS(ALGraph AG, double a) {
	V(a);
	visited[LOC(AG, a)] = true;
	bool isdone = true;
	for (int i = 0; i < AG.vexnum; i++) {
		if (visited[i]) isdone = false;
	}
	if (isdone) return;
	ArcNode* an = AG.vertices[LOC(AG, a)].firstarc;
	while(an!=NULL) {
		if (!visited[an->adjvex]) {
			DFS(AG, AG.vertices[an->adjvex].data);
		}
		//如果这个该节点的一个相邻节点被访问过，那么就找另一个相邻的节点
		else {
			an = an->nextarc;
			//如果这个节点不为空，且没有访问过，那么DFS它
			if (an&& !visited[an->adjvex])	DFS(AG, AG.vertices[an->adjvex].data);		
		}
	}
}

void DFSTraverse(ALGraph AG, void(*visit)(double v)) {
	V = visit;
	for (int i = 0; i < AG.vexnum; i++) visited[i] = false;
	for (int j = 0; j < AG.vexnum; j++) {
		if (!visited[j]) {
			DFS(AG, AG.vertices[j].data);
		}
	}
}



/*
3 2
1 2 3
1 2 44
1 3 66
*/
/*
4 6
7 4 6 5
6 5 11
5 6 33
7 5 88
7 4 99
4 7 10
6 4 58
0 0 0
*/

/*
10 13
7 5 4 6 8 1 9 2 3 0
7 5 11
5 6 12
6 5 13
6 9 14
9 6 15
9 1 16
6 4 17
4 8 18
4 7 19
7 4 20
8 2 21
2 3 22
3 0 23
0 0 0
*/

/*
3 2
1 2 3
1 2
1 3
0 0
0 0
0 0
*/

/*
4 4
1 2 3 4
1 2
2 1
1 3
3 4
2 4
0 0
0 0
0 0
*/

/*
10 12
7 5 4 6 8 9 2 1 3 0
7 5 10
7 4 11
4 7 12
5 6 13
6 5 14
9 6 15
6 9 16
9 1 17
4 8 18
8 2 19
2 3 20
1 0 21
0 1 22
3 0 23
0 0 0
*/
int main() {
	MGraph G;
	ALGraph AG;
	CreateDN(&AG);
	//CreateUDN(&G);
	//CreateDN(&G);
	//DFSTraverse(G, Print);
	//cout << endl;
	//BFSTraverse(AG, Print);
	DFSTraverse(AG, Print);
	system("pause");
}
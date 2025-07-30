#pragma once
#ifndef ADJACENCY__LIST__GRAPH__H
#define ADJACENCY__LIST__GRAPH__H

// = = = = = 图的邻接表存储表示 = = = = = 
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define FEASIBLE -1
#define OVERFLOW -2
typedef int Status;

// 最大顶点个数
#define MAX_VERTEX_NUM 50
// 顶点元素类型
typedef char VertexType[4];
// 弧相关信息类型
typedef char InfoType;
// 图的种类标识
typedef enum { DG, DN, UDG, UDN } GraphKind;
// 弧的结点类型
typedef struct ArcNode {
    int adjvex; // 该弧所指向的顶点的位置（弧头位置）
    struct ArcNode *nextArc; // 指向下一条弧的指针
    InfoType *info; // 该弧相关信息的指针
} ArcNode;
// 顶点的结点类型
typedef struct {
    VertexType data; // 顶点信息
    ArcNode *firstArc; // 指向第一条依附该顶点的弧的指针
} VertexNode, AdjList[MAX_VERTEX_NUM];
// 图的类型
typedef struct {
    AdjList vertices; // 图的顶点向量
    int vexnum, arcnum; // 图的当前顶点数和弧数
    GraphKind kind; // 图的种类
} ALGraph;

// = = = = = 基本操作的函数原型说明 = = = = = 
// 创建图
Status createGraph(ALGraph *g);

// 构建有向图
Status createDG(ALGraph *g);

// 构建有向网
Status createDN(ALGraph *g);

// 构建无向图
Status createUDG(ALGraph *g);

// 构建无向网
Status createUDN(ALGraph *g);

// 顶点位置
int locateVertex(ALGraph g, VertexType v);

// 输出图的邻接表存储结构
Status displayGraph(ALGraph g);

// 销毁图
Status destroyGraph(ALGraph *g);


#endif // ADJACENCY__LIST__GRAPH__H

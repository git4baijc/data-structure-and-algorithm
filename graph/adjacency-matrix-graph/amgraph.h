#pragma once
#ifndef ADJACENCY__MATRIX__GRAPH__H
#define ADJACENCY__MATRIX__GRAPH__H

#include <limits.h>

// = = = = = 图的邻接矩阵（数组表示法）存储表示 = = = = = 
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define FEASIBLE -1
#define OVERFLOW -2
typedef int Status;

// 一个无限大的值
#define INFINITY INT_MAX
// 最大顶点个数
#define MAX_VERTEX_NUM 50
// 顶点类型
typedef char VertexType[4];
// 顶点关系类型
typedef int VRType;
// 弧相关信息的类型
typedef char InfoType;
// 图的类型：有向图、有向网、无向图和无向网
typedef enum { DG, DN, UG, UN } GraphKind;
// 弧的类型
typedef struct {
    /*对于无权图，用1表示相邻，0表示不相邻；对于带权图，存储权值*/
    VRType adj;
    /*与弧或边的相关信息*/
    InfoType *info;
} ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
// 图的类型
typedef struct {
    /*顶点向量*/
    VertexType vexs[MAX_VERTEX_NUM];
    /*邻接矩阵*/
    AdjMatrix arcs;
    /*图的当前顶点数和弧数*/
    int vexnum, arcnum;
    /*图的种类标识*/
    GraphKind kind;
} AMGraph;

// = = = = = 基本操作的函数原型说明 = = = = = 
// 创建图
Status createGraph(AMGraph *g);

// 顶点位置
int locateVertex(AMGraph g, VertexType v);

// 输出图的顶点和弧
Status displayGraph(AMGraph g);

// 销毁图
Status destroyGraph(AMGraph *g);

#endif // ADJACENCY__MATRIX__GRAPH__H


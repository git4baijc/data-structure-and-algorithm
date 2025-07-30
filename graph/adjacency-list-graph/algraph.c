#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "algraph.h"

// = = = = = 基本操作的函数描述 = = = = = 
// 创建图，采用邻接表存储结构
Status createGraph(ALGraph *g) {
    printf("请输入图的种类标识（0表示有向图，1表示有向网，2表示无向图，3表示无向网）：\n");
    scanf("%d", &(g -> kind));
    switch(g -> kind) {
	case DG: return createDG(g); // 构造有向图
	case DN: return createDN(g); // 构造有向网
	case UDG: return createUDG(g); // 构造无向图
	case UDN: return createUDN(g); // 构造无向网
	default : return ERROR;
    }
}

// 构造有向图
Status createDG(ALGraph *g) {
    return OK;
}

// 构造有向网
Status createDN(ALGraph *g) {
    return OK;
}

// 构造无向图
Status createUDG(ALGraph *g) {
    int i, j, k;
    VertexType v, w;
    ArcNode *p;
    printf("请输入图的顶点数，边数（逗号分隔）：\n");
    scanf("%d,%d", &(*g).vexnum, &(*g).arcnum);
    printf("请输入%d个顶点的值：\n", g -> vexnum);
    /*将顶点存储在头结点中*/
    for(i = 0; i < g -> vexnum; i++) {
	scanf("%s", g -> vertices[i].data);
	g -> vertices[i].firstArc = NULL; // 将弧的信息置空
    }

    printf("请输入弧尾和弧头（以空格作为间隔）：\n");
    for(k = 0; k < g -> arcnum; k++) {
	scanf("%s%s", v, w);
	i = locateVertex(*g, v);
	j = locateVertex(*g, w);

	/*以j为入边，以i为出边创建邻接表*/
	p = (ArcNode *)malloc(sizeof(ArcNode));
	p -> adjvex = j;
	p -> info = NULL;
	p -> nextArc = g -> vertices[i].firstArc;
	g -> vertices[i].firstArc = p;
    }


    return OK;
}

// 构造无向网
Status createUDN(ALGraph *g) {
    return OK;
}

// 顶点位置
int locateVertex(ALGraph g, VertexType v) {
    int i;
    for(i = 0; i < g.vexnum; i++) {
	if(strcmp(g.vertices[i].data, v) == 0) {
	    return i;
	}
    }
    return -1;
}

// 输出图的邻接表存储结构
Status displayGraph(ALGraph g) {
    int i;
    ArcNode *p;
    printf("%d个顶点：\n", g.vexnum);
    for(i = 0; i < g.vexnum; i++) {
	printf("%s ", g.vertices[i].data);
    }
    printf("\n%d条边：\n", 2 * g.arcnum);
    for(i = 0; i < g.vexnum; i++) {
	p = g.vertices[i].firstArc;
	while(p) {
	    printf("%s-->%s ", g.vertices[i].data, g.vertices[p -> adjvex].data);
	    p = p -> nextArc;
	}
	printf("\n");
    }

    return OK;
}

// 销毁图
Status destroyGraph(ALGraph *g) {
    int i;
    ArcNode *p, *q;
    /*释放图中的边表结点*/
    for(i = 0; i < g -> vexnum; i++) {
	p = g -> vertices[i].firstArc;
	while(p) {
	    q = p -> nextArc;
	    free(p);
	    p = q;
	}
    }
    g -> vexnum = 0;
    g -> arcnum = 0;
    return OK;
}


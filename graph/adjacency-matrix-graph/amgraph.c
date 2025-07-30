#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "amgraph.h"

// = = = = = 基本操作的算法描述 = = = = = 
// 采用邻接矩阵存储表示法创建有向网
Status createGraph(AMGraph *g) {
    int i, j, k, weight, infoFlag, len;
    char s[MAX_VERTEX_NUM];
    VertexType v, w;
    printf("请输入有向网g的顶点数、弧数、弧的信息（是：1，否：0）：");
    scanf("%d,%d,%d", &(g -> vexnum), &(g -> arcnum), &infoFlag);
    printf("请输入%d个顶点的值（小于%d个字符）：\n", g -> vexnum, MAX_VERTEX_NUM);
    /*创建一个数组，用于保存网的各个顶点*/
    for(i = 0; i < g -> vexnum; i++) {
        scanf("%s", g -> vexs[i]);
    }
    /*初始化邻接矩阵*/
    for(i = 0; i < g -> vexnum; i++) {
        for(j = 0; j < g -> vexnum; j++) {
	    g -> arcs[i][j].adj = INFINITY;
	    g -> arcs[i][j].info = NULL;
	}
    }

    printf("请输入%d条弧的弧尾 弧头 权值（以空格作为间隔）：\n", g -> arcnum);
    for(k = 0; k < g -> arcnum; k++) {
	/*输入两个顶点和弧的权值*/
	scanf("%s%s%d", v, w, &weight);
	i = locateVertex(*g, v);
	j = locateVertex(*g, w);
	g -> arcs[i][j].adj = weight;
	/*如果弧包含其他信息*/
	if(infoFlag) {
	    printf("请输入弧的相关信息：");
	    fgets(s, sizeof(s), stdin);
	    len = strlen(s);
	    if(len) {
		g -> arcs[i][j].info = (char *)malloc((len + 1) * sizeof(char));
		strcpy(g -> arcs[i][j].info, s);
	    }
	}
    }
    g -> kind = DN;

    return OK;
}

// 顶点位置
int locateVertex(AMGraph g, VertexType v) {
    int i;
    for(i = 0; i < g.vexnum; i++) {
	if(strcmp(g.vexs[i], v) == 0) {
	    return i;
	}
    }
    
    return -1;
}

// 输出图的顶点和弧
Status displayGraph(AMGraph g) {
    int i, j;
    printf("有向网具有%d个顶点%d条弧，顶点依次是：", g.vexnum, g.arcnum);
    for(i = 0; i < g.vexnum; i++) {
	printf("%s ", g.vexs[i]);
    }

    printf("\n有向网g的：\n");
    printf("序号i=");
    for(i = 0; i < g.vexnum; i++) {
        printf("%4d", i);
    }
    printf("\n");
    for(i = 0; i < g.vexnum; i++) {
	printf("%6d", i);
	for(j = 0; j < g.vexnum; j++) {
	    if(g.arcs[i][j].adj < INFINITY) {
		printf("%4d", g.arcs[i][j].adj);
	    } else {
		printf("%4s", "∞");
	    }
	}
	printf("\n");
    }

    return OK;
}

// 销毁图
Status destroyGraph(AMGraph *g) {
    int i, j;
    for(i = 0; i < g -> vexnum; i++) {
	for(j = 0; j < g -> vexnum; j++) {
	    if(g -> arcs[i][j].adj != INFINITY) {
		if(g -> arcs[i][j].info != NULL) {
		    free(g -> arcs[i][j].info);
		    g -> arcs[i][j].info = NULL;
		}
	    }
	}
    }
    g -> vexnum = 0;
    g -> arcnum = 0;

    return OK;
}



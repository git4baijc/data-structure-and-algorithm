#include <stdio.h>
#include "amgraph.h"

/**
 * 图的邻接矩阵存储表示测试案例：
 * 
 * 利用邻接矩阵表示法创建一个有向网
 */
int main(int argc, const char *argv[]) {
    AMGraph g;
    printf("创建一个网g:\n");
    createGraph(&g);
    printf("输出网的顶点和弧：\n");
    displayGraph(g);
    printf("销毁网：\n");
    destroyGraph(&g);

    return 0;
}


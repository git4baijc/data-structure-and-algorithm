#include <stdio.h>
#include "amgraph.h"

int main(int argc, const char argv[]) {
    AMGraph g;
    printf("创建一个网g:\n");
    createGraph(&g);
    printf("输出网的顶点和弧：\n");
    displayGraph(g);
    printf("销毁网：\n");
    destroyGraph(&g);

    return 0;
}


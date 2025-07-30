#include <stdio.h>
#include "algraph.h"

int main(int argc, const char *argv[]) {
    
    ALGraph g;
    printf("采用邻接表创建无向图g：\n");
    createGraph(&g);
    printf("输出无向图g：");
    displayGraph(g);
    destroyGraph(&g);

    return 0;
}

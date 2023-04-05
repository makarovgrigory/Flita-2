#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *inputfile;
    FILE *outputfile;
    int roads, vertices;
    inputfile = fopen("d:/2022-2023/C/Flita/HW2/input.txt", "r");
    outputfile = fopen("d:/2022-2023/C/Flita/HW2/graph.dot", "w");
    fprintf(outputfile, "graph{\n");
    while (fscanf(inputfile, "%d %d", &vertices, &roads)!=EOF) {
        fprintf(outputfile,"%d -- %d\n", vertices, roads);
    }

    fprintf(outputfile, "}\n");
    fclose(inputfile);
    fclose(outputfile);
    system("dot -Tpng -O d:/2022-2023/C/Flita/HW2/graph.dot");
    system("d:/2022-2023/C/Flita/HW2/graph.dot.png");

    return 0;
}
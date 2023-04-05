#include <stdio.h>

int main() {
    int numberofvertices, i, j;
    printf("Enter the number of vertices of the graph:");
    scanf("%d", &numberofvertices);
    int adjancencymatrix[numberofvertices][numberofvertices];

    for (i = numberofvertices;i > 0; i--){
        printf("Enter the number of edges from vertex %d \n", (i - 1));
        for (j = 0; j < i; j++){
            printf("to vertex %d:", j);
            scanf("%d", &adjancencymatrix[i][j]);
        }
    }
    printf("Adjancency matrix:");
    for (i = numberofvertices;i > 0; i--){
        for (j = 0; j < numberofvertices; j++){
            printf("%d", adjancencymatrix[i][j]);
        }
        printf("\n");
    }
}

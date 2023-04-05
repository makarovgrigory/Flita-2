#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
    FILE *inputfile;
    FILE *outputfile;
    int roads, count_2 = 0, verticies, count = 0, back_roads = 0, i, j, num_r = 1, num_v = 1, num_all = 0, element = 0;
    char first_string[100];
    inputfile = fopen("d:/2022-2023/C/Flita/HW2_alt/input.txt", "r");
    outputfile = fopen("d:/2022-2023/C/Flita/HW2_alt/graph.dot", "w");

    fgets(first_string, 100, inputfile);
    num_v = strlen(first_string);
    while(fscanf(inputfile, "%d", &roads) != EOF){
        num_all++;
    }
    num_r = (num_all + num_v / 2) / (num_v / 2);
    fclose(inputfile);


    inputfile = fopen("d:/2022-2023/C/Flita/HW2_alt/input.txt", "r");
    int matrix_of_incendence[num_r][num_v / 2];
    for(i = 0; i < num_r; i++){
        for (j = 0; j < (num_v / 2); j++) {
            fscanf(inputfile, "%d", &matrix_of_incendence[i][j]);
        }
    }
    fprintf(outputfile, "graph{\n");
    for(j = 0; j < (num_v / 2); j++){
        for (i = 0; i < num_r; i++){
            element = matrix_of_incendence[i][j];
            if (matrix_of_incendence[i][j] == 1 && count == 0) {
                fprintf(outputfile, "%d -- ", i);
                count = 1;
                back_roads = i;
            }
            else if(matrix_of_incendence[i][j] == 1 && count == 1){
                fprintf(outputfile,"%d\n", i);
                count = 0;
            }
        }
        if (count == 1)
            fprintf(outputfile, "%d\n", back_roads);
        back_roads = 0;
        count = 0;
    }
    for(i = 0; i < num_r; i++){
        count_2 = 0;
        for (j = 0; j < (num_v / 2); j++) {
            element = matrix_of_incendence[i][j];
            if (element == 1)
                count_2++;
        }
         if(count_2 == 0)
             fprintf(outputfile, "%d\n", i);
    }
    fprintf(outputfile, "}\n");
    fclose(inputfile);
    fclose(outputfile);
    system("dot -Tpng -O d:/2022-2023/C/Flita/HW2_alt/graph.dot");
    system("d:/2022-2023/C/Flita/HW2_alt/graph.dot.png");

    return 0;
}
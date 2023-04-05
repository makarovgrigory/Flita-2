#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
    FILE *inputfile;
    FILE *outputfile;
    int numb_1 = -1, count_3, numb_2 = -1, count_new_ver = 0, count_2 = 0, count = 0;
    int number_of_unique_path, back_roads = 0, i, j, num_r = 1, num_v = 1, num_all = 0, element = 0;
    char first_string[100];
    inputfile = fopen("d:/2022-2023/C/Flita/HW3/input.txt", "r");
    outputfile = fopen("d:/2022-2023/C/Flita/HW3/graph.dot", "w");

    fgets(first_string, 100, inputfile);
    num_v = strlen(first_string);
    while(fscanf(inputfile, "%d", &element) != EOF){
        num_all++;
    }
    num_r = (num_all + num_v / 2) / (num_v / 2);
    fclose(inputfile);


    inputfile = fopen("d:/2022-2023/C/Flita/HW3/input.txt", "r");
    int matrix_of_incendence[num_r][num_v / 2];
    for(i = 0; i < num_r; i++){
        for (j = 0; j < (num_v / 2); j++) {
            fscanf(inputfile, "%d", &matrix_of_incendence[i][j]);
        }
    }
    fprintf(outputfile, "graph{\n");
    for(j = 0; j < (num_v / 2); j++){
        count_new_ver = 0;
        for (i = 0; i < num_r; i++) {
            element = matrix_of_incendence[i][j];
            if (matrix_of_incendence[i][j] == 1 && count == 0) {
                fprintf(outputfile, "%d -- ", i);
                count = 1;
                back_roads = i;
                if (numb_1 == i) {
                    count_new_ver++;
                }
                numb_1 = i;
            }
            else if (matrix_of_incendence[i][j] == 1 && count == 1) {
                fprintf(outputfile, "%d\n", i);
                count = 0;
                if (numb_2 == i) {
                    count_new_ver++;
                }
                numb_2 = i;
            }
        }

        if(count_new_ver == 2)
            count_2++;
        if (count == 1) {
            fprintf(outputfile, "%d\n", back_roads);
            count_2++;
        }
        back_roads = 0;
        count = 0;
    }

    for(i = 0; i < num_r; i++){
        count_3 = 0;
        for (j = 0; j < (num_v / 2); j++) {
            element = matrix_of_incendence[i][j];
            if (element == 1)
                count_3++;
        }
        if(count_3 == 0)
            fprintf(outputfile, "%d\n", i);
    }

    number_of_unique_path = num_v / 2 - count_2;
    if(number_of_unique_path < num_r)
        printf("The graph is not connected");
    else if(number_of_unique_path > (num_r - 2) * (num_r - 1) / 2)
        printf("The graph is connected");
    else
        printf("It is impossible to determine the connectivity of the graph");

    fprintf(outputfile, "}\n");
    fclose(inputfile);
    fclose(outputfile);
    system("dot -Tpng -O d:/2022-2023/C/Flita/HW3/graph.dot");
    system("d:/2022-2023/C/Flita/HW3/graph.dot.png");

    return 0;
}
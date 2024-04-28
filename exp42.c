#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char operator;
    char arg1[10];
    char arg2[10];
    char result[10];
} Quadruple;

Quadruple* generateQuadruples(char* expression) {
    Quadruple* quadruples = malloc(sizeof(Quadruple) * 100); // Assuming a maximum of 100 quadruples
    int quadrupleCount = 0;

    char* token = strtok(expression, "+*/=");

    char tempResult[10] = "";
    char tempArg1[10] = "";
    char tempArg2[10] = "";

    while (token != NULL) {
        if (strchr("+-*/=", token[0])) {
            if (strlen(tempArg1) > 0 && strlen(tempArg2) > 0) {
                sprintf(quadruples[quadrupleCount].result, "t%d", quadrupleCount + 1);
                strcpy(quadruples[quadrupleCount].arg1, tempArg1);
                strcpy(quadruples[quadrupleCount].arg2, tempArg2);
                quadruples[quadrupleCount].operator = *tempResult;
                quadrupleCount++;

                strcpy(tempArg1, quadruples[quadrupleCount - 1].result);
                strcpy(tempArg2, "");
            }
            strcpy(tempResult, token);
        } else {
            if (strlen(tempArg1) == 0) {
                strcpy(tempArg1, token);
            } else {
                strcpy(tempArg2, token);
            }
        }

        token = strtok(NULL, "+*/=");
    }

    if (strlen(tempArg1) > 0 && strlen(tempArg2) > 0) {
        sprintf(quadruples[quadrupleCount].result, "t%d", quadrupleCount + 1);
        strcpy(quadruples[quadrupleCount].arg1, tempArg1);
        strcpy(quadruples[quadrupleCount].arg2, tempArg2);
        quadruples[quadrupleCount].operator = *tempResult;
        quadrupleCount++;
    }

    return quadruples;
}

void printQuadruples(Quadruple* quadruples, int count) {
    for (int i = 0; i < count; i++) {
        printf("(%c, %s, %s, %s)\n", quadruples[i].operator, quadruples[i].arg1, quadruples[i].arg2, quadruples[i].result);
    }
}

int main() {
    char expression[] = "x = e+c*r+40";
    Quadruple* quadruples = generateQuadruples(expression);
    
    printQuadruples(quadruples, 3); // Assuming the expression generates 3 quadruples
    
    free(quadruples);

    return 0;
}

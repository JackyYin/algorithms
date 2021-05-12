#include "stdlib.h"
#include <string.h>

typedef struct {
   int rowSize;
   int **cumuRows;
} NumMatrix;


NumMatrix* numMatrixCreate(int** matrix, int matrixSize, int* matrixColSize) {
    NumMatrix *numMatrix = malloc(sizeof(NumMatrix));
    memset(numMatrix, 0, sizeof(NumMatrix));

    numMatrix->rowSize = matrixSize;
    numMatrix->cumuRows = malloc(sizeof(int *) * matrixSize);

    for (int i = 0; i < matrixSize; i++) {
        int *cumuRow = malloc(sizeof(int) * (matrixColSize[i] + 1));
        cumuRow[0] = 0;
        int colSum = 0;
        for (int j = 0; j < matrixColSize[i]; j++) {
            colSum += matrix[i][j];
            cumuRow[j + 1] = colSum;
        }
        numMatrix->cumuRows[i] = cumuRow;
    }

    return numMatrix;
}

int numMatrixSumRegion(NumMatrix* obj, int row1, int col1, int row2, int col2) {
    int sum = 0;
    for (int r = row1; r <= row2; r++) {
        sum += obj->cumuRows[r][col2 + 1] - obj->cumuRows[r][col1];
    }
    return sum;
}

void numMatrixFree(NumMatrix* obj) {
    for (int i = 0; i < obj->rowSize; i++) {
        free(obj->cumuRows[i]);
    }
    free(obj->cumuRows);
    free(obj);
}

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int i;
    int j;
} MatrixPosition;

typedef struct {
    MatrixPosition* data;
    int size;
} ArrayWithInfo;

ArrayWithInfo getNeighbours(const int row, const int col, const int m, const int n) {
    MatrixPosition neighbours[4]; // In the best-case scenario, an element will have four neighbours.
    int totalNeighbours = 0;

    MatrixPosition position;

    // Check and collect neighbours
    if (row - 1 >= 0) {
        position.i = row - 1;
        position.j = col;

        neighbours[totalNeighbours] = position;
        totalNeighbours += 1;
    }
    if (row + 1 < m) {
        position.i = row + 1;
        position.j = col;

        neighbours[totalNeighbours] = position;
        totalNeighbours += 1;
    }
    if (col - 1 >= 0) {
        position.i = row;
        position.j = col - 1;

        neighbours[totalNeighbours] = position;
        totalNeighbours += 1;
    }
    if (col + 1 < n) {
        position.i = row;
        position.j = col + 1;

        neighbours[totalNeighbours] = position;
        totalNeighbours += 1;
    }

    // Allocate memory for final neighbours
    MatrixPosition* finalNeighbours = malloc(totalNeighbours * sizeof(MatrixPosition));
    if (finalNeighbours == NULL) {
        // Handle memory allocation failure
        ArrayWithInfo result = {NULL, 0};
        return result;
    }

    for (int i = 0; i < totalNeighbours; i++) {
        finalNeighbours[i] = neighbours[i];
    }

    ArrayWithInfo result;
    result.size = totalNeighbours;
    result.data = &finalNeighbours[0];
    return result;
}

ArrayWithInfo filterNeighbours(int m, int n, const int matrix[m][n], const int i, const int j, const ArrayWithInfo neighbours) {
    int totalNeighbours = neighbours.size;
    printf("totalNeighbours: %d\n", totalNeighbours);

    int currentMatrixItem = matrix[i][j];
    printf("currentMatrixItem: %d\n", currentMatrixItem);

    MatrixPosition filteredNeighbours[4]; // In the best-case scenario, an element will have four neighbours.
    int totalFilteredNeighbours = 0;

    for (int i = 0; i < totalNeighbours; i++) {
        MatrixPosition matrixPosition = neighbours.data[i];
        //printf("(%d, %d) -> Value: %d\n", matrixPosition.i, matrixPosition.j, matrix[matrixPosition.i][matrixPosition.j]);

        if (matrix[matrixPosition.i][matrixPosition.j] > currentMatrixItem) {
            filteredNeighbours[totalFilteredNeighbours++] = matrixPosition;
        }
    }

    // Allocate memory for final neighbours
    MatrixPosition* finalFilteredNeighbours = malloc(totalFilteredNeighbours * sizeof(MatrixPosition));
    if (finalFilteredNeighbours == NULL) {
        // Handle memory allocation failure
        ArrayWithInfo result = {NULL, 0};
        return result;
    }

    for (int i = 0; i < totalFilteredNeighbours; i++) {
        finalFilteredNeighbours[i] = filteredNeighbours[i];
    }

    ArrayWithInfo result;
    result.size = totalFilteredNeighbours;
    result.data = &finalFilteredNeighbours[0];
    return result;
}

int findPath(int m, int n, const int matrix[m][n], const int i, const int j) {
    const ArrayWithInfo neighbours = getNeighbours(i, j, m, n);
    const ArrayWithInfo filteredNeighbours = filterNeighbours(m, n, matrix, i, j, neighbours);

    if (filteredNeighbours.size == 0) {
        return 0;
    }

    int maxLength = 0;
    int length = 0;

    for (int k = 0; k < filteredNeighbours.size; k++) {
        MatrixPosition matrixPosition = filteredNeighbours.data[k];
        printf("(%d, %d) -> Value: %d\n", matrixPosition.i, matrixPosition.j, matrix[matrixPosition.i][matrixPosition.j]);

        length = 1 + findPath(m, n, matrix, matrixPosition.i, matrixPosition.j);
        if (length > maxLength) {
            maxLength = length;
        }
    }

    return maxLength;
}

void solveForMatrix(int m, int n, const int matrix[m][n], const numRows, const numCols)
{
    int maxLength = 0;
    int length = 0;

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            printf("matrix[%d][%d] = %d\n", i, j, matrix[i][j]);

            length = 1 + findPath(numRows, numCols, matrix, i, j);
            printf("length: %d\n", length);

            if (length > maxLength) {
                maxLength = length;
            }
        }
    }

    printf("maxLength: %d\n", maxLength);
    printf("\n");
}

int main(int argc, char** argv) {
    const int matrix1[3][3] = {{9, 9, 4}, {6, 6, 8}, {2, 2, 1}};
    const int numRows1 = sizeof(matrix1) / sizeof(matrix1[0]);
    const int numCols1 = sizeof(matrix1[0]) / sizeof(matrix1[0][0]);
    solveForMatrix(3, 3, matrix1, numRows1, numCols1);

    const int matrix2[3][3] = {{3, 4, 5}, {3, 2, 6}, {2, 2, 1}};
    const int numRows2 = sizeof(matrix2) / sizeof(matrix2[0]);
    const int numCols2 = sizeof(matrix2[0]) / sizeof(matrix2[0][0]);
    solveForMatrix(3, 3, matrix2, numRows2, numCols2);

    const int matrix3[1][1] = {{1}};
    const int numRows3 = sizeof(matrix3) / sizeof(matrix3[0]);
    const int numCols3 = sizeof(matrix3[0]) / sizeof(matrix3[0][0]);
    solveForMatrix(3, 3, matrix3, numRows3, numCols3);

    return 0;
}

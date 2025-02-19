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

int main(int argc, char** argv) {
    const int matrix[3][3] = {{3, 4, 5}, {3, 2, 6}, {2, 2, 1}};

    //const int m = sizeof(matrix);    // 3 * 3 ints (each int is sizeof 4) -> 3 * 3 * 4 = 36
    //const int n = sizeof(matrix[0]); // 3 ints (each int is sizeof 4) -> 3 * 4 = 12
    //printf("m = %d\n", m);
    //printf("n = %d\n", n);

    const int numRows = sizeof(matrix) / sizeof(matrix[0]);
    const int numCols = sizeof(matrix[0]) / sizeof(matrix[0][0]);
    //printf("numRows = %d\n", numRows);
    //printf("numCols = %d\n", numCols);

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            printf("matrix[%d][%d] = %d\n", i, j, matrix[i][j]);

            const ArrayWithInfo neighbours = getNeighbours(i, j, numRows, numCols);
            printf("Neighbours of (%d, %d):\n", i, j);

            for (int k = 0; k < neighbours.size; k++) {
                MatrixPosition matrixPosition = neighbours.data[k];
                printf("(%d, %d) -> Value: %d\n", matrixPosition.i, matrixPosition.j, matrix[matrixPosition.i][matrixPosition.j]);
            }

            const ArrayWithInfo filteredNeighbours = filterNeighbours(numRows, numCols, matrix, i, j, neighbours);
            printf("Filtered neighbours of (%d, %d):\n", i, j);

            for (int k = 0; k < filteredNeighbours.size; k++) {
                MatrixPosition matrixPosition = filteredNeighbours.data[k];
                printf("(%d, %d) -> Value: %d\n", matrixPosition.i, matrixPosition.j, matrix[matrixPosition.i][matrixPosition.j]);
            }

            free(neighbours.data); // Free allocated memory
            free(filteredNeighbours.data); // Free allocated memory

            printf("\n");
        }
    }

    return 0;
}

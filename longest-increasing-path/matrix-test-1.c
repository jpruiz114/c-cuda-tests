#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* data;
    int size;
} ArrayWithInfo;

ArrayWithInfo getNeighbours(const int row, const int col, const int m, const int n) {
    int neighbours[4]; // In the best-case scenario, an element will have four neighbours.
    int totalNeighbours = 0;

    /*for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }*/

    // Check and collect neighbors
    if (row - 1 >= 0) {
        neighbours[totalNeighbours] = matrix[row - 1][col];
        totalNeighbours += 1;
    }
    if (row + 1 < m) {
        neighbours[totalNeighbours] = matrix[row + 1][col];
        totalNeighbours += 1;
    }
    if (col - 1 >= 0) {
        neighbours[totalNeighbours] = matrix[row][col - 1];
        totalNeighbours += 1;
    }
    if (col + 1 < n) {
        neighbours[totalNeighbours] = matrix[row][col + 1];
        totalNeighbours += 1;
    }

    //printf("totalNeighbours = %d\n", totalNeighbours);

    // Allocate memory for final neighbors
    int* finalNeighbours = (int*)malloc(totalNeighbours * sizeof(int));
    if (finalNeighbours == NULL) {
        // Handle memory allocation failure
        ArrayWithInfo result = {NULL, 0};
        return result;
    }

    for (int i = 0; i < totalNeighbours; i++) {
        finalNeighbours[i] = neighbours[i];
    }

    /*for (int i = 0; i < totalNeighbours; i++) {
        printf("finalNeighbours[%d] = %d\n", i, finalNeighbours[i]);
    }*/

    //int *resultPointer = &finalNeighbours[0];
    //printf("resultPointer = %p\n", resultPointer);

    ArrayWithInfo result;
    result.size = totalNeighbours;
    result.data = &finalNeighbours[0];
    return result;
}

void traverseArray(const int *arrayPointer, const int size) {
    printf("arrayPointer = %p\n", arrayPointer);
    for (int i = 0; i < size; i++) {
        printf("%d ", arrayPointer[i]);
    }
    printf("\n");
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

            const ArrayWithInfo neighbors = getNeighbours(i, j, numRows, numCols);
            printf("Neighbors of (%d, %d):\n", i, j);
            traverseArray(neighbors.data, neighbors.size);
            free(neighbors.data); // Free allocated memory

            printf("\n");
        }
    }

    return 0;
}

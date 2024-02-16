#include <iostream>
using namespace std;
const int ROWS = 3;
const int COLS = 3;

void inputMatrix(int matrix[ROWS][COLS], const char* matrixName) {
    cout << "Enter elements for matrix " << matrixName << ":\n";
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cout << matrixName << "[" << i + 1 << "][" << j + 1 << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void multiplyMatrices(const int mat1[ROWS][COLS], const int mat2[ROWS][COLS], int result[ROWS][COLS]) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < COLS; ++k) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void displayMatrix(const int matrix[ROWS][COLS], const char* matrixName) {
    cout << matrixName << ":\n";
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}

int main() {
    int matrix1[ROWS][COLS];
    int matrix2[ROWS][COLS];
    int resultMatrix[ROWS][COLS];

    inputMatrix(matrix1, "Matrix1");
    inputMatrix(matrix2, "Matrix2");

    multiplyMatrices(matrix1, matrix2, resultMatrix);

    displayMatrix(matrix1, "Matrix1");
    displayMatrix(matrix2, "Matrix2");
    displayMatrix(resultMatrix, "Result Matrix");

    return 0;
}


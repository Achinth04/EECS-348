
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;

// Functional prototypes
void printMatrix(const std::vector<std::vector<int>>& matrix);
std::vector<std::vector<int>> matrixSum(const std::vector<std::vector<int>>& matrixA, const std::vector<std::vector<int>>& matrixB);
std::vector<std::vector<int>> matrixProduct(const std::vector<std::vector<int>>& matrixA, const std::vector<std::vector<int>>& matrixB);
std::vector<std::vector<int>> matrixDifference(const std::vector<std::vector<int>>& matrixA, const std::vector<std::vector<int>>& matrixB);

int main() {
    const int MAX_SIZE = 100;
    int size = 0;
    std::vector<std::vector<int>> matrixA;
    std::vector<std::vector<int>> matrixB;

    // Print header and get file name from the user
    std::string fileName;
    std::cout << "\nLab #6: Matrix manipulation\n\nEnter the name of the input file: ";
    std::cin >> fileName;

    // Open file
    std::ifstream inFile(fileName);

    try {
        if (inFile.is_open()) {
            inFile >> size;
            if (size > MAX_SIZE) {
                // Size of matrices must be less than or equal to 100
                inFile.close();
                throw std::runtime_error("Size must be less than or equal to 100");
            }

            matrixA.resize(size, std::vector<int>(size));
            matrixB.resize(size, std::vector<int>(size));

            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    inFile >> matrixA[i][j];
                }
            }

            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    inFile >> matrixB[i][j];
                }
            }
        } else {
            // File name is invalid
            throw std::runtime_error("Invalid file name");
        }

        inFile.close();

        // Print matrices
        std::cout << "\nMatrix A:\n";
        printMatrix(matrixA);

        std::cout << "\nMatrix B:\n";
        printMatrix(matrixB);

        // Calculate and print the sum of matrices
        std::cout << "\nMatrix Sum (A + B):\n";
        printMatrix(matrixSum(matrixA, matrixB));

        // Calculate and print the product of matrices
        std::cout << "\nMatrix Product (A * B):\n";
        printMatrix(matrixProduct(matrixA, matrixB));

        // Calculate and print the difference of matrices
        std::cout << "\nMatrix Difference (A - B):\n";
        printMatrix(matrixDifference(matrixA, matrixB));

        return 0;
    } catch (std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    return 1;
}

void printMatrix(const std::vector<std::vector<int>>& matrix) {
    int size = matrix.size();
    int width = 0;

    // Find the maximum width of matrix elements
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int element = matrix[i][j];
            int elementWidth = int(log10(std::abs(element)) + 1);
            if (elementWidth > width) {
                width = elementWidth;
            }
        }
    }

    // Print the matrix
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << std::right << std::setw(width) << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}

std::vector<std::vector<int>> matrixSum(const std::vector<std::vector<int>>& matrixA, const std::vector<std::vector<int>>& matrixB) {
    int size = matrixA.size();
    std::vector<std::vector<int>> result(size, std::vector<int>(size));

    // Compute the sum of corresponding elements of the matrices
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }

    return result;
}

std::vector<std::vector<int>> matrixProduct(const std::vector<std::vector<int>>& matrixA, const std::vector<std::vector<int>>& matrixB) {
    int size = matrixA.size();
    std::vector<std::vector<int>> result(size, std::vector<int>(size, 0));

    // Compute the product of the matrices
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }

    return result;
}

std::vector<std::vector<int>> matrixDifference(const std::vector<std::vector<int>>& matrixA, const std::vector<std::vector<int>>& matrixB) {
    int size = matrixA.size();
    std::vector<std::vector<int>> result(size, std::vector<int>(size));

    // Compute the difference of corresponding elements of the matrices
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }

    return result;
}

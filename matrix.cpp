#include "matrix.hpp"
#include <iostream>
#include <vector>

// Constructor to initialize an N x N matrix with zeroes
Matrix::Matrix(std::size_t N) {
    size = N;
    matrix.resize(N, std::vector<int>(N, 0)); // Initialize matrix with zeros
}

// Constructor to initialize the matrix with a given 2D vector
Matrix::Matrix(std::vector<std::vector<int>> nums) {
    size = nums.size();
    matrix = nums; // Directly initialize the matrix with the provided vector
}

// Matrix addition
Matrix Matrix::operator+(const Matrix &rhs) const {
    Matrix result(size);
    for (std::size_t i = 0; i < size; i++) {
        for (std::size_t j = 0; j < size; j++) {
            result.matrix[i][j] = matrix[i][j] + rhs.matrix[i][j];
        }
    }
    return result;
}

// Matrix multiplication
Matrix Matrix::operator*(const Matrix &rhs) const {
    Matrix result(size);
    for (std::size_t i = 0; i < size; i++) {
        for (std::size_t j = 0; j < size; j++) {
            for (std::size_t k = 0; k < size; k++) {
                result.matrix[i][j] += matrix[i][k] * rhs.matrix[k][j];
            }
        }
    }
    return result;
}

// Set value at position (i, j)
void Matrix::set_value(std::size_t i, std::size_t j, int n) {
    matrix[i][j] = n;
}

// Get value at position (i, j)
int Matrix::get_value(std::size_t i, std::size_t j) const {
    return matrix[i][j];
}

// Get the size of the matrix (number of rows or columns)
int Matrix::get_size() const {
    return size;
}

// Sum of the main diagonal (top-left to bottom-right)
int Matrix::sum_diagonal_major() const {
    int sum = 0;
    for (std::size_t i = 0; i < size; i++) {
        sum += matrix[i][i];  // Diagonal element (i, i)
    }
    return sum;
}

// Sum of the minor diagonal (top-right to bottom-left)
int Matrix::sum_diagonal_minor() const {
    int sum = 0;
    for (std::size_t i = 0; i < size; i++) {
        sum += matrix[i][size - 1 - i];  // Minor diagonal element (i, size-i-1)
    }
    return sum;
}

// Swap two rows (r1 and r2)
void Matrix::swap_rows(std::size_t r1, std::size_t r2) {
    std::swap(matrix[r1], matrix[r2]);
}

// Swap two columns (c1 and c2)
void Matrix::swap_cols(std::size_t c1, std::size_t c2) {
    for (std::size_t i = 0; i < size; i++) {
        std::swap(matrix[i][c1], matrix[i][c2]);
    }
}

// Print the matrix
void Matrix::print_matrix() const {
    for (const auto &row : matrix) {
        for (int num : row) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}

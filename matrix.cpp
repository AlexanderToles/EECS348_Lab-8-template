#include "matrix.hpp"
#include <vector>

// implementation of functions declared in matrix.hpp goes here
// function definitions for a class have their names prefixed with
// the class name and "::"

// e.g. for the constructor:

Matrix::Matrix(size_t N) {
    //initialize empty matrix
    Matrix::size = N;
    Matrix::newMatrix = std::vector<std::vector<int>> (N,std::vector<int> (N,0));
}

Matrix::Matrix(std::vector<std::vector<int>> nums) {
    for(int i = 0; i < Matrix::size; i++){
        for(int j = 0; j < Matrix::size; j++){
            Matrix::newMatrix[i][j] = nums[i][j];
        }
    }
}

Matrix Matrix::operator+(const Matrix &rhs) const{

}
Matrix Matrix::operator*(const Matrix &rhs) const{

}

void Matrix::set_value(std::size_t i, std::size_t j, int n){
}

int Matrix::get_value(std::size_t i, std::size_t j) const{
    return 0;

}

int Matrix::get_size() const{
    return(Matrix::size);
}

int Matrix::sum_diagonal_major() const{
    return 0;
}

int Matrix::sum_diagonal_minor() const{
    return 0;

}

void Matrix::swap_rows(std::size_t r1, std::size_t r2){

}

void Matrix::swap_cols(std::size_t c1, std::size_t c2){

}

// e.g. for a member function:

void Matrix::print_matrix() const {
    // print out the matrix
}
#include <matrix.h>
#include <assert.h>
#include <iostream>
#include <fstream>
#include <string>

Matrix::Matrix(int m, int n){
    this->m = m;
    this->n = n;
    this->arr = new float[m*n]();
}

Matrix::Matrix(const Matrix& other){
    this->m = other.m;
    this->n = other.n;
    this->arr = new float[m*n]();
    for(int i=0; i<m*n; i++){
        this->arr[i] = other.arr[i];
    }
}

Matrix::~Matrix(){
    delete [] this->arr;
}

Matrix* Matrix::MatMul(Matrix* other){
    assert(this->n == other->m);
    int k_max = this->n;
    Matrix* product = new Matrix(this->m, other->n);
    for(int i=0; i<product->m; i++){
        for(int j=0; j<product->n; j++){
            float value = 0;
            for(int k=0; k<k_max; k++){
                value += this->get(i, k) * other->get(k, j);
            }
            product->set(i, j, value);
        }
    }
    return product;
}

void Matrix::set(int i, int j, float value){
    assert(0 <= i && i<m);
    assert(0 <= j && j<n);
    this->arr[i*n + j] = value;
}

float Matrix::get(int i, int j){
    assert(0 <= i && i<m);
    assert(0 <= j && j<n);
    return this->arr[i*n + j];
}

void Matrix::print(){
    for(int i=0; i<this->m; i++){
        for(int j=0; j<this->n; j++){
            std::cout << std::to_string(this->get(i, j)) << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void Matrix::save(char* filename){
    std::ofstream out_file;
    out_file.open(filename);
    for(int i=0; i<this->m; i++){
        for(int j=0; j<this->n; j++){
            out_file << std::to_string(this->get(i, j)) << " ";
        }
        out_file << std::endl;
    }
    out_file << std::endl;
    out_file.close();
}

void Matrix::identity(){
    assert(this->m == this->n);
    for(int i=0; i<this->m; i++){
        for(int j=0; j<this->n; j++){
            if(i == j){
                this->set(i, j, 1);
            }
            else{
                this->set(i, j, 0);
            }
        }
    }
}

void Matrix::transpose(){
    Matrix* original = new Matrix(*this);
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            this->set(i, j, original->get(j, i));
        }
    }
}

void Matrix::set_matrix(Matrix* other){
    for(int i=0; i<m*n; i++){
        this->arr[i] = other->arr[i];
    }
}
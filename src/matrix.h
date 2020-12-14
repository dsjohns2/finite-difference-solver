#pragma once

class Matrix{
    private:
        float* arr;
    public:
        Matrix(int m, int n);
        Matrix(const Matrix& other);
        ~Matrix();
        int m;
        int n;
        Matrix* MatMul(Matrix* other);
        void set(int i, int j, float value);
        float get(int i, int j);
        void print();
        void save(char* filename);
        void identity();
        void transpose();
        void set_matrix(Matrix* other);
};
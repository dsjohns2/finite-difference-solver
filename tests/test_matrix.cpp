#include <matrix.h>
#include <iostream>

int main(){
    Matrix* A = new Matrix(2, 2);
    A->print();
    for(int i=0; i<A->m; i++){
        for(int j=0; j<A->n; j++){
            A->set(i, j, i+j);
        }
    }
    std::cout<<std::endl;
    A->print();
    std::cout<<std::endl;
    Matrix* B = new Matrix(2, 2);
    for(int i=0; i<B->m; i++){
        for(int j=0; j<B->n; j++){
            B->set(i, j, i*j);
        }
    }
    B->print();
    std::cout<<std::endl;
    Matrix* C = A->MatMul(B);
    C->print();
    std::cout<<std::endl;
    Matrix* D = new Matrix(*C);
    D->print();
    std::cout<<std::endl;
    D->set(0, 1, 32);
    D->print();
    std::cout<<std::endl;
    D->transpose();
    D->print();
    std::cout<<std::endl;
    D->identity();
    D->print();
    std::cout<<std::endl;

    return 0;
}
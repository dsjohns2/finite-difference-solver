#include <tri_diag_solver.h>
#include <iostream>
#include <matrix.h>

int main(){
    Matrix* A = new Matrix(6, 6);
    for(int i=0; i<A->m; i++){
        A->set(i, i, 1+i+i);
    }
    for(int i=0; i<A->m-1; i++){
        int j;
        j = i+1;
        A->set(i, j, 1+i+j);
    }
    for(int i=1; i<A->m; i++){
        int j;
        j = i-1;
        A->set(i, j, 1+i+j);
    }
    Matrix* x = new Matrix(6, 1);
    for(int i=0; i<x->m; i++){
        x->set(i, 0, 1+i+i);
    }
    Matrix* b = A->MatMul(x);
    Matrix* Q = new Matrix(6, 6);
    Q->identity();
    TriDiagSolver solver = TriDiagSolver();
    Matrix* x_solve = solver.solve(A, b);

    A->print();
    b->print();
    x->print();
    x_solve->print();
    return 0;
};
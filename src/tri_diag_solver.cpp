#include <tri_diag_solver.h>
#include <matrix.h>
#include <math.h>
#include <iostream>

Matrix* TriDiagSolver::solve(Matrix* A, Matrix* b){
    Matrix* Q = new Matrix(A->n, A->m);
    Q->identity();
    Matrix* T = new Matrix(*A);
    //Givens rotation
    for(int j=0; j<Q->n - 1; j++){
        this->givens(T, Q, j);
    }
    Matrix* y = Q->MatMul(b);
    //Backward substitution    
    Matrix* x = this->back_sub(T, y);

    delete Q;
    delete T;
    delete y;

    return x;
}

void TriDiagSolver::givens(Matrix* T, Matrix* Q, int j){
    Matrix givens_matrix = Matrix(*Q);
    givens_matrix.identity();
    float denom = pow( pow( T->get(j, j), 2) + pow( T->get(j+1, j), 2), .5);
    float c = T->get(j, j);
    float s = T->get(j+1, j);
    givens_matrix.set(j, j, c/denom);
    givens_matrix.set(j, j+1, s/denom);
    givens_matrix.set(j+1, j, -1*s/denom);
    givens_matrix.set(j+1, j+1, c/denom);
    Matrix* new_T = givens_matrix.MatMul(T);
    T->set_matrix(new_T);
    Matrix* new_Q = givens_matrix.MatMul(Q);
    Q->set_matrix(new_Q);
    delete new_T;
    delete new_Q;
}

Matrix* TriDiagSolver::back_sub(Matrix* A, Matrix* b){
    Matrix* x = new Matrix(A->n, 1);
    for(int i=x->m - 1; i>=0; i--){
        float value = b->get(i,0);
        for(int j=x->m - 1; j>i; j--){
            value -= A->get(i, j) * x->get(j, 0);
        }
        x->set(i, 0, value/A->get(i, i));
    }
    return x;
}
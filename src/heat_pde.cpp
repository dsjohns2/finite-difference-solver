#include <PDE/heat_pde.h>
#include <matrix.h>
#include <tri_diag_solver.h>
#include <iostream>

HeatPDE::HeatPDE(float h, int N, Matrix* data){
    this->h = h;
    this->N = N;
    this->stencil = this->generate_stencil();
    this->data = data;
    this->solver = new TriDiagSolver();
};

HeatPDE::~HeatPDE(){
    delete this->solver;
    delete this->stencil;
}

Matrix* HeatPDE::generate_stencil(){
    Matrix* stencil = new Matrix(this->N + 1, this->N + 1);
    stencil->set(0, 0, 1);
    stencil->set(this->N, this->N, 1);
    for(int i=1; i<this->N; i++){
        float scalar = 1/(this->h*this->h);
        stencil->set(i, i-1, 1 * scalar);
        stencil->set(i, i, -2 * scalar);
        stencil->set(i, i+1, 1 * scalar);
    }
    return stencil;
}

Matrix* HeatPDE::solve(){
    return this->solver->solve(this->stencil, this->data);
}
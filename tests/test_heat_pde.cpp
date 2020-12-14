#include <PDE/heat_pde.h>
#include <iostream>

int main(){
    float h = .1;
    int N = 10;
    float left_boundary_condition = 1;
    float right_boundary_condition = 3;
    Matrix* data = new Matrix(N+1, 1);
    data->set(0, 0, left_boundary_condition);
    data->set(N, 0, right_boundary_condition);
    HeatPDE* pde = new HeatPDE(h, N, data);
    pde->stencil->print();
    Matrix* x = pde->solve();
    x->print();
    return 0;
};
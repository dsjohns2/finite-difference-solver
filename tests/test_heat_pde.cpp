#include <PDE/heat_pde.h>
#include <iostream>
#include <math.h>

int main(int argc, char** argv){
    float h = .1;
    int N = 10;
    float left_boundary_condition = 1;
    float right_boundary_condition = 1;
    Matrix* grid = new Matrix(N+1, 1);
    Matrix* data = new Matrix(N+1, 1);
    for(int i=0; i<N+1; i++){
        float x = i*h;
        float val = 5*(sin(M_PI*x) - cos(M_PI*x));
        grid->set(i, 0, x);
        data->set(i, 0, val);
    }
    data->set(0, 0, left_boundary_condition);
    data->set(N, 0, right_boundary_condition);
    HeatPDE* pde = new HeatPDE(h, N, data);
    pde->stencil->print();
    Matrix* x = pde->solve();
    x->print();
    x->save("tests/solution.txt");
    grid->save("tests/grid.txt");

    delete grid;
    delete data;
    delete pde;
    delete x;
    return 0;
};
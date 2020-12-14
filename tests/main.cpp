#include <PDE/heat_pde.h>

int main(){
    float h = .1;
    float left_boundary_condition = 1;
    float right_boundary_condition = 2;
    Matrix* data = new Matrix(10, 1);
    HeatPDE* pde = new HeatPDE(h, left_boundary_condition, right_boundary_condition, data);
    pde->solve();
    return 0;
};
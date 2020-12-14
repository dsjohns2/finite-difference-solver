#pragma once

#include <matrix.h>
#include <tri_diag_solver.h>

class HeatPDE{
    public:
        HeatPDE(float h, int N, Matrix* data);
        ~HeatPDE();
        int N;
        float h;
        Matrix* stencil;
        Matrix* data;
        TriDiagSolver* solver;
        Matrix* generate_stencil();
        Matrix* solve();
};
#pragma once

#include <matrix.h>

class TriDiagSolver{
    public:
        Matrix* solve(Matrix* A, Matrix* b);
        void givens(Matrix* T, Matrix* Q, int j);
        Matrix* back_sub(Matrix* A, Matrix* b);
};
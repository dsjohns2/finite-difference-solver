cmake_minimum_required( VERSION 3.0 )

project( pde )

# flags

# include files
include_directories( ./include ./src ./tests)

# target
add_executable( matrix_test ./tests/test_matrix.cpp ./src/matrix.cpp )
add_executable( tri_diag_solver_test ./tests/test_tri_diag_solver.cpp ./src/tri_diag_solver.cpp ./src/matrix.cpp )
add_executable( heat_pde_test ./tests/test_heat_pde.cpp ./src/heat_pde.cpp ./src/matrix.cpp ./src/tri_diag_solver.cpp )

# 3rd party libs
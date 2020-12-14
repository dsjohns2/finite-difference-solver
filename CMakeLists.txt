cmake_minimum_required( VERSION 3.0 )

project( pde )

# flags
set(CMAKE_BUILD_TYPE Debug)

# include files
include_directories( ./include ./src ./tests)

# target
add_executable( test_matrix ./tests/test_matrix.cpp ./src/matrix.cpp )
add_executable( test_tri_diag_solver ./tests/test_tri_diag_solver.cpp ./src/tri_diag_solver.cpp ./src/matrix.cpp )
add_executable( test_heat_pde ./tests/test_heat_pde.cpp ./src/heat_pde.cpp ./src/matrix.cpp ./src/tri_diag_solver.cpp )

# 3rd party libs
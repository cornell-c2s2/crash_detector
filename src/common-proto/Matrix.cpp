//========================================================================
// Matrix.cpp
//========================================================================
// Implementation of Matrix. 

#include "Matrix.h"

//------------------------------------------------------------------------
// Matrix
//------------------------------------------------------------------------
// Matrix Constructor.
// Constructs a Matrix object. 
Matrix::Matrix() {
  

int r, c, a[100][100], b[100][100], result[100][100], i, j;
// NOTES - QUESTIONS - CONCERNS 
// What should be the maximum size of the matrix that we can have? 

// OTHER THINGS TO DO: 
// Add functions: transpose(), multiply() 
// figure out interface? 


int add(i_max,j_max, a[i_max][j_max],b){
  int sum[100][100], i, j;
  for (i = 0; i < i_max; ++i)
    for (j = 0; j < j_max; ++j) {
      sum[i][j] = a[i][j] + b[i][j];
    }
    return sum[i][j];
}

int subtract(a,b,i_max,j_max){
  int sum[100][100], i, j;
  for (i = 0; i < i_max; ++i)
    for (j = 0; j < j_max; ++j) {
      sum[i][j] = a[i][j] - b[i][j];
    }
}


int main() {
  int r, c, a[100][100], b[100][100], i, j;

  // start by getting the number of rows and columns to check for same size
  // NOTE Potential error -> need to add size checking function
  printf("Enter the number of rows (between 1 and 100): ");
  scanf("%d", &r);
  printf("Enter the number of columns (between 1 and 100): ");
  scanf("%d", &c);

  // Get elements for the rows and columns
  // NOTE : Potential error -> need to check if the given size and elements are the same 
  printf("\nEnter elements of 1st matrix:\n");
  for (i = 0; i < r; ++i)
    for (j = 0; j < c; ++j) {
      printf("Enter element a%d%d: ", i + 1, j + 1);
      scanf("%d", &a[i][j]);
    }
  printf("Enter elements of 2nd matrix:\n");
  for (i = 0; i < r; ++i)
    for (j = 0; j < c; ++j) {
      printf("Enter element b%d%d: ", i + 1, j + 1);
      scanf("%d", &b[i][j]);
    }

  int result =add(r,c, a,b);

  // printing the result
  printf("\nSum of two matrices: \n");
  for (i = 0; i < r; ++i)
    for (j = 0; j < c; ++j) {
      printf("%d   ", result[i][j]);
      if (j == c - 1) {
        printf("\n\n");
      }
    }

  return 0;
}
}


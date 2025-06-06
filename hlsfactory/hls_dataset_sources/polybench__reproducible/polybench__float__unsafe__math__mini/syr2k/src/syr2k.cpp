#include "syr2k.h"


void kernel_syr2k( 
		  double alpha,
		  double beta,
		  double C[ 30 + 0][30 + 0],
		  double A[ 30 + 0][20 + 0],
		  double B[ 30 + 0][20 + 0])
{
  #pragma HLS top name=kernel_syr2k

    const int n = 30;
    const int m = 20;

  int i, j, k;
  lp1: for (i = 0; i < n; i++) {
    lp2: for (j = 0; j <= i; j++)
      C[i][j] *= beta;
    lp3: for (k = 0; k < m; k++)
      lp4: for (j = 0; j <= i; j++)
	{
	  C[i][j] += A[j][k]*alpha*B[i][k] + B[j][k]*alpha*A[i][k];
	}
  }

}
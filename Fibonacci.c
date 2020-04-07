#include <stdio.h>
#include <omp.h>
 
int main()
{
  int a, b[100], j;
 

  omp_set_num_threads(2);
 
  printf("Enter the number of Fibonacci numbers to be generated : \n > ");
  scanf("%d", &a);
 
  b[0] = 0; b[1] = 1;
 
  #pragma omp parallel
  {
    #pragma omp single
    for (j = 2; j < a; j++) {
      b[j] = b[j-1] + b[j-2];
      printf("Computation of Fibonacci number %d, thread_id is %d\n", j, omp_get_thread_num());
    }
   
    #pragma omp barrier
   
    #pragma omp single
    {
      printf("The elements of the fibonacci series are : \n");
      for (j = 0; j < a; j++) {
        printf("%d, thread_id is %d\n", b[j], omp_get_thread_num());
      }
    }
  }  
 
  return 0;
}

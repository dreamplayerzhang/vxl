/*
  fsm@robots.ox.ac.uk
*/
#include <vcl/vcl_algorithm.h>

int main(int, char **) 
{
  double v[5] = {1,5,2,4,3};
  vcl_sort(v, v+5);

  return 0;
}

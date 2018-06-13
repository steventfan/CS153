#include "types.h"
#include "user.h"
#pragma GCC push_options
#pragma GCC optimize("O0")

int main(int argc, char *argv[])
{
  void recursion(int);

  printf(1, "\n Running tests for Lab 3 \n");
  if(argc > 1)
  {
    recursion(1000);
  }

  exit();
}

void recursion(int number)
{
  printf(1, "\n Recursion %d \n", number);
  if(number > 0)
  {
    recursion(number - 1);
  }
}

#pragma GCC pop_options

#include "debug_output.h"

int main()
{
  char arr[] = {'a', 's', 'd', 'f'}; // not null terminated!

  DOUT(  << "DOUT via function-like " << " macro" << " statement"  << std::endl);
  DOUT(  .write(arr, sizeof(arr))  << std::endl);

  DMOUT( << "DMOUT via function-like " << " macro" << " statement"  << std::endl);
  DMOUT( .write(arr, sizeof(arr))  << std::endl);
  
  return 0;
}

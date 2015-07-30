#include "debug_output.h"

int main()
{
  char arr[] = {'a', 's', 'd', 'f'}; // not null terminated!

#define DEBUG_OUTPUT_VARIANT   DEBUG_OUTPUT_FUNCLIKE_STATEMENT
#include "debug_output_selector.h"

  DOUT(  << "DOUT via function-like " << " macro" << " statement"  << std::endl);
  DOUT(  .write(arr, sizeof(arr))  << std::endl);

  DMOUT( << "DMOUT via function-like " << " macro" << " statement"  << std::endl);
  DMOUT( .write(arr, sizeof(arr))  << std::endl);
  

#undef  DEBUG_OUTPUT_VARIANT
#define DEBUG_OUTPUT_VARIANT   DEBUG_OUTPUT_FUNCLIKE_CHAINING
#include "debug_output_selector.h"
  
  (DOUT(  << "DOUT via function-like " << " macro"))   << " expression chaining" << std::endl; 
  DOUT(  .write(arr, sizeof(arr))  << std::endl);

  /* mutex only holds for the bracketed arguments of DMOUT */
  DMOUT( << "DMOUT via function-like " << " macro")     << " expression chaining"  << std::endl;
  DMOUT( .write(arr, sizeof(arr))  << std::endl);
  (DMOUT( << ("wow", "DMOUT") << " is"))                << " cool"                  << std::endl; /* demo why __VA_ARGS__ is needed! */

#undef  DEBUG_OUTPUT_VARIANT
#define DEBUG_OUTPUT_VARIANT   DEBUG_OUTPUT_NON_FUNCLIKE
#include "debug_output_selector.h"

  D_OUT << "hi " << std::endl;  
  return 0;
}

#include "debug_output_headers.h"

int main()
{
  char arr[] = {'a', 's', 'd', 'f'}; // not null terminated!

#define DEBUG_OUTPUT_VARIANT   DEBUG_OUTPUT_FUNCLIKE_STATEMENT
#include "debug_output.h"

  D_OUT(  << "D_OUT via function-like " << " macro" << " statement"  << std::endl);
  D_OUT(  .write(arr, sizeof(arr))  << std::endl);

  DM_OUT( << "DM_OUT via function-like " << " macro" << " statement"  << std::endl);
  DM_OUT( .write(arr, sizeof(arr))  << std::endl);
  

#undef  DEBUG_OUTPUT_VARIANT
#define DEBUG_OUTPUT_VARIANT   DEBUG_OUTPUT_FUNCLIKE_CHAINING
#include "debug_output.h"
  
  (D_OUT(  << "D_OUT via function-like " << " macro"))   << " expression chaining" << std::endl; 
  D_OUT(  .write(arr, sizeof(arr))  << std::endl);

  /* mutex only holds for the bracketed arguments of DM_OUT */
  DM_OUT( << "DM_OUT via function-like " << " macro")     << " expression chaining"  << std::endl;
  DM_OUT( .write(arr, sizeof(arr))  << std::endl);
  (DM_OUT( << ("wow", "DM_OUT") << " is"))                << " cool"                  << std::endl; /* demo why __VA_ARGS__ is needed! */

#undef  DEBUG_OUTPUT_VARIANT
#define DEBUG_OUTPUT_VARIANT   DEBUG_OUTPUT_NON_FUNCLIKE
#include "debug_output.h"

  DOUT << "hi " << std::endl;  
  return 0;
}

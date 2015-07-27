//////////////////
// User Settings
//////////////////

/* If you want to globally use a specific type of D_OUT (etc.) you can set that, 
   by setting one of the following 3 variants to uncommented.

   Alternatively you can leave all versions commented, and decide on a per-case basis what kind of
   D_OUT (etc.) you want. In that case do e.g. the following in cpp files
        #undef  DEBUG_OUTPUT_VARIANT
        #define DEBUG_OUTPUT_VARIANT   DEBUG_OUTPUT_FUNCLIKE_STATEMENT
        #include "debug_output.h"
        DOUT( << "hi" << std::endl);
   But that's one hell of a act, so just uncomment one of the following 3 variants
 */
//#define DEBUG_OUTPUT_VARIANT DEBUG_OUTPUT_FUNCLIKE_STATEMENT
//#define DEBUG_OUTPUT_VARIANT DEBUG_OUTPUT_FUNCLIKE_CHAINING
//#define DEBUG_OUTPUT_VARIANT DEBUG_OUTPUT_NON_FUNCLIKE


/*
  If you  have left all 3 variants above commented (really!?),
  and plan to use DEBUG_OUTPUT_FUNCLIKE_CHAINING somewhere (on a per-case basis)
  then you need to uncomment the following line, in order to allow the linker to find the global called nullout
 */
#define DEBUG_OUTPUT_GLOBAL_NULLOUT



/* Use mutex protection everywhere ? Even in normal D_OUT, D_ERR or D_LOG ?
   Then uncomment the following
*/
//#define DEBUG_OUT_MUTEX_EVERYWHERE



/* Are you sure you do NOT want to use mutex-protected versions (DM_OUT, DM_ERR or DM_LOG) ?
   Then uncomment the following:
*/
//#define DEBUG_OUT_NO_DM_MUTEX

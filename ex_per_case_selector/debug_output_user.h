//////////////////
// User Settings
//////////////////

/* If you want to globally use a specific type of DOUT (etc.) you can set that, 
   by setting one of the following 3 variants to uncommented.

   Alternatively you can leave all versions commented, and decide on a per-case basis what kind of
   DOUT (etc.) you want. In that case do e.g. the following in cpp files
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



/* Use mutex protection everywhere (within brackets)? Even in normal DOUT, DERR or DLOG ?
   Then uncomment the following
*/
//#define DEBUG_OUT_MUTEX_EVERY_BRACKET



/* Are you sure you do NOT want to use mutex-protected versions called DMOUT, DMERR or DMLOG ?
   Then uncomment the following:
*/
//#define DEBUG_OUT_NO_DM

/* With filename and linenumbers? Then uncomment the following
 */
#define DEBUG_OUT_LINENO

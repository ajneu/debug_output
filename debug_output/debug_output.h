#ifndef DEBUG_OUTPUT_H
#define DEBUG_OUTPUT_H

// user settings
#include "debug_output_user.h"


#include "debug_output_selector.h"





#ifndef NDEBUG /* -------------------------------- */
// debugging: so print debug output

#include <iostream>

#if !defined (DEBUG_OUT_NO_DM) || defined (DEBUG_OUT_MUTEX_EVERY_BRACKET)
#include <mutex>
extern std::mutex debug_out_mutex;
#endif

#else  /* ---------------------------------------- */
// NOT debugging: so do NOT print debug output


constexpr bool debug_output_disabled{true};

#if ((DEBUG_OUTPUT_VARIANT == DEBUG_OUTPUT_FUNCLIKE_CHAINING) || defined (DEBUG_OUTPUT_GLOBAL_NULLOUT) || \
     (DEBUG_OUTPUT_VARIANT == DEBUG_OUTPUT_NON_FUNCLIKE))

#include <ostream>

/// https://groups.google.com/d/msg/comp.lang.c++/HkEffd3Geb4/g8J6yTgSyQkJ
struct Nullstream: std::ostream {
 Nullstream(): std::ios(0), std::ostream(0) {}
};

#endif


#if ((DEBUG_OUTPUT_VARIANT == DEBUG_OUTPUT_FUNCLIKE_CHAINING) || defined (DEBUG_OUTPUT_GLOBAL_NULLOUT))
extern Nullstream nullout;
#endif

#endif  /* --------------------------------------- */




#endif

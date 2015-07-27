#include "debug_output_user.h"

#if !defined (NDEBUG)   &&   (!defined (DEBUG_OUT_NO_DM) || defined (DEBUG_OUT_MUTEX_EVERYWHERE))
#include <mutex>
std::mutex debug_out_mutex;
#endif


#if  defined (NDEBUG)   &&   ((DEBUG_OUTPUT_VARIANT == DEBUG_OUTPUT_FUNCLIKE_CHAINING) || defined (DEBUG_OUTPUT_GLOBAL_NULLOUT))
#include <ostream>

/// https://groups.google.com/d/msg/comp.lang.c++/HkEffd3Geb4/g8J6yTgSyQkJ
struct Nullstream: std::ostream {
 Nullstream(): std::ios(0), std::ostream(0) {}
};

Nullstream nullout;
#endif

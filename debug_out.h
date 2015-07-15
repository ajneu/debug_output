#ifndef DEBUG_OUT_H
#define DEBUG_OUT_H

/*
Print debug info only when debugging. When NDEBUG (no debug) is defined, then print nothing
*/


// choose one of the following variants:
#define DEBUG_OUT_VARIANT1
//#define DEBUG_OUT_VARIANT2


/*

There are 2 Variants:

1) DEBUG_OUT_VARIANT1

DOUT << "this is how is works" << std::endl; // output to cout, unless NDEBUG is defined
DERR << "this is how is works" << std::endl; // output to cerr, unless NDEBUG is defined
DLOG << "this is how is works" << std::endl; // output to clog, unless NDEBUG is defined

Limitations:
(DOUT << "string") << "oops"; // this does not work!

2) DEBUG_OUT_VARIANT2

DOUT_v2( << "this is how is works" << std::endl); // output to cout, unless NDEBUG is defined
DERR_v2( << "this is how is works" << std::endl); // output to cerr, unless NDEBUG is defined
DLOG_v2( << "this is how is works" << std::endl); // output to clog, unless NDEBUG is defined


This does not have the above limitation. The following works:
(DOUT_v2( << "string")) << "oops"; // this works

But therefore the output operator and operands have to be wrapped in brackets (), which looks rather ugly.
So choose DEBUG_OUT_VARIANT1, because you really do not need DEBUG_OUT_VARIANT2 (or do you?)

 */




#ifdef NDEBUG /* ~~~~~~~~~~~~~~~~~~~ */
// NOT debugging: so do NOT print debug output

#include <ostream>

/* https://groups.google.com/d/msg/comp.lang.c++/HkEffd3Geb4/g8J6yTgSyQkJ
   possible alternatives for a nullstream:
   http://stackoverflow.com/a/7818394  // but use:   static null_out_buf buf;
 */
struct Nullstream:
  std::ostream {
 Nullstream(): std::ios(0), std::ostream(0) {}
};

#endif /* ~~~~~~~~~~~~~~~~~~~~~~~~~~ */







#ifdef DEBUG_OUT_VARIANT1 /* -------------------------------------------------- */

#ifndef NDEBUG  /* //////////////////////////// */
// debugging: print debug output

#include <iostream>

#define DOUT std::cout
#define DERR std::cerr
#define DLOG std::clog

#else  /* ///////////////////////////////////// */
// NOT debugging: so do NOT print debug output

// http://stackoverflow.com/a/11826787

constexpr bool debug_disabled{true};

#define DOUT if (debug_disabled) {} else Nullstream()
#define DERR if (debug_disabled) {} else Nullstream()
#define DLOG if (debug_disabled) {} else Nullstream()

#endif  /* //////////////////////////////////// */

#elif defined DEBUG_OUT_VARIANT2 /* ------------------------------------------- */

#ifndef NDEBUG  /* //////////////////////////// */
// debugging: print debug output

#include <iostream>

#define DOUT_v2(...) (std::cout __VA_ARGS__)
#define DERR_v2(...) (std::cerr __VA_ARGS__)
#define DLOG_v2(...) (std::clog __VA_ARGS__)

#else  /* ///////////////////////////////////// */
// NOT debugging: so do NOT print debug output

constexpr bool debug_disabled{true};

#define DOUT_v2(...) nullout
#define DERR_v2(...) nullout
#define DLOG_v2(...) nullout


extern Nullstream nullout;

#endif  /* //////////////////////////////////// */

#else /* ------------------------------------------------------------ */

#error **** Warning:Neiter DEBUG_OUT_VARIANT1 nor DEBUG_OUT_VARIANT2 defined *****

#endif /* ----------------------------------------------------------- */

#endif

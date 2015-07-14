#ifndef DEBUG_OUT_H
#define DEBUG_OUT_H

/*
Print debug info only when debugging. When NDEBUG (no debug) is defined, then print nothing
*/


// choose one of the following variants:
#define VARIANT1
//#define VARIANT2


/*

There are 2 Variants:

1) VARIANT1

DOUT << "this is how is works" << std::endl; // output to cout, unless NDEBUG is defined
DERR << "this is how is works" << std::endl; // output to cerr, unless NDEBUG is defined
DLOG << "this is how is works" << std::endl; // output to clog, unless NDEBUG is defined

Limitations:
(DOUT << "string") << "oops"; // this does not work!

2) VARIANT2

DOUT_v2( << "this is how is works" << std::endl); // output to cout, unless NDEBUG is defined
DERR_v2( << "this is how is works" << std::endl); // output to cerr, unless NDEBUG is defined
DLOG_v2( << "this is how is works" << std::endl); // output to clog, unless NDEBUG is defined


This does not have the above limitation. The following works:
(DOUT_v2( << "string")) << "oops"; // this works

But therefore the output operator and operands have to be wrapped in brackets (), which looks rather ugly.
So choose VARIANT1, because you really do not need VARIANT2 (or do you?)

 */





#ifdef VARIANT1 /* -------------------------------------------------- */

#ifndef NDEBUG  /* //////////////////////////// */
// debugging: print debug output

#include <iostream>

#define DOUT std::cout
#define DERR std::cerr
#define DLOG std::clog

#else  /* ///////////////////////////////////// */
// NOT debugging: so do NOT print debug output

// http://stackoverflow.com/a/11826787
#include <iostream>

constexpr bool debug_disabled{true};

#define DOUT if (debug_disabled) {} else std::cerr
#define DERR if (debug_disabled) {} else std::cerr
#define DLOG if (debug_disabled) {} else std::cerr

#endif  /* //////////////////////////////////// */

#elif defined VARIANT2 /* ------------------------------------------- */

#ifndef NDEBUG  /* //////////////////////////// */
// debugging: print debug output

#include <iostream>

#define DOUT_v2(...) std::cout __VA_ARGS__
#define DERR_v2(...) std::cerr __VA_ARGS__
#define DLOG_v2(...) std::clog __VA_ARGS__

#else  /* ///////////////////////////////////// */
// NOT debugging: so do NOT print debug output

#include <iostream>

constexpr bool debug_disabled{true};

#define DOUT_v2(...) ((debug_disabled) ? nullout : nullout __VA_ARGS__)
#define DERR_v2(...) ((debug_disabled) ? nullout : nullout __VA_ARGS__)
#define DLOG_v2(...) ((debug_disabled) ? nullout : nullout __VA_ARGS__)

/* https://groups.google.com/d/msg/comp.lang.c++/HkEffd3Geb4/g8J6yTgSyQkJ
   possible alternatives from a nullstream:
   http://stackoverflow.com/a/7818394  // but use:   static null_out_buf buf;
   
 */
struct Nullstream:
  std::ostream {
 Nullstream(): std::ios(0), std::ostream(0) {}
};

extern Nullstream nullout;

#endif  /* //////////////////////////////////// */

#else /* ------------------------------------------------------------ */

#error **** Warning:Neiter VARIANT1 nor VARIANT2 defined *****

#endif /* ----------------------------------------------------------- */

#endif

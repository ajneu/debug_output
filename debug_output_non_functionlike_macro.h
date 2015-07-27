#undef D_OUT
#undef D_ERR
#undef D_LOG

#undef DM_OUT
#undef DM_ERR
#undef DM_LOG

#undef priv_dm_out
#undef priv_dm_err
#undef priv_dm_log

#undef DOUT
#undef DOUT
#undef DOUT


#ifdef DEBUG_OUT_MUTEX_EVERYWHERE
#error cannot use DEBUG_OUTPUT_NON_FUNCLIKE (with DOUT, ERR, DLOG) if DEBUG_OUT_MUTEX_EVERYWHERE is defined
#endif

#ifndef NDEBUG  /* ------------------------------------------------------------ */
// debugging: print debug output

/* #include <iostream> // see debug_output_headers.h
                       // (which is included at top of cpp files)
*/
#define DOUT (std::cout)
#define DERR (std::cerr)
#define DLOG (std::clog)


#else  /* --------------------------------------------------------------------- */
// NOT debugging: so do NOT print debug output

#define DOUT if (debug_output_disabled)  { /* nothing */ } else Nullstream()
#define DERR if (debug_output_disabled)  { /* nothing */ } else Nullstream()
#define DLOG if (debug_output_disabled)  { /* nothing */ } else Nullstream()

#endif /* --------------------------------------------------------------------- */

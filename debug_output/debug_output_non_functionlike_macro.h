#undef DOUT
#undef DERR
#undef DLOG

#undef DMOUT
#undef DMERR
#undef DMLOG

#undef priv_dm_out
#undef priv_dm_err
#undef priv_dm_log

#undef D_OUT
#undef D_ERR
#undef D_LOG

#undef priv_line

#ifdef DEBUG_OUT_LINENO
#define priv_str(x) priv_val(x)
#define priv_val(x) #x
#define priv_line << __FILE__ ":" priv_str(__LINE__) " "
#else
#define priv_line
#endif


#ifndef NDEBUG  /* ------------------------------------------------------------ */
// debugging: print debug output

/* #include <iostream> // see debug_output_headers.h
                       // (which is included at top of cpp files)
*/
#define D_OUT (std::cout priv_line)
#define D_ERR (std::cerr priv_line)
#define D_LOG (std::clog priv_line)


#else  /* --------------------------------------------------------------------- */
// NOT debugging: so do NOT print debug output

#define D_OUT if (debug_output_disabled)  { /* nothing */ } else Nullstream()
#define D_ERR if (debug_output_disabled)  { /* nothing */ } else Nullstream()
#define D_LOG if (debug_output_disabled)  { /* nothing */ } else Nullstream()

#endif /* --------------------------------------------------------------------- */

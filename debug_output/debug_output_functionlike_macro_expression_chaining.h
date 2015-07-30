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


#define priv_dm_out(...)                                      \
  (static_cast<void>                                          \
   (                                                          \
    [&](){ std::lock_guard<std::mutex> lock{debug_out_mutex}; \
           (std::cout priv_line) __VA_ARGS__;                 \
    }()                                                       \
   ), std::cout)

#define priv_dm_err(...)                                      \
  (static_cast<void>                                          \
   (                                                          \
    [&](){ std::lock_guard<std::mutex> lock{debug_out_mutex}; \
           (std::cerr priv_line) __VA_ARGS__;                 \
    }()                                                       \
   ), std::cerr)

#define priv_dm_log(...)                                      \
  (static_cast<void>                                          \
   (                                                          \
    [&](){ std::lock_guard<std::mutex> lock{debug_out_mutex}; \
           (std::clog priv_line) __VA_ARGS__;                 \
    }()                                                       \
   ), std::clog)

/*
// statement expressions (seem to be a GNU extension)

#define priv_dm_out(...)                                      \
(({ std::lock_guard<std::mutex> lock{debug_out_mutex};        \
    static_cast<void>((std::cout priv_line) __VA_ARGS__);     \
   }), std::cout)

#define priv_dm_err(...)                                      \
(({ std::lock_guard<std::mutex> lock{debug_out_mutex};        \
    static_cast<void>((std::cerr priv_line) __VA_ARGS__);     \
   }), std::cerr)

#define priv_dm_log(...)                                      \
(({ std::lock_guard<std::mutex> lock{debug_out_mutex};        \
    static_cast<void>((std::clog priv_line) __VA_ARGS__);     \
   }), std::clog)

*/


#ifndef DEBUG_OUT_MUTEX_EVERY_BRACKET /* ............ */

/* #include <iostream> // see debug_output.h
                       // (which is included at top of cpp files)
*/
#define DOUT(...) ((std::cout priv_line) __VA_ARGS__)
#define DERR(...) ((std::cerr priv_line) __VA_ARGS__)
#define DLOG(...) ((std::clog priv_line) __VA_ARGS__)

#else  /* ........................................... */

/* #include <mutex> // see debug_output.h
                    // (which is included at top of cpp files)
*/
#define DOUT(...) priv_dm_out(__VA_ARGS__)
#define DERR(...) priv_dm_err(__VA_ARGS__)
#define DLOG(...) priv_dm_log(__VA_ARGS__)

#endif   /* ......................................... */



#ifndef DEBUG_OUT_NO_DM /* ~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/* #include <mutex> // see debug_output.h
                    // (which is included at top of cpp files)
*/
#define DMOUT(...) priv_dm_out(__VA_ARGS__)
#define DMERR(...) priv_dm_err(__VA_ARGS__)
#define DMLOG(...) priv_dm_log(__VA_ARGS__)
  
#endif /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

  

#else  /* --------------------------------------------------------------------- */
// NOT debugging: so do NOT print debug output

#define DOUT(...) nullout
#define DERR(...) nullout
#define DLOG(...) nullout

  
#ifndef DEBUG_OUT_NO_DM /* ~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#define DMOUT(...) nullout
#define DMERR(...) nullout
#define DMLOG(...) nullout

#endif  /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#endif /* --------------------------------------------------------------------- */

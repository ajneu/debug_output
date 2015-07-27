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


#ifndef DEBUG_OUT_MUTEX_EVERYWHERE /* ............... */

/* #include <iostream> // see debug_output_headers.h
                       // (which is included at top of cpp files)
*/
#define D_OUT(...) ((std::cout priv_line) __VA_ARGS__)
#define D_ERR(...) ((std::cerr priv_line) __VA_ARGS__)
#define D_LOG(...) ((std::clog priv_line) __VA_ARGS__)

#else  /* ........................................... */

/* #include <mutex> // see debug_output_headers.h
                    // (which is included at top of cpp files)
*/
#define D_OUT(...) priv_dm_out(__VA_ARGS__)
#define D_ERR(...) priv_dm_err(__VA_ARGS__)
#define D_LOG(...) priv_dm_log(__VA_ARGS__)

#endif   /* ......................................... */



#ifndef DEBUG_OUT_NO_DM /* ~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/* #include <mutex> // see debug_output_headers.h
                    // (which is included at top of cpp files)
*/
#define DM_OUT(...) priv_dm_out(__VA_ARGS__)
#define DM_ERR(...) priv_dm_err(__VA_ARGS__)
#define DM_LOG(...) priv_dm_log(__VA_ARGS__)
  
#endif /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

  

#else  /* --------------------------------------------------------------------- */
// NOT debugging: so do NOT print debug output

#define D_OUT(...) nullout
#define D_ERR(...) nullout
#define D_LOG(...) nullout

  
#ifndef DEBUG_OUT_NO_DM /* ~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#define DM_OUT(...) nullout
#define DM_ERR(...) nullout
#define DM_LOG(...) nullout

#endif  /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#endif /* --------------------------------------------------------------------- */

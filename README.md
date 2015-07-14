# debug_output

C++ debug output that's get's printed, unless NDEBUG is defined

choose one of the following variants (to be set in `debug_out.h`):
```
#define VARIANT1  
//#define VARIANT2
```

### 1) VARIANT1
```
DOUT << "this is how is works" << std::endl; // output to cout, unless NDEBUG is defined
DERR << "this is how is works" << std::endl; // output to cerr, unless NDEBUG is defined
DLOG << "this is how is works" << std::endl; // output to clog, unless NDEBUG is defined
```
Limitations:  
`(DOUT << "string") << "oops";` // this does not work!

### 2) VARIANT2
```
DOUT_v2( << "this is how is works" << std::endl); // output to cout, unless NDEBUG is defined
DERR_v2( << "this is how is works" << std::endl); // output to cerr, unless NDEBUG is defined
DLOG_v2( << "this is how is works" << std::endl); // output to clog, unless NDEBUG is defined
```

This does not have the limitation of VARIANT1 above. The following works:  
`(DOUT_v2( << "string")) << "oops";` // this works

But as a consequence, the output operator and operands now have to be wrapped in brackets (), which looks rather ugly.
So choose VARIANT1, because you really do not need/want VARIANT2 (or do you?)

## Credits
Variant 1 is adapted from here: http://stackoverflow.com/a/11826787  
Variant 2 uses https://groups.google.com/d/msg/comp.lang.c++/HkEffd3Geb4/g8J6yTgSyQkJ

#define DEBUG_OUTPUT_FUNCLIKE_STATEMENT 1
#define DEBUG_OUTPUT_FUNCLIKE_CHAINING  2
#define DEBUG_OUTPUT_NON_FUNCLIKE       3


#if DEBUG_OUTPUT_VARIANT   == DEBUG_OUTPUT_FUNCLIKE_STATEMENT
#include "debug_output_functionlike_macro_statement.h"
#elif DEBUG_OUTPUT_VARIANT == DEBUG_OUTPUT_FUNCLIKE_CHAINING
#include "debug_output_functionlike_macro_expression_chaining.h"
#elif DEBUG_OUTPUT_VARIANT == DEBUG_OUTPUT_NON_FUNCLIKE
#include "debug_output_non_functionlike_macro.h"
#else
#error "DEBUG_OUTPUT_VARIANT does not have suitable value"
#endif

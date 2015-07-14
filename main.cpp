#include "debug_out.h"
#include <iomanip>

int main()
{
  char arr[] = {'a', 's', 'd', 'f'}; // not null terminated!

#ifdef DEBUG_OUT_VARIANT1
  DOUT     << "hello"   << " there"  << std::endl;
  DOUT.write(arr, sizeof(arr)) << std::endl;
#elif defined DEBUG_OUT_VARIANT2
  DOUT_v2( << "hello"   << " there"  << std::endl); // wrap in brackets!

  (DOUT_v2( << ("wow", "hello2") << " there2" << std::endl)) << "cool" << std::endl;

  DOUT_v2(.write(arr, sizeof(arr)) << std::endl);
#endif
  return 0;
}

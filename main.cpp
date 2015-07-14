#include "debug_out.h"
#include <iomanip>

int main()
{
#ifdef VARIANT1
  DOUT     << "hello"   << " there"  << std::endl;
#elif defined VARIANT2
  DOUT_v2( << "hello"   << " there"  << std::endl); // wrap in brackets!

  (DOUT_v2( << ("wow", "hello2") << " there2" << std::endl)) << "cool" << std::endl;
#endif
  return 0;
}

#include "camino.h"

// static bool stop = true;

DataPath::DataPath(sc_module_name name)
    : sc_module(name), adder("sumador"), im("im_"), pc("pc"), re("re_") {

   pc.clkIn(clkIn);
   pc.addressPC(SgOutadd);
   pc.addressBlock(SgOutPC);

   adder.sIn(SgOutPC);
   adder.sOut(SgOutadd);

   im.address(SgOutPC);
   im.block(SgOutim);

   re.cpIn(SgOutPC);
   re.insIn(SgOutim);
   re.clkIn(clkIn);
   re.cpOut(Sg_cpOutre);
   re.insOut(Sg_stringDOutre);

}
DataPath::~DataPath() {}


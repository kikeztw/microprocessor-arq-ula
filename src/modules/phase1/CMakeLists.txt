set(
  SRC_MODULES_PHASE_1
  Adder.cpp Adder.h
  instruction_memory.cpp instruction_memory.h
  pc.cpp pc.h
  register_if_id.cpp register_if_id.h
)

add_library(A_MODULES_PHASE_ONE STATIC ${SRC_MODULES_PHASE_1})

set(
  SRC_PHASES
  phase1.cpp phase1.h
)
add_library(A_PHASES STATIC ${SRC_PHASES})
target_link_libraries(A_PHASES A_MODULES_PHASE_ONE A_UTILITY_FILES)

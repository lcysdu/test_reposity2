
include_directories(
    ${SOLUTION_INCLUDE_DIRS}
    ${OpenCV_INCLUDE_DIRS})
link_directories(
    ${OpenCV_LIB_DIR})
    
add_library(utility
	ctimer.cpp
	ctimer.h
	relay.cpp
	relay.h
)

add_executable(relay-test
	relay-test.cpp
)

target_link_libraries(utility hidapi-libusb pthread ${OpenCV_LIBS})

target_link_libraries(relay-test utility)

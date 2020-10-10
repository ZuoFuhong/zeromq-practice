cmake_minimum_required(VERSION 3.17)
project(zeromq_practice C)

set(CMAKE_C_STANDARD 99)
set(INC_DIR /usr/local/include)
set(LINK_DIR /usr/local/lib)

include_directories(${INC_DIR})
link_directories(${LINK_DIR})
link_libraries(zmq)

add_executable(zeromq_practice main.c
    zmq_version.c
    zmq_req_client.c
    zmq_rep_server.c
    zmq_pub_server.c
    zmq_sub_client.c
    zmq_push_server.c
    zmq_pull_client.c
        zmq_inproc.c)

target_link_libraries(zeromq_practice zmq)
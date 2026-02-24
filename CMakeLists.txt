cmake_minimum_required(VERSION 4.1)
project(Reactor_Core C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Reactor_Core test/bbTest_core.c
        engine/threadsafe/bbThreadedQueue_search.c
        engine/threadsafe/bbThreadedQueue.c
        engine/threadsafe/bbThreadedPool.c
        engine/logic/bbTree.c
        engine/logic/bbList_sort.c
        engine/logic/bbList_iterate.c
        engine/logic/bbList_getNth.c
        engine/logic/bbList.c
        engine/logic/bbDictionary.c
        engine/logic/bbBloatedPool.c)

target_include_directories(Reactor_Core  PRIVATE "./")


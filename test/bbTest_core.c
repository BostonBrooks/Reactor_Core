#include <stdio.h>
#include <pthread.h>
#include "engine/core/bbCore.h"


U64 test_time = 193;
thread_local char* thread;

int main(void)
{
    bbCore core;

    bbCore_init(&core);

    bbHere()
}
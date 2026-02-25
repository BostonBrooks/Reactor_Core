#include <stdio.h>
#include <pthread.h>
#include "engine/core/bbCore.h"
#include "engine/core/bbCoreInputs.h"
#include "engine/data/bbConstants.h"
#include "engine/data/bbData.h"
#include "engine/logic/bbString.h"
#include "engine/core/bbInstruction.h"
#include "engine/core/bbAction.h"

thread_local char* thread;

int main(void)
{
    bbCore core;

    bbCore_init(&core);

    bbStr_putStr(test_string, "Abera Kedabera",KEY_LENGTH);

    U32 collision = 0;

    for (I32 i = 1; i < 9;i++)
    {
        bbCoreInput_setTime(&core, i, bbInstructionSource_input, no_handle);
        bbCore_react(&core);

        char str[KEY_LENGTH];
        sprintf(str, "i = %d", i);

        //bbCoreInput_setString(&core, str, bbInstructionSource_input, no_handle);
        //bbCore_react(&core);


        sprintf(str, "~i = %d", i+3);

        bbAction_setString(&core,
                         0,
                         collision++,
                         i,
                         i+3,
                         str);


        bbCoreInput_checkActions(&core,i,bbInstructionSource_input, no_handle);
        bbCore_react(&core);
    }



    bbCore_rewind(&core);
    bbCore_react(&core);

    bbHere()
}
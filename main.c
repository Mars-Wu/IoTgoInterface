#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "std_stream.h"
#include "wormhole.h"

const StdStream *pair_stream = NULL;
const StdStream *boot_svr_stream = NULL;
const StdStream *opr_svr_stream = NULL;
const StdStream *ota_svr_stream = NULL;

void main(void)
{
    uint8 buf[16];
    printf("main finished!\n");
}


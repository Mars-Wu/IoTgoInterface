#include "std_stream.h"

const StdStream *pair_stream = NULL;
const StdStream *boot_svr_stream = NULL;
const StdStream *opr_svr_stream = NULL;
const StdStream *ota_svr_stream = NULL;

void main(void)
{
    ...
    pair_stream = strmGetPairStream();

    ...
    
    boot_svr_stream = strmGetBootSvrStream(boot_ip, boot_port);

    ...

    opr_svr_stream = strmGetOprSvrStream(opr_ip, opr_port);

    ...

    ota_svr_stream = strmGetOtaSvrStream(ota_ip, ota_port);

    ...
    
}


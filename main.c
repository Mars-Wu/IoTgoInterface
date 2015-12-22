#include "std_stream.h"

const StdStream *pair_stream = NULL;
const StdStream *boot_svr_stream = NULL;
const StdStream *opr_svr_stream = NULL;
const StdStream *ota_svr_stream = NULL;

void main(void)
{
    uint8 buf[16];
    
    ...
    
    pair_stream = strmGetPairStream();
    pair_stream->open();
    pair_stream->state();
    pair_stream->write(buf, sizeof(buf));
    pair_stream->read(buf, pair_stream->available());
    pair_stream->close();
    
    ...
    
    boot_svr_stream = strmGetBootSvrStream(boot_ip, boot_port);

    ...

    opr_svr_stream = strmGetOprSvrStream(opr_ip, opr_port);

    ...

    opr_svr_stream->close();
    opr_svr_stream = strmGetOprSvrStream(opr2_ip, opr2_port);

    ...
    
    ota_svr_stream = strmGetOtaSvrStream(ota_ip, ota_port);

    ...
    
}


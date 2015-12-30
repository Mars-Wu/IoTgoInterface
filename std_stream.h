#ifndef __STD_STREAM_H__
#define __STD_STREAM_H__

typedef signed int int32;
typedef unsigned int uint32;
typedef unsigned char uint8;

typedef enum 
{
    STD_STREAM_STATE_READY      = 1,    /**< Closed and can be open */
    STD_STREAM_STATE_BUSY       = 2,    /**< Opened and busy(write/read can NOT be called) */
    STD_STREAM_STATE_IDLE       = 3,    /**< Opened and idle(write/read can be called) */
    STD_STREAM_STATE_INVALID    = 100   /**< Error occurs */
} StdStreamState;

typedef enum 
{
    STD_STREAM_TYPE_CLIENT      = 1, 
    STD_STREAM_TYPE_SERVER      = 2,
    STD_STREAM_TYPE_P2P         = 3,
    STD_STREAM_TYPE_INVALID     = 100,
} StdStreamType;

typedef enum 
{
    STD_STREAM_ERROR_NONE       = 0,
    
} StdStreamError;

typedef struct 
{
    StdStreamType type;
    uint32 ip;
    uint32 port;
} StdStreamParam;

typedef struct StdStream StdStream;

const StdStream * ssCreateStdStream(void);
void ssReleaseStdStream(const StdStream *obj);
StdStreamError ssSetParam(const StdStream *obj, StdStreamParam param);
StdStreamParam ssGetParam(const StdStream *obj);
StdStreamState ssGetState(const StdStream *obj);
StdStreamError ssOpen(const StdStream *obj); 
StdStreamError ssClose(const StdStream *obj); 
int32 ssWrite(const StdStream *obj, const uint8 *buf, int32 len); 
int32 ssAvailable(const StdStream *obj);
int32 ssRead(const StdStream *obj, uint8 *buf, int32 len); 

#endif /* #ifndef __STD_STREAM_H__ */

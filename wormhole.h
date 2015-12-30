#ifndef __WORMHOLE_H__
#define __WORMHOLE_H__

typedef enum 
{
    WORM_ID_SIZE                = 10 + 1,
    WORM_TOKEN_SIZE             = 36 + 1,
} WormConstant;

typedef enum 
{
    WORM_ERROR_NONE = 0,
} WormError;

typedef struct 
{
    char id[WORM_ID_SIZE];
    char token[WORM_TOKEN_SIZE];
} WormInfo;

typedef struct 
{
    WormInfo wi;
} WormParam;

typedef enum 
{
    WORMHOLE_STATE_READY      = 1,    /**< Closed and can be open */
    WORMHOLE_STATE_BUSY       = 2,    /**< Opened and busy(write/read can NOT be called) */
    WORMHOLE_STATE_IDLE       = 3,    /**< Opened and idle(write/read can be called) */
    WORMHOLE_STATE_INVALID    = 100   /**< Error occurs */
} WormholeState;

typedef struct Wormhole Wormhole;

const Wormhole * whCreateWormhole(void);
void whReleaseWormhole(const Wormhole *obj);

WormInfo whSetParam(const Wormhole *obj, WormParam wp);
WormParam whGetParam(const Wormhole *obj);

WormError whPair(const Wormhole *obj);

WormError whOpen(const Wormhole *obj);
WormError whClose(const Wormhole *obj);

WormholeState whGetState(const Wormhole *obj);

int32 whWrite(const Wormhole *obj, const uint8 *buf, int32 len); 
int32 whAvailable(const Wormhole *obj);
int32 whRead(const Wormhole *obj, uint8 *buf, int32 len); 



#endif /* #ifndef __WORMHOLE_H__ */


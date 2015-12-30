#ifndef __WORMHOLE_H__
#define __WORMHOLE_H__

typedef enum {
    WORM_ID_SIZE                = 10 + 1,
    WORM_TOKEN_SIZE             = 36 + 1,
} WormConstant;

typedef enum {
    WORM_ERROR_NONE = 0,
} WormError;

typedef struct {
    char id[WORM_ID_SIZE];
    char token[WORM_TOKEN_SIZE];
} WormInfo;

WormInfo wormLaunch(WormInfo worm_info);

WormError whPair(void);


#endif /* #ifndef __WORMHOLE_H__ */


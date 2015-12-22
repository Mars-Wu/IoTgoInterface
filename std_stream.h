/**
 * @file std_stream.h
 * @brief The definition of StdStream Interface. 
 */

typedef platform_bool bool;
typedef platform_int32 int32;
typedef platform_uint32 uint32;
typedef platform_uint8 uint8;

#ifndef false
#define false (1)
#endif

#ifndef true
#define true (0)
#endif

typedef enum 
{
    STD_STREAM_STATE_IDLE   = 0,
    STD_STREAM_STATE_OPENED ,
    STD_STREAM_STATE_CLOSED ,
    STD_STREAM_STATE_INVALID
} StdStreamState;

/**
 * @brief StdStream Interface
 */
typedef struct 
{
    /**
     * @brief Init something necessary. 
     * @retrun true or false. 
     */
    bool (*open)(void); 

    /**
     * @brief Indicates if read and write can be called. 
     * @retrun the state of stream. 
     */
    StdStreamState (*state)(void);

    /**
     * @brief Write data to stream. 
     * @param buf - the started pointer of data to write. 
     * @param len - the length of data. 
     * @retval not less than 0 - the number of bytes written successuffly. 
     * @retval others - return with error. 
     * @warning the content of buf MUST NOT be changed in this call. 
     */
    int32 (*write)(const uint8 *buf, int32 len); 

    /**
     * @brief Get the number of data unread in stream. 
     * @retval not less than 0 - the number of data unread in stream. 
     * @retval others - return with error. 
     */
    int32 (*available)(void);    

    /**
     * @brief Read data to buffer from stream. 
     * @param buf - the started pointer for saving data. 
     * @param len - the length to read. 
     * @retval not less than 0 - the number of bytes read actually. 
     * @retval others - return with error(the content of buf is unexpectable in this case). 
     */
    int32 (*read)(uint8 *buf, int32 len); 

    /**
     * Deinit things necessary. 
     */
    void (*close)(void); 
} StdStream;


/**
 * @brief Get the single object of Pair Stream. 
 * @return the pointer for success, NULL for failure. 
 */
const StdStream * strmGetPairStream(void);

/**
 * @brief Get the single object of Bootstrap Server Stream. 
 * @param ip - the ip address of target host. 
 * @param port - the port of target host. 
 * @return the pointer for success, NULL for failure. 
 */
const StdStream * strmGetBootSvrStream(uint32 ip, uint32 port);

/**
 * @brief Get the single object of Operation Server Stream. 
 * @param ip - the ip address of target host. 
 * @param port - the port of target host.  
 * @return the pointer for success, NULL for failure. 
 */
const StdStream * strmGetOprSvrStream(uint32 ip, uint32 port);

/**
 * @brief Get the single object of OTA Server Stream. 
 * @param ip - the ip address of target host. 
 * @param port - the port of target host. 
 * @return the pointer for success, NULL for failure. 
 */
const StdStream * strmGetOtaSvrStream(uint32 ip, uint32 port);


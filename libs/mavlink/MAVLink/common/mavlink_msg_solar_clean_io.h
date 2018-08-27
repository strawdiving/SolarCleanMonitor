#pragma once
// MESSAGE SOLAR_CLEAN_IO PACKING

#define MAVLINK_MSG_ID_SOLAR_CLEAN_IO 184

MAVPACKED(
typedef struct __mavlink_solar_clean_io_t {
 uint8_t PLC_DI; /*< PLC digital input */
 uint8_t PLC_DO; /*< PLC digital output*/
}) mavlink_solar_clean_io_t;

#define MAVLINK_MSG_ID_SOLAR_CLEAN_IO_LEN 2
#define MAVLINK_MSG_ID_SOLAR_CLEAN_IO_MIN_LEN 2
#define MAVLINK_MSG_ID_184_LEN 2
#define MAVLINK_MSG_ID_184_MIN_LEN 2

#define MAVLINK_MSG_ID_SOLAR_CLEAN_IO_CRC 214
#define MAVLINK_MSG_ID_184_CRC 214



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SOLAR_CLEAN_IO { \
    184, \
    "SOLAR_CLEAN_IO", \
    2, \
    {  { "PLC_DI", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_solar_clean_io_t, PLC_DI) }, \
         { "PLC_DO", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_solar_clean_io_t, PLC_DO) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SOLAR_CLEAN_IO { \
    "SOLAR_CLEAN_IO", \
    2, \
    {  { "PLC_DI", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_solar_clean_io_t, PLC_DI) }, \
         { "PLC_DO", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_solar_clean_io_t, PLC_DO) }, \
         } \
}
#endif

/**
 * @brief Pack a solar_clean_io message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param PLC_DI PLC digital input 
 * @param PLC_DO PLC digital output
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_solar_clean_io_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t PLC_DI, uint8_t PLC_DO)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SOLAR_CLEAN_IO_LEN];
    _mav_put_uint8_t(buf, 0, PLC_DI);
    _mav_put_uint8_t(buf, 1, PLC_DO);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SOLAR_CLEAN_IO_LEN);
#else
    mavlink_solar_clean_io_t packet;
    packet.PLC_DI = PLC_DI;
    packet.PLC_DO = PLC_DO;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SOLAR_CLEAN_IO_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SOLAR_CLEAN_IO;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SOLAR_CLEAN_IO_MIN_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_IO_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_IO_CRC);
}

/**
 * @brief Pack a solar_clean_io message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param PLC_DI PLC digital input 
 * @param PLC_DO PLC digital output
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_solar_clean_io_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t PLC_DI,uint8_t PLC_DO)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SOLAR_CLEAN_IO_LEN];
    _mav_put_uint8_t(buf, 0, PLC_DI);
    _mav_put_uint8_t(buf, 1, PLC_DO);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SOLAR_CLEAN_IO_LEN);
#else
    mavlink_solar_clean_io_t packet;
    packet.PLC_DI = PLC_DI;
    packet.PLC_DO = PLC_DO;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SOLAR_CLEAN_IO_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SOLAR_CLEAN_IO;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SOLAR_CLEAN_IO_MIN_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_IO_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_IO_CRC);
}

/**
 * @brief Encode a solar_clean_io struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param solar_clean_io C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_solar_clean_io_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_solar_clean_io_t* solar_clean_io)
{
    return mavlink_msg_solar_clean_io_pack(system_id, component_id, msg, solar_clean_io->PLC_DI, solar_clean_io->PLC_DO);
}

/**
 * @brief Encode a solar_clean_io struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param solar_clean_io C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_solar_clean_io_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_solar_clean_io_t* solar_clean_io)
{
    return mavlink_msg_solar_clean_io_pack_chan(system_id, component_id, chan, msg, solar_clean_io->PLC_DI, solar_clean_io->PLC_DO);
}

/**
 * @brief Send a solar_clean_io message
 * @param chan MAVLink channel to send the message
 *
 * @param PLC_DI PLC digital input 
 * @param PLC_DO PLC digital output
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_solar_clean_io_send(mavlink_channel_t chan, uint8_t PLC_DI, uint8_t PLC_DO)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SOLAR_CLEAN_IO_LEN];
    _mav_put_uint8_t(buf, 0, PLC_DI);
    _mav_put_uint8_t(buf, 1, PLC_DO);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SOLAR_CLEAN_IO, buf, MAVLINK_MSG_ID_SOLAR_CLEAN_IO_MIN_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_IO_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_IO_CRC);
#else
    mavlink_solar_clean_io_t packet;
    packet.PLC_DI = PLC_DI;
    packet.PLC_DO = PLC_DO;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SOLAR_CLEAN_IO, (const char *)&packet, MAVLINK_MSG_ID_SOLAR_CLEAN_IO_MIN_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_IO_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_IO_CRC);
#endif
}

/**
 * @brief Send a solar_clean_io message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_solar_clean_io_send_struct(mavlink_channel_t chan, const mavlink_solar_clean_io_t* solar_clean_io)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_solar_clean_io_send(chan, solar_clean_io->PLC_DI, solar_clean_io->PLC_DO);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SOLAR_CLEAN_IO, (const char *)solar_clean_io, MAVLINK_MSG_ID_SOLAR_CLEAN_IO_MIN_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_IO_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_IO_CRC);
#endif
}

#if MAVLINK_MSG_ID_SOLAR_CLEAN_IO_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_solar_clean_io_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t PLC_DI, uint8_t PLC_DO)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, PLC_DI);
    _mav_put_uint8_t(buf, 1, PLC_DO);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SOLAR_CLEAN_IO, buf, MAVLINK_MSG_ID_SOLAR_CLEAN_IO_MIN_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_IO_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_IO_CRC);
#else
    mavlink_solar_clean_io_t *packet = (mavlink_solar_clean_io_t *)msgbuf;
    packet->PLC_DI = PLC_DI;
    packet->PLC_DO = PLC_DO;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SOLAR_CLEAN_IO, (const char *)packet, MAVLINK_MSG_ID_SOLAR_CLEAN_IO_MIN_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_IO_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_IO_CRC);
#endif
}
#endif

#endif

// MESSAGE SOLAR_CLEAN_IO UNPACKING


/**
 * @brief Get field PLC_DI from solar_clean_io message
 *
 * @return PLC digital input 
 */
static inline uint8_t mavlink_msg_solar_clean_io_get_PLC_DI(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field PLC_DO from solar_clean_io message
 *
 * @return PLC digital output
 */
static inline uint8_t mavlink_msg_solar_clean_io_get_PLC_DO(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Decode a solar_clean_io message into a struct
 *
 * @param msg The message to decode
 * @param solar_clean_io C-struct to decode the message contents into
 */
static inline void mavlink_msg_solar_clean_io_decode(const mavlink_message_t* msg, mavlink_solar_clean_io_t* solar_clean_io)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    solar_clean_io->PLC_DI = mavlink_msg_solar_clean_io_get_PLC_DI(msg);
    solar_clean_io->PLC_DO = mavlink_msg_solar_clean_io_get_PLC_DO(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_SOLAR_CLEAN_IO_LEN? msg->len : MAVLINK_MSG_ID_SOLAR_CLEAN_IO_LEN;
        memset(solar_clean_io, 0, MAVLINK_MSG_ID_SOLAR_CLEAN_IO_LEN);
    memcpy(solar_clean_io, _MAV_PAYLOAD(msg), len);
#endif
}

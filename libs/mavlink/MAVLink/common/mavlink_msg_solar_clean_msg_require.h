#pragma once
// MESSAGE SOLAR_CLEAN_MSG_REQUIRE PACKING

#define MAVLINK_MSG_ID_SOLAR_CLEAN_MSG_REQUIRE 186

MAVPACKED(
typedef struct __mavlink_solar_clean_msg_require_t {
 uint8_t message_id_require; /*< the message id require */
}) mavlink_solar_clean_msg_require_t;

#define MAVLINK_MSG_ID_SOLAR_CLEAN_MSG_REQUIRE_LEN 1
#define MAVLINK_MSG_ID_SOLAR_CLEAN_MSG_REQUIRE_MIN_LEN 1
#define MAVLINK_MSG_ID_186_LEN 1
#define MAVLINK_MSG_ID_186_MIN_LEN 1

#define MAVLINK_MSG_ID_SOLAR_CLEAN_MSG_REQUIRE_CRC 171
#define MAVLINK_MSG_ID_186_CRC 171



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SOLAR_CLEAN_MSG_REQUIRE { \
    186, \
    "SOLAR_CLEAN_MSG_REQUIRE", \
    1, \
    {  { "message_id_require", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_solar_clean_msg_require_t, message_id_require) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SOLAR_CLEAN_MSG_REQUIRE { \
    "SOLAR_CLEAN_MSG_REQUIRE", \
    1, \
    {  { "message_id_require", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_solar_clean_msg_require_t, message_id_require) }, \
         } \
}
#endif

/**
 * @brief Pack a solar_clean_msg_require message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param message_id_require the message id require 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_solar_clean_msg_require_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t message_id_require)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SOLAR_CLEAN_MSG_REQUIRE_LEN];
    _mav_put_uint8_t(buf, 0, message_id_require);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SOLAR_CLEAN_MSG_REQUIRE_LEN);
#else
    mavlink_solar_clean_msg_require_t packet;
    packet.message_id_require = message_id_require;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SOLAR_CLEAN_MSG_REQUIRE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SOLAR_CLEAN_MSG_REQUIRE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SOLAR_CLEAN_MSG_REQUIRE_MIN_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_MSG_REQUIRE_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_MSG_REQUIRE_CRC);
}

/**
 * @brief Pack a solar_clean_msg_require message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param message_id_require the message id require 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_solar_clean_msg_require_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t message_id_require)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SOLAR_CLEAN_MSG_REQUIRE_LEN];
    _mav_put_uint8_t(buf, 0, message_id_require);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SOLAR_CLEAN_MSG_REQUIRE_LEN);
#else
    mavlink_solar_clean_msg_require_t packet;
    packet.message_id_require = message_id_require;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SOLAR_CLEAN_MSG_REQUIRE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SOLAR_CLEAN_MSG_REQUIRE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SOLAR_CLEAN_MSG_REQUIRE_MIN_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_MSG_REQUIRE_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_MSG_REQUIRE_CRC);
}

/**
 * @brief Encode a solar_clean_msg_require struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param solar_clean_msg_require C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_solar_clean_msg_require_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_solar_clean_msg_require_t* solar_clean_msg_require)
{
    return mavlink_msg_solar_clean_msg_require_pack(system_id, component_id, msg, solar_clean_msg_require->message_id_require);
}

/**
 * @brief Encode a solar_clean_msg_require struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param solar_clean_msg_require C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_solar_clean_msg_require_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_solar_clean_msg_require_t* solar_clean_msg_require)
{
    return mavlink_msg_solar_clean_msg_require_pack_chan(system_id, component_id, chan, msg, solar_clean_msg_require->message_id_require);
}

/**
 * @brief Send a solar_clean_msg_require message
 * @param chan MAVLink channel to send the message
 *
 * @param message_id_require the message id require 
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_solar_clean_msg_require_send(mavlink_channel_t chan, uint8_t message_id_require)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SOLAR_CLEAN_MSG_REQUIRE_LEN];
    _mav_put_uint8_t(buf, 0, message_id_require);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SOLAR_CLEAN_MSG_REQUIRE, buf, MAVLINK_MSG_ID_SOLAR_CLEAN_MSG_REQUIRE_MIN_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_MSG_REQUIRE_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_MSG_REQUIRE_CRC);
#else
    mavlink_solar_clean_msg_require_t packet;
    packet.message_id_require = message_id_require;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SOLAR_CLEAN_MSG_REQUIRE, (const char *)&packet, MAVLINK_MSG_ID_SOLAR_CLEAN_MSG_REQUIRE_MIN_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_MSG_REQUIRE_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_MSG_REQUIRE_CRC);
#endif
}

/**
 * @brief Send a solar_clean_msg_require message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_solar_clean_msg_require_send_struct(mavlink_channel_t chan, const mavlink_solar_clean_msg_require_t* solar_clean_msg_require)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_solar_clean_msg_require_send(chan, solar_clean_msg_require->message_id_require);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SOLAR_CLEAN_MSG_REQUIRE, (const char *)solar_clean_msg_require, MAVLINK_MSG_ID_SOLAR_CLEAN_MSG_REQUIRE_MIN_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_MSG_REQUIRE_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_MSG_REQUIRE_CRC);
#endif
}

#if MAVLINK_MSG_ID_SOLAR_CLEAN_MSG_REQUIRE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_solar_clean_msg_require_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t message_id_require)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, message_id_require);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SOLAR_CLEAN_MSG_REQUIRE, buf, MAVLINK_MSG_ID_SOLAR_CLEAN_MSG_REQUIRE_MIN_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_MSG_REQUIRE_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_MSG_REQUIRE_CRC);
#else
    mavlink_solar_clean_msg_require_t *packet = (mavlink_solar_clean_msg_require_t *)msgbuf;
    packet->message_id_require = message_id_require;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SOLAR_CLEAN_MSG_REQUIRE, (const char *)packet, MAVLINK_MSG_ID_SOLAR_CLEAN_MSG_REQUIRE_MIN_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_MSG_REQUIRE_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_MSG_REQUIRE_CRC);
#endif
}
#endif

#endif

// MESSAGE SOLAR_CLEAN_MSG_REQUIRE UNPACKING


/**
 * @brief Get field message_id_require from solar_clean_msg_require message
 *
 * @return the message id require 
 */
static inline uint8_t mavlink_msg_solar_clean_msg_require_get_message_id_require(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Decode a solar_clean_msg_require message into a struct
 *
 * @param msg The message to decode
 * @param solar_clean_msg_require C-struct to decode the message contents into
 */
static inline void mavlink_msg_solar_clean_msg_require_decode(const mavlink_message_t* msg, mavlink_solar_clean_msg_require_t* solar_clean_msg_require)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    solar_clean_msg_require->message_id_require = mavlink_msg_solar_clean_msg_require_get_message_id_require(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_SOLAR_CLEAN_MSG_REQUIRE_LEN? msg->len : MAVLINK_MSG_ID_SOLAR_CLEAN_MSG_REQUIRE_LEN;
        memset(solar_clean_msg_require, 0, MAVLINK_MSG_ID_SOLAR_CLEAN_MSG_REQUIRE_LEN);
    memcpy(solar_clean_msg_require, _MAV_PAYLOAD(msg), len);
#endif
}

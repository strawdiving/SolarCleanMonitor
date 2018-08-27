#pragma once
// MESSAGE SOLAR_CLEAN_PARAMATER PACKING

#define MAVLINK_MSG_ID_SOLAR_CLEAN_PARAMATER 185

MAVPACKED(
typedef struct __mavlink_solar_clean_paramater_t {
 uint32_t heartbeat_cycle; /*< set the heartbeat cycle time of the solar machine,unit:ms*/
 uint16_t length_of_working_panel; /*< set the length of the working panel(uint:cm)*/
 uint16_t width_of_solar_clean; /*< set the width of the solar machine*/
}) mavlink_solar_clean_paramater_t;

#define MAVLINK_MSG_ID_SOLAR_CLEAN_PARAMATER_LEN 8
#define MAVLINK_MSG_ID_SOLAR_CLEAN_PARAMATER_MIN_LEN 8
#define MAVLINK_MSG_ID_185_LEN 8
#define MAVLINK_MSG_ID_185_MIN_LEN 8

#define MAVLINK_MSG_ID_SOLAR_CLEAN_PARAMATER_CRC 228
#define MAVLINK_MSG_ID_185_CRC 228



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SOLAR_CLEAN_PARAMATER { \
    185, \
    "SOLAR_CLEAN_PARAMATER", \
    3, \
    {  { "heartbeat_cycle", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_solar_clean_paramater_t, heartbeat_cycle) }, \
         { "length_of_working_panel", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_solar_clean_paramater_t, length_of_working_panel) }, \
         { "width_of_solar_clean", NULL, MAVLINK_TYPE_UINT16_T, 0, 6, offsetof(mavlink_solar_clean_paramater_t, width_of_solar_clean) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SOLAR_CLEAN_PARAMATER { \
    "SOLAR_CLEAN_PARAMATER", \
    3, \
    {  { "heartbeat_cycle", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_solar_clean_paramater_t, heartbeat_cycle) }, \
         { "length_of_working_panel", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_solar_clean_paramater_t, length_of_working_panel) }, \
         { "width_of_solar_clean", NULL, MAVLINK_TYPE_UINT16_T, 0, 6, offsetof(mavlink_solar_clean_paramater_t, width_of_solar_clean) }, \
         } \
}
#endif

/**
 * @brief Pack a solar_clean_paramater message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param length_of_working_panel set the length of the working panel(uint:cm)
 * @param width_of_solar_clean set the width of the solar machine
 * @param heartbeat_cycle set the heartbeat cycle time of the solar machine,unit:ms
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_solar_clean_paramater_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint16_t length_of_working_panel, uint16_t width_of_solar_clean, uint32_t heartbeat_cycle)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SOLAR_CLEAN_PARAMATER_LEN];
    _mav_put_uint32_t(buf, 0, heartbeat_cycle);
    _mav_put_uint16_t(buf, 4, length_of_working_panel);
    _mav_put_uint16_t(buf, 6, width_of_solar_clean);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SOLAR_CLEAN_PARAMATER_LEN);
#else
    mavlink_solar_clean_paramater_t packet;
    packet.heartbeat_cycle = heartbeat_cycle;
    packet.length_of_working_panel = length_of_working_panel;
    packet.width_of_solar_clean = width_of_solar_clean;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SOLAR_CLEAN_PARAMATER_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SOLAR_CLEAN_PARAMATER;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SOLAR_CLEAN_PARAMATER_MIN_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_PARAMATER_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_PARAMATER_CRC);
}

/**
 * @brief Pack a solar_clean_paramater message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param length_of_working_panel set the length of the working panel(uint:cm)
 * @param width_of_solar_clean set the width of the solar machine
 * @param heartbeat_cycle set the heartbeat cycle time of the solar machine,unit:ms
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_solar_clean_paramater_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint16_t length_of_working_panel,uint16_t width_of_solar_clean,uint32_t heartbeat_cycle)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SOLAR_CLEAN_PARAMATER_LEN];
    _mav_put_uint32_t(buf, 0, heartbeat_cycle);
    _mav_put_uint16_t(buf, 4, length_of_working_panel);
    _mav_put_uint16_t(buf, 6, width_of_solar_clean);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SOLAR_CLEAN_PARAMATER_LEN);
#else
    mavlink_solar_clean_paramater_t packet;
    packet.heartbeat_cycle = heartbeat_cycle;
    packet.length_of_working_panel = length_of_working_panel;
    packet.width_of_solar_clean = width_of_solar_clean;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SOLAR_CLEAN_PARAMATER_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SOLAR_CLEAN_PARAMATER;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SOLAR_CLEAN_PARAMATER_MIN_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_PARAMATER_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_PARAMATER_CRC);
}

/**
 * @brief Encode a solar_clean_paramater struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param solar_clean_paramater C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_solar_clean_paramater_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_solar_clean_paramater_t* solar_clean_paramater)
{
    return mavlink_msg_solar_clean_paramater_pack(system_id, component_id, msg, solar_clean_paramater->length_of_working_panel, solar_clean_paramater->width_of_solar_clean, solar_clean_paramater->heartbeat_cycle);
}

/**
 * @brief Encode a solar_clean_paramater struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param solar_clean_paramater C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_solar_clean_paramater_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_solar_clean_paramater_t* solar_clean_paramater)
{
    return mavlink_msg_solar_clean_paramater_pack_chan(system_id, component_id, chan, msg, solar_clean_paramater->length_of_working_panel, solar_clean_paramater->width_of_solar_clean, solar_clean_paramater->heartbeat_cycle);
}

/**
 * @brief Send a solar_clean_paramater message
 * @param chan MAVLink channel to send the message
 *
 * @param length_of_working_panel set the length of the working panel(uint:cm)
 * @param width_of_solar_clean set the width of the solar machine
 * @param heartbeat_cycle set the heartbeat cycle time of the solar machine,unit:ms
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_solar_clean_paramater_send(mavlink_channel_t chan, uint16_t length_of_working_panel, uint16_t width_of_solar_clean, uint32_t heartbeat_cycle)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SOLAR_CLEAN_PARAMATER_LEN];
    _mav_put_uint32_t(buf, 0, heartbeat_cycle);
    _mav_put_uint16_t(buf, 4, length_of_working_panel);
    _mav_put_uint16_t(buf, 6, width_of_solar_clean);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SOLAR_CLEAN_PARAMATER, buf, MAVLINK_MSG_ID_SOLAR_CLEAN_PARAMATER_MIN_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_PARAMATER_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_PARAMATER_CRC);
#else
    mavlink_solar_clean_paramater_t packet;
    packet.heartbeat_cycle = heartbeat_cycle;
    packet.length_of_working_panel = length_of_working_panel;
    packet.width_of_solar_clean = width_of_solar_clean;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SOLAR_CLEAN_PARAMATER, (const char *)&packet, MAVLINK_MSG_ID_SOLAR_CLEAN_PARAMATER_MIN_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_PARAMATER_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_PARAMATER_CRC);
#endif
}

/**
 * @brief Send a solar_clean_paramater message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_solar_clean_paramater_send_struct(mavlink_channel_t chan, const mavlink_solar_clean_paramater_t* solar_clean_paramater)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_solar_clean_paramater_send(chan, solar_clean_paramater->length_of_working_panel, solar_clean_paramater->width_of_solar_clean, solar_clean_paramater->heartbeat_cycle);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SOLAR_CLEAN_PARAMATER, (const char *)solar_clean_paramater, MAVLINK_MSG_ID_SOLAR_CLEAN_PARAMATER_MIN_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_PARAMATER_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_PARAMATER_CRC);
#endif
}

#if MAVLINK_MSG_ID_SOLAR_CLEAN_PARAMATER_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_solar_clean_paramater_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint16_t length_of_working_panel, uint16_t width_of_solar_clean, uint32_t heartbeat_cycle)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, heartbeat_cycle);
    _mav_put_uint16_t(buf, 4, length_of_working_panel);
    _mav_put_uint16_t(buf, 6, width_of_solar_clean);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SOLAR_CLEAN_PARAMATER, buf, MAVLINK_MSG_ID_SOLAR_CLEAN_PARAMATER_MIN_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_PARAMATER_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_PARAMATER_CRC);
#else
    mavlink_solar_clean_paramater_t *packet = (mavlink_solar_clean_paramater_t *)msgbuf;
    packet->heartbeat_cycle = heartbeat_cycle;
    packet->length_of_working_panel = length_of_working_panel;
    packet->width_of_solar_clean = width_of_solar_clean;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SOLAR_CLEAN_PARAMATER, (const char *)packet, MAVLINK_MSG_ID_SOLAR_CLEAN_PARAMATER_MIN_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_PARAMATER_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_PARAMATER_CRC);
#endif
}
#endif

#endif

// MESSAGE SOLAR_CLEAN_PARAMATER UNPACKING


/**
 * @brief Get field length_of_working_panel from solar_clean_paramater message
 *
 * @return set the length of the working panel(uint:cm)
 */
static inline uint16_t mavlink_msg_solar_clean_paramater_get_length_of_working_panel(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  4);
}

/**
 * @brief Get field width_of_solar_clean from solar_clean_paramater message
 *
 * @return set the width of the solar machine
 */
static inline uint16_t mavlink_msg_solar_clean_paramater_get_width_of_solar_clean(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  6);
}

/**
 * @brief Get field heartbeat_cycle from solar_clean_paramater message
 *
 * @return set the heartbeat cycle time of the solar machine,unit:ms
 */
static inline uint32_t mavlink_msg_solar_clean_paramater_get_heartbeat_cycle(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Decode a solar_clean_paramater message into a struct
 *
 * @param msg The message to decode
 * @param solar_clean_paramater C-struct to decode the message contents into
 */
static inline void mavlink_msg_solar_clean_paramater_decode(const mavlink_message_t* msg, mavlink_solar_clean_paramater_t* solar_clean_paramater)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    solar_clean_paramater->heartbeat_cycle = mavlink_msg_solar_clean_paramater_get_heartbeat_cycle(msg);
    solar_clean_paramater->length_of_working_panel = mavlink_msg_solar_clean_paramater_get_length_of_working_panel(msg);
    solar_clean_paramater->width_of_solar_clean = mavlink_msg_solar_clean_paramater_get_width_of_solar_clean(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_SOLAR_CLEAN_PARAMATER_LEN? msg->len : MAVLINK_MSG_ID_SOLAR_CLEAN_PARAMATER_LEN;
        memset(solar_clean_paramater, 0, MAVLINK_MSG_ID_SOLAR_CLEAN_PARAMATER_LEN);
    memcpy(solar_clean_paramater, _MAV_PAYLOAD(msg), len);
#endif
}

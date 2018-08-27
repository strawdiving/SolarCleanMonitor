#pragma once
// MESSAGE SOLAR_CLEAN_TEMPERATURE_CHANNEL_SELECT PACKING

#define MAVLINK_MSG_ID_SOLAR_CLEAN_TEMPERATURE_CHANNEL_SELECT 187

MAVPACKED(
typedef struct __mavlink_solar_clean_temperature_channel_select_t {
 uint32_t number_of_temperature; /*<  set the bit to 1 enable the channel*/
}) mavlink_solar_clean_temperature_channel_select_t;

#define MAVLINK_MSG_ID_SOLAR_CLEAN_TEMPERATURE_CHANNEL_SELECT_LEN 4
#define MAVLINK_MSG_ID_SOLAR_CLEAN_TEMPERATURE_CHANNEL_SELECT_MIN_LEN 4
#define MAVLINK_MSG_ID_187_LEN 4
#define MAVLINK_MSG_ID_187_MIN_LEN 4

#define MAVLINK_MSG_ID_SOLAR_CLEAN_TEMPERATURE_CHANNEL_SELECT_CRC 93
#define MAVLINK_MSG_ID_187_CRC 93



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SOLAR_CLEAN_TEMPERATURE_CHANNEL_SELECT { \
    187, \
    "SOLAR_CLEAN_TEMPERATURE_CHANNEL_SELECT", \
    1, \
    {  { "number_of_temperature", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_solar_clean_temperature_channel_select_t, number_of_temperature) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SOLAR_CLEAN_TEMPERATURE_CHANNEL_SELECT { \
    "SOLAR_CLEAN_TEMPERATURE_CHANNEL_SELECT", \
    1, \
    {  { "number_of_temperature", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_solar_clean_temperature_channel_select_t, number_of_temperature) }, \
         } \
}
#endif

/**
 * @brief Pack a solar_clean_temperature_channel_select message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param number_of_temperature  set the bit to 1 enable the channel
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_solar_clean_temperature_channel_select_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t number_of_temperature)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SOLAR_CLEAN_TEMPERATURE_CHANNEL_SELECT_LEN];
    _mav_put_uint32_t(buf, 0, number_of_temperature);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SOLAR_CLEAN_TEMPERATURE_CHANNEL_SELECT_LEN);
#else
    mavlink_solar_clean_temperature_channel_select_t packet;
    packet.number_of_temperature = number_of_temperature;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SOLAR_CLEAN_TEMPERATURE_CHANNEL_SELECT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SOLAR_CLEAN_TEMPERATURE_CHANNEL_SELECT;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SOLAR_CLEAN_TEMPERATURE_CHANNEL_SELECT_MIN_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_TEMPERATURE_CHANNEL_SELECT_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_TEMPERATURE_CHANNEL_SELECT_CRC);
}

/**
 * @brief Pack a solar_clean_temperature_channel_select message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param number_of_temperature  set the bit to 1 enable the channel
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_solar_clean_temperature_channel_select_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t number_of_temperature)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SOLAR_CLEAN_TEMPERATURE_CHANNEL_SELECT_LEN];
    _mav_put_uint32_t(buf, 0, number_of_temperature);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SOLAR_CLEAN_TEMPERATURE_CHANNEL_SELECT_LEN);
#else
    mavlink_solar_clean_temperature_channel_select_t packet;
    packet.number_of_temperature = number_of_temperature;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SOLAR_CLEAN_TEMPERATURE_CHANNEL_SELECT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SOLAR_CLEAN_TEMPERATURE_CHANNEL_SELECT;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SOLAR_CLEAN_TEMPERATURE_CHANNEL_SELECT_MIN_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_TEMPERATURE_CHANNEL_SELECT_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_TEMPERATURE_CHANNEL_SELECT_CRC);
}

/**
 * @brief Encode a solar_clean_temperature_channel_select struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param solar_clean_temperature_channel_select C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_solar_clean_temperature_channel_select_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_solar_clean_temperature_channel_select_t* solar_clean_temperature_channel_select)
{
    return mavlink_msg_solar_clean_temperature_channel_select_pack(system_id, component_id, msg, solar_clean_temperature_channel_select->number_of_temperature);
}

/**
 * @brief Encode a solar_clean_temperature_channel_select struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param solar_clean_temperature_channel_select C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_solar_clean_temperature_channel_select_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_solar_clean_temperature_channel_select_t* solar_clean_temperature_channel_select)
{
    return mavlink_msg_solar_clean_temperature_channel_select_pack_chan(system_id, component_id, chan, msg, solar_clean_temperature_channel_select->number_of_temperature);
}

/**
 * @brief Send a solar_clean_temperature_channel_select message
 * @param chan MAVLink channel to send the message
 *
 * @param number_of_temperature  set the bit to 1 enable the channel
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_solar_clean_temperature_channel_select_send(mavlink_channel_t chan, uint32_t number_of_temperature)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SOLAR_CLEAN_TEMPERATURE_CHANNEL_SELECT_LEN];
    _mav_put_uint32_t(buf, 0, number_of_temperature);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SOLAR_CLEAN_TEMPERATURE_CHANNEL_SELECT, buf, MAVLINK_MSG_ID_SOLAR_CLEAN_TEMPERATURE_CHANNEL_SELECT_MIN_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_TEMPERATURE_CHANNEL_SELECT_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_TEMPERATURE_CHANNEL_SELECT_CRC);
#else
    mavlink_solar_clean_temperature_channel_select_t packet;
    packet.number_of_temperature = number_of_temperature;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SOLAR_CLEAN_TEMPERATURE_CHANNEL_SELECT, (const char *)&packet, MAVLINK_MSG_ID_SOLAR_CLEAN_TEMPERATURE_CHANNEL_SELECT_MIN_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_TEMPERATURE_CHANNEL_SELECT_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_TEMPERATURE_CHANNEL_SELECT_CRC);
#endif
}

/**
 * @brief Send a solar_clean_temperature_channel_select message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_solar_clean_temperature_channel_select_send_struct(mavlink_channel_t chan, const mavlink_solar_clean_temperature_channel_select_t* solar_clean_temperature_channel_select)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_solar_clean_temperature_channel_select_send(chan, solar_clean_temperature_channel_select->number_of_temperature);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SOLAR_CLEAN_TEMPERATURE_CHANNEL_SELECT, (const char *)solar_clean_temperature_channel_select, MAVLINK_MSG_ID_SOLAR_CLEAN_TEMPERATURE_CHANNEL_SELECT_MIN_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_TEMPERATURE_CHANNEL_SELECT_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_TEMPERATURE_CHANNEL_SELECT_CRC);
#endif
}

#if MAVLINK_MSG_ID_SOLAR_CLEAN_TEMPERATURE_CHANNEL_SELECT_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_solar_clean_temperature_channel_select_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t number_of_temperature)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, number_of_temperature);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SOLAR_CLEAN_TEMPERATURE_CHANNEL_SELECT, buf, MAVLINK_MSG_ID_SOLAR_CLEAN_TEMPERATURE_CHANNEL_SELECT_MIN_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_TEMPERATURE_CHANNEL_SELECT_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_TEMPERATURE_CHANNEL_SELECT_CRC);
#else
    mavlink_solar_clean_temperature_channel_select_t *packet = (mavlink_solar_clean_temperature_channel_select_t *)msgbuf;
    packet->number_of_temperature = number_of_temperature;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SOLAR_CLEAN_TEMPERATURE_CHANNEL_SELECT, (const char *)packet, MAVLINK_MSG_ID_SOLAR_CLEAN_TEMPERATURE_CHANNEL_SELECT_MIN_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_TEMPERATURE_CHANNEL_SELECT_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_TEMPERATURE_CHANNEL_SELECT_CRC);
#endif
}
#endif

#endif

// MESSAGE SOLAR_CLEAN_TEMPERATURE_CHANNEL_SELECT UNPACKING


/**
 * @brief Get field number_of_temperature from solar_clean_temperature_channel_select message
 *
 * @return  set the bit to 1 enable the channel
 */
static inline uint32_t mavlink_msg_solar_clean_temperature_channel_select_get_number_of_temperature(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Decode a solar_clean_temperature_channel_select message into a struct
 *
 * @param msg The message to decode
 * @param solar_clean_temperature_channel_select C-struct to decode the message contents into
 */
static inline void mavlink_msg_solar_clean_temperature_channel_select_decode(const mavlink_message_t* msg, mavlink_solar_clean_temperature_channel_select_t* solar_clean_temperature_channel_select)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    solar_clean_temperature_channel_select->number_of_temperature = mavlink_msg_solar_clean_temperature_channel_select_get_number_of_temperature(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_SOLAR_CLEAN_TEMPERATURE_CHANNEL_SELECT_LEN? msg->len : MAVLINK_MSG_ID_SOLAR_CLEAN_TEMPERATURE_CHANNEL_SELECT_LEN;
        memset(solar_clean_temperature_channel_select, 0, MAVLINK_MSG_ID_SOLAR_CLEAN_TEMPERATURE_CHANNEL_SELECT_LEN);
    memcpy(solar_clean_temperature_channel_select, _MAV_PAYLOAD(msg), len);
#endif
}

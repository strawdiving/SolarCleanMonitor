#pragma once
// MESSAGE SOLAR_CLEAN_TEMPERATURE PACKING

#define MAVLINK_MSG_ID_SOLAR_CLEAN_TEMPERATURE 182

MAVPACKED(
typedef struct __mavlink_solar_clean_temperature_t {
 uint32_t temperature_enabled; /*< the bit 0 to 29 replace the relative the channel of Temperature*/
 float temperature[30]; /*< Temperature in Celsius*/
}) mavlink_solar_clean_temperature_t;

#define MAVLINK_MSG_ID_SOLAR_CLEAN_TEMPERATURE_LEN 124
#define MAVLINK_MSG_ID_SOLAR_CLEAN_TEMPERATURE_MIN_LEN 124
#define MAVLINK_MSG_ID_182_LEN 124
#define MAVLINK_MSG_ID_182_MIN_LEN 124

#define MAVLINK_MSG_ID_SOLAR_CLEAN_TEMPERATURE_CRC 129
#define MAVLINK_MSG_ID_182_CRC 129

#define MAVLINK_MSG_SOLAR_CLEAN_TEMPERATURE_FIELD_TEMPERATURE_LEN 30

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SOLAR_CLEAN_TEMPERATURE { \
    182, \
    "SOLAR_CLEAN_TEMPERATURE", \
    2, \
    {  { "temperature_enabled", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_solar_clean_temperature_t, temperature_enabled) }, \
         { "temperature", NULL, MAVLINK_TYPE_FLOAT, 30, 4, offsetof(mavlink_solar_clean_temperature_t, temperature) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SOLAR_CLEAN_TEMPERATURE { \
    "SOLAR_CLEAN_TEMPERATURE", \
    2, \
    {  { "temperature_enabled", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_solar_clean_temperature_t, temperature_enabled) }, \
         { "temperature", NULL, MAVLINK_TYPE_FLOAT, 30, 4, offsetof(mavlink_solar_clean_temperature_t, temperature) }, \
         } \
}
#endif

/**
 * @brief Pack a solar_clean_temperature message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param temperature_enabled the bit 0 to 29 replace the relative the channel of Temperature
 * @param temperature Temperature in Celsius
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_solar_clean_temperature_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t temperature_enabled, const float *temperature)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SOLAR_CLEAN_TEMPERATURE_LEN];
    _mav_put_uint32_t(buf, 0, temperature_enabled);
    _mav_put_float_array(buf, 4, temperature, 30);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SOLAR_CLEAN_TEMPERATURE_LEN);
#else
    mavlink_solar_clean_temperature_t packet;
    packet.temperature_enabled = temperature_enabled;
    mav_array_memcpy(packet.temperature, temperature, sizeof(float)*30);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SOLAR_CLEAN_TEMPERATURE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SOLAR_CLEAN_TEMPERATURE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SOLAR_CLEAN_TEMPERATURE_MIN_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_TEMPERATURE_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_TEMPERATURE_CRC);
}

/**
 * @brief Pack a solar_clean_temperature message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param temperature_enabled the bit 0 to 29 replace the relative the channel of Temperature
 * @param temperature Temperature in Celsius
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_solar_clean_temperature_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t temperature_enabled,const float *temperature)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SOLAR_CLEAN_TEMPERATURE_LEN];
    _mav_put_uint32_t(buf, 0, temperature_enabled);
    _mav_put_float_array(buf, 4, temperature, 30);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SOLAR_CLEAN_TEMPERATURE_LEN);
#else
    mavlink_solar_clean_temperature_t packet;
    packet.temperature_enabled = temperature_enabled;
    mav_array_memcpy(packet.temperature, temperature, sizeof(float)*30);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SOLAR_CLEAN_TEMPERATURE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SOLAR_CLEAN_TEMPERATURE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SOLAR_CLEAN_TEMPERATURE_MIN_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_TEMPERATURE_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_TEMPERATURE_CRC);
}

/**
 * @brief Encode a solar_clean_temperature struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param solar_clean_temperature C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_solar_clean_temperature_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_solar_clean_temperature_t* solar_clean_temperature)
{
    return mavlink_msg_solar_clean_temperature_pack(system_id, component_id, msg, solar_clean_temperature->temperature_enabled, solar_clean_temperature->temperature);
}

/**
 * @brief Encode a solar_clean_temperature struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param solar_clean_temperature C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_solar_clean_temperature_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_solar_clean_temperature_t* solar_clean_temperature)
{
    return mavlink_msg_solar_clean_temperature_pack_chan(system_id, component_id, chan, msg, solar_clean_temperature->temperature_enabled, solar_clean_temperature->temperature);
}

/**
 * @brief Send a solar_clean_temperature message
 * @param chan MAVLink channel to send the message
 *
 * @param temperature_enabled the bit 0 to 29 replace the relative the channel of Temperature
 * @param temperature Temperature in Celsius
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_solar_clean_temperature_send(mavlink_channel_t chan, uint32_t temperature_enabled, const float *temperature)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SOLAR_CLEAN_TEMPERATURE_LEN];
    _mav_put_uint32_t(buf, 0, temperature_enabled);
    _mav_put_float_array(buf, 4, temperature, 30);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SOLAR_CLEAN_TEMPERATURE, buf, MAVLINK_MSG_ID_SOLAR_CLEAN_TEMPERATURE_MIN_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_TEMPERATURE_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_TEMPERATURE_CRC);
#else
    mavlink_solar_clean_temperature_t packet;
    packet.temperature_enabled = temperature_enabled;
    mav_array_memcpy(packet.temperature, temperature, sizeof(float)*30);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SOLAR_CLEAN_TEMPERATURE, (const char *)&packet, MAVLINK_MSG_ID_SOLAR_CLEAN_TEMPERATURE_MIN_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_TEMPERATURE_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_TEMPERATURE_CRC);
#endif
}

/**
 * @brief Send a solar_clean_temperature message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_solar_clean_temperature_send_struct(mavlink_channel_t chan, const mavlink_solar_clean_temperature_t* solar_clean_temperature)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_solar_clean_temperature_send(chan, solar_clean_temperature->temperature_enabled, solar_clean_temperature->temperature);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SOLAR_CLEAN_TEMPERATURE, (const char *)solar_clean_temperature, MAVLINK_MSG_ID_SOLAR_CLEAN_TEMPERATURE_MIN_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_TEMPERATURE_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_TEMPERATURE_CRC);
#endif
}

#if MAVLINK_MSG_ID_SOLAR_CLEAN_TEMPERATURE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_solar_clean_temperature_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t temperature_enabled, const float *temperature)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, temperature_enabled);
    _mav_put_float_array(buf, 4, temperature, 30);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SOLAR_CLEAN_TEMPERATURE, buf, MAVLINK_MSG_ID_SOLAR_CLEAN_TEMPERATURE_MIN_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_TEMPERATURE_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_TEMPERATURE_CRC);
#else
    mavlink_solar_clean_temperature_t *packet = (mavlink_solar_clean_temperature_t *)msgbuf;
    packet->temperature_enabled = temperature_enabled;
    mav_array_memcpy(packet->temperature, temperature, sizeof(float)*30);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SOLAR_CLEAN_TEMPERATURE, (const char *)packet, MAVLINK_MSG_ID_SOLAR_CLEAN_TEMPERATURE_MIN_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_TEMPERATURE_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_TEMPERATURE_CRC);
#endif
}
#endif

#endif

// MESSAGE SOLAR_CLEAN_TEMPERATURE UNPACKING


/**
 * @brief Get field temperature_enabled from solar_clean_temperature message
 *
 * @return the bit 0 to 29 replace the relative the channel of Temperature
 */
static inline uint32_t mavlink_msg_solar_clean_temperature_get_temperature_enabled(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field temperature from solar_clean_temperature message
 *
 * @return Temperature in Celsius
 */
static inline uint16_t mavlink_msg_solar_clean_temperature_get_temperature(const mavlink_message_t* msg, float *temperature)
{
    return _MAV_RETURN_float_array(msg, temperature, 30,  4);
}

/**
 * @brief Decode a solar_clean_temperature message into a struct
 *
 * @param msg The message to decode
 * @param solar_clean_temperature C-struct to decode the message contents into
 */
static inline void mavlink_msg_solar_clean_temperature_decode(const mavlink_message_t* msg, mavlink_solar_clean_temperature_t* solar_clean_temperature)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    solar_clean_temperature->temperature_enabled = mavlink_msg_solar_clean_temperature_get_temperature_enabled(msg);
    mavlink_msg_solar_clean_temperature_get_temperature(msg, solar_clean_temperature->temperature);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_SOLAR_CLEAN_TEMPERATURE_LEN? msg->len : MAVLINK_MSG_ID_SOLAR_CLEAN_TEMPERATURE_LEN;
        memset(solar_clean_temperature, 0, MAVLINK_MSG_ID_SOLAR_CLEAN_TEMPERATURE_LEN);
    memcpy(solar_clean_temperature, _MAV_PAYLOAD(msg), len);
#endif
}

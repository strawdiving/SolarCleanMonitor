#pragma once
// MESSAGE SOLAR_CLEAN_CONTROL PACKING

#define MAVLINK_MSG_ID_SOLAR_CLEAN_CONTROL 181

MAVPACKED(
typedef struct __mavlink_solar_clean_control_t {
 uint16_t move_speed_control; /*< control the speed of solar clean. MAX speed value 1600*/
 uint8_t move_mode_control; /*< control the move of solar clean,check enum SLOAR_CLEAN_STATE.*/
 uint8_t cleaner_control; /*< control of the cleaner,check enum SLOAR_CLEAN_CLEANER*/
 uint8_t set_working_alarm[2]; /*< set the working alarm after hibernate,24 format*/
}) mavlink_solar_clean_control_t;

#define MAVLINK_MSG_ID_SOLAR_CLEAN_CONTROL_LEN 6
#define MAVLINK_MSG_ID_SOLAR_CLEAN_CONTROL_MIN_LEN 6
#define MAVLINK_MSG_ID_181_LEN 6
#define MAVLINK_MSG_ID_181_MIN_LEN 6

#define MAVLINK_MSG_ID_SOLAR_CLEAN_CONTROL_CRC 32
#define MAVLINK_MSG_ID_181_CRC 32

#define MAVLINK_MSG_SOLAR_CLEAN_CONTROL_FIELD_SET_WORKING_ALARM_LEN 2

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SOLAR_CLEAN_CONTROL { \
    181, \
    "SOLAR_CLEAN_CONTROL", \
    4, \
    {  { "move_speed_control", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_solar_clean_control_t, move_speed_control) }, \
         { "move_mode_control", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_solar_clean_control_t, move_mode_control) }, \
         { "cleaner_control", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_solar_clean_control_t, cleaner_control) }, \
         { "set_working_alarm", NULL, MAVLINK_TYPE_UINT8_T, 2, 4, offsetof(mavlink_solar_clean_control_t, set_working_alarm) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SOLAR_CLEAN_CONTROL { \
    "SOLAR_CLEAN_CONTROL", \
    4, \
    {  { "move_speed_control", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_solar_clean_control_t, move_speed_control) }, \
         { "move_mode_control", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_solar_clean_control_t, move_mode_control) }, \
         { "cleaner_control", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_solar_clean_control_t, cleaner_control) }, \
         { "set_working_alarm", NULL, MAVLINK_TYPE_UINT8_T, 2, 4, offsetof(mavlink_solar_clean_control_t, set_working_alarm) }, \
         } \
}
#endif

/**
 * @brief Pack a solar_clean_control message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param move_mode_control control the move of solar clean,check enum SLOAR_CLEAN_STATE.
 * @param move_speed_control control the speed of solar clean. MAX speed value 1600
 * @param cleaner_control control of the cleaner,check enum SLOAR_CLEAN_CLEANER
 * @param set_working_alarm set the working alarm after hibernate,24 format
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_solar_clean_control_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t move_mode_control, uint16_t move_speed_control, uint8_t cleaner_control, const uint8_t *set_working_alarm)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SOLAR_CLEAN_CONTROL_LEN];
    _mav_put_uint16_t(buf, 0, move_speed_control);
    _mav_put_uint8_t(buf, 2, move_mode_control);
    _mav_put_uint8_t(buf, 3, cleaner_control);
    _mav_put_uint8_t_array(buf, 4, set_working_alarm, 2);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SOLAR_CLEAN_CONTROL_LEN);
#else
    mavlink_solar_clean_control_t packet;
    packet.move_speed_control = move_speed_control;
    packet.move_mode_control = move_mode_control;
    packet.cleaner_control = cleaner_control;
    mav_array_memcpy(packet.set_working_alarm, set_working_alarm, sizeof(uint8_t)*2);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SOLAR_CLEAN_CONTROL_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SOLAR_CLEAN_CONTROL;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SOLAR_CLEAN_CONTROL_MIN_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_CONTROL_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_CONTROL_CRC);
}

/**
 * @brief Pack a solar_clean_control message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param move_mode_control control the move of solar clean,check enum SLOAR_CLEAN_STATE.
 * @param move_speed_control control the speed of solar clean. MAX speed value 1600
 * @param cleaner_control control of the cleaner,check enum SLOAR_CLEAN_CLEANER
 * @param set_working_alarm set the working alarm after hibernate,24 format
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_solar_clean_control_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t move_mode_control,uint16_t move_speed_control,uint8_t cleaner_control,const uint8_t *set_working_alarm)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SOLAR_CLEAN_CONTROL_LEN];
    _mav_put_uint16_t(buf, 0, move_speed_control);
    _mav_put_uint8_t(buf, 2, move_mode_control);
    _mav_put_uint8_t(buf, 3, cleaner_control);
    _mav_put_uint8_t_array(buf, 4, set_working_alarm, 2);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SOLAR_CLEAN_CONTROL_LEN);
#else
    mavlink_solar_clean_control_t packet;
    packet.move_speed_control = move_speed_control;
    packet.move_mode_control = move_mode_control;
    packet.cleaner_control = cleaner_control;
    mav_array_memcpy(packet.set_working_alarm, set_working_alarm, sizeof(uint8_t)*2);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SOLAR_CLEAN_CONTROL_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SOLAR_CLEAN_CONTROL;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SOLAR_CLEAN_CONTROL_MIN_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_CONTROL_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_CONTROL_CRC);
}

/**
 * @brief Encode a solar_clean_control struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param solar_clean_control C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_solar_clean_control_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_solar_clean_control_t* solar_clean_control)
{
    return mavlink_msg_solar_clean_control_pack(system_id, component_id, msg, solar_clean_control->move_mode_control, solar_clean_control->move_speed_control, solar_clean_control->cleaner_control, solar_clean_control->set_working_alarm);
}

/**
 * @brief Encode a solar_clean_control struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param solar_clean_control C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_solar_clean_control_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_solar_clean_control_t* solar_clean_control)
{
    return mavlink_msg_solar_clean_control_pack_chan(system_id, component_id, chan, msg, solar_clean_control->move_mode_control, solar_clean_control->move_speed_control, solar_clean_control->cleaner_control, solar_clean_control->set_working_alarm);
}

/**
 * @brief Send a solar_clean_control message
 * @param chan MAVLink channel to send the message
 *
 * @param move_mode_control control the move of solar clean,check enum SLOAR_CLEAN_STATE.
 * @param move_speed_control control the speed of solar clean. MAX speed value 1600
 * @param cleaner_control control of the cleaner,check enum SLOAR_CLEAN_CLEANER
 * @param set_working_alarm set the working alarm after hibernate,24 format
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_solar_clean_control_send(mavlink_channel_t chan, uint8_t move_mode_control, uint16_t move_speed_control, uint8_t cleaner_control, const uint8_t *set_working_alarm)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SOLAR_CLEAN_CONTROL_LEN];
    _mav_put_uint16_t(buf, 0, move_speed_control);
    _mav_put_uint8_t(buf, 2, move_mode_control);
    _mav_put_uint8_t(buf, 3, cleaner_control);
    _mav_put_uint8_t_array(buf, 4, set_working_alarm, 2);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SOLAR_CLEAN_CONTROL, buf, MAVLINK_MSG_ID_SOLAR_CLEAN_CONTROL_MIN_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_CONTROL_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_CONTROL_CRC);
#else
    mavlink_solar_clean_control_t packet;
    packet.move_speed_control = move_speed_control;
    packet.move_mode_control = move_mode_control;
    packet.cleaner_control = cleaner_control;
    mav_array_memcpy(packet.set_working_alarm, set_working_alarm, sizeof(uint8_t)*2);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SOLAR_CLEAN_CONTROL, (const char *)&packet, MAVLINK_MSG_ID_SOLAR_CLEAN_CONTROL_MIN_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_CONTROL_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_CONTROL_CRC);
#endif
}

/**
 * @brief Send a solar_clean_control message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_solar_clean_control_send_struct(mavlink_channel_t chan, const mavlink_solar_clean_control_t* solar_clean_control)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_solar_clean_control_send(chan, solar_clean_control->move_mode_control, solar_clean_control->move_speed_control, solar_clean_control->cleaner_control, solar_clean_control->set_working_alarm);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SOLAR_CLEAN_CONTROL, (const char *)solar_clean_control, MAVLINK_MSG_ID_SOLAR_CLEAN_CONTROL_MIN_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_CONTROL_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_CONTROL_CRC);
#endif
}

#if MAVLINK_MSG_ID_SOLAR_CLEAN_CONTROL_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_solar_clean_control_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t move_mode_control, uint16_t move_speed_control, uint8_t cleaner_control, const uint8_t *set_working_alarm)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint16_t(buf, 0, move_speed_control);
    _mav_put_uint8_t(buf, 2, move_mode_control);
    _mav_put_uint8_t(buf, 3, cleaner_control);
    _mav_put_uint8_t_array(buf, 4, set_working_alarm, 2);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SOLAR_CLEAN_CONTROL, buf, MAVLINK_MSG_ID_SOLAR_CLEAN_CONTROL_MIN_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_CONTROL_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_CONTROL_CRC);
#else
    mavlink_solar_clean_control_t *packet = (mavlink_solar_clean_control_t *)msgbuf;
    packet->move_speed_control = move_speed_control;
    packet->move_mode_control = move_mode_control;
    packet->cleaner_control = cleaner_control;
    mav_array_memcpy(packet->set_working_alarm, set_working_alarm, sizeof(uint8_t)*2);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SOLAR_CLEAN_CONTROL, (const char *)packet, MAVLINK_MSG_ID_SOLAR_CLEAN_CONTROL_MIN_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_CONTROL_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_CONTROL_CRC);
#endif
}
#endif

#endif

// MESSAGE SOLAR_CLEAN_CONTROL UNPACKING


/**
 * @brief Get field move_mode_control from solar_clean_control message
 *
 * @return control the move of solar clean,check enum SLOAR_CLEAN_STATE.
 */
static inline uint8_t mavlink_msg_solar_clean_control_get_move_mode_control(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Get field move_speed_control from solar_clean_control message
 *
 * @return control the speed of solar clean. MAX speed value 1600
 */
static inline uint16_t mavlink_msg_solar_clean_control_get_move_speed_control(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  0);
}

/**
 * @brief Get field cleaner_control from solar_clean_control message
 *
 * @return control of the cleaner,check enum SLOAR_CLEAN_CLEANER
 */
static inline uint8_t mavlink_msg_solar_clean_control_get_cleaner_control(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  3);
}

/**
 * @brief Get field set_working_alarm from solar_clean_control message
 *
 * @return set the working alarm after hibernate,24 format
 */
static inline uint16_t mavlink_msg_solar_clean_control_get_set_working_alarm(const mavlink_message_t* msg, uint8_t *set_working_alarm)
{
    return _MAV_RETURN_uint8_t_array(msg, set_working_alarm, 2,  4);
}

/**
 * @brief Decode a solar_clean_control message into a struct
 *
 * @param msg The message to decode
 * @param solar_clean_control C-struct to decode the message contents into
 */
static inline void mavlink_msg_solar_clean_control_decode(const mavlink_message_t* msg, mavlink_solar_clean_control_t* solar_clean_control)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    solar_clean_control->move_speed_control = mavlink_msg_solar_clean_control_get_move_speed_control(msg);
    solar_clean_control->move_mode_control = mavlink_msg_solar_clean_control_get_move_mode_control(msg);
    solar_clean_control->cleaner_control = mavlink_msg_solar_clean_control_get_cleaner_control(msg);
    mavlink_msg_solar_clean_control_get_set_working_alarm(msg, solar_clean_control->set_working_alarm);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_SOLAR_CLEAN_CONTROL_LEN? msg->len : MAVLINK_MSG_ID_SOLAR_CLEAN_CONTROL_LEN;
        memset(solar_clean_control, 0, MAVLINK_MSG_ID_SOLAR_CLEAN_CONTROL_LEN);
    memcpy(solar_clean_control, _MAV_PAYLOAD(msg), len);
#endif
}

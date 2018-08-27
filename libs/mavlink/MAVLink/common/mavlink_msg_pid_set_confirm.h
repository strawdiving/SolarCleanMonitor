#pragma once
// MESSAGE PID_SET_Confirm PACKING

#define MAVLINK_MSG_ID_PID_SET_Confirm 157

MAVPACKED(
typedef struct __mavlink_pid_set_confirm_t {
 float param_1; /*< param_1*/
 float param_2; /*< param_2*/
 float param_3; /*< param_3*/
 float param_4; /*< param_4*/
 char PID_NAME[7]; /*< enum{PITCH,ROLL,YAW,X,Y,Z}*/
}) mavlink_pid_set_confirm_t;

#define MAVLINK_MSG_ID_PID_SET_Confirm_LEN 23
#define MAVLINK_MSG_ID_PID_SET_Confirm_MIN_LEN 23
#define MAVLINK_MSG_ID_157_LEN 23
#define MAVLINK_MSG_ID_157_MIN_LEN 23

#define MAVLINK_MSG_ID_PID_SET_Confirm_CRC 76
#define MAVLINK_MSG_ID_157_CRC 76

#define MAVLINK_MSG_PID_SET_Confirm_FIELD_PID_NAME_LEN 7

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_PID_SET_Confirm { \
    157, \
    "PID_SET_Confirm", \
    5, \
    {  { "param_1", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_pid_set_confirm_t, param_1) }, \
         { "param_2", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_pid_set_confirm_t, param_2) }, \
         { "param_3", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_pid_set_confirm_t, param_3) }, \
         { "param_4", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_pid_set_confirm_t, param_4) }, \
         { "PID_NAME", NULL, MAVLINK_TYPE_CHAR, 7, 16, offsetof(mavlink_pid_set_confirm_t, PID_NAME) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_PID_SET_Confirm { \
    "PID_SET_Confirm", \
    5, \
    {  { "param_1", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_pid_set_confirm_t, param_1) }, \
         { "param_2", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_pid_set_confirm_t, param_2) }, \
         { "param_3", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_pid_set_confirm_t, param_3) }, \
         { "param_4", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_pid_set_confirm_t, param_4) }, \
         { "PID_NAME", NULL, MAVLINK_TYPE_CHAR, 7, 16, offsetof(mavlink_pid_set_confirm_t, PID_NAME) }, \
         } \
}
#endif

/**
 * @brief Pack a pid_set_confirm message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param PID_NAME enum{PITCH,ROLL,YAW,X,Y,Z}
 * @param param_1 param_1
 * @param param_2 param_2
 * @param param_3 param_3
 * @param param_4 param_4
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_pid_set_confirm_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               const char *PID_NAME, float param_1, float param_2, float param_3, float param_4)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PID_SET_Confirm_LEN];
    _mav_put_float(buf, 0, param_1);
    _mav_put_float(buf, 4, param_2);
    _mav_put_float(buf, 8, param_3);
    _mav_put_float(buf, 12, param_4);
    _mav_put_char_array(buf, 16, PID_NAME, 7);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PID_SET_Confirm_LEN);
#else
    mavlink_pid_set_confirm_t packet;
    packet.param_1 = param_1;
    packet.param_2 = param_2;
    packet.param_3 = param_3;
    packet.param_4 = param_4;
    mav_array_memcpy(packet.PID_NAME, PID_NAME, sizeof(char)*7);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_PID_SET_Confirm_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_PID_SET_Confirm;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_PID_SET_Confirm_MIN_LEN, MAVLINK_MSG_ID_PID_SET_Confirm_LEN, MAVLINK_MSG_ID_PID_SET_Confirm_CRC);
}

/**
 * @brief Pack a pid_set_confirm message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param PID_NAME enum{PITCH,ROLL,YAW,X,Y,Z}
 * @param param_1 param_1
 * @param param_2 param_2
 * @param param_3 param_3
 * @param param_4 param_4
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_pid_set_confirm_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   const char *PID_NAME,float param_1,float param_2,float param_3,float param_4)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PID_SET_Confirm_LEN];
    _mav_put_float(buf, 0, param_1);
    _mav_put_float(buf, 4, param_2);
    _mav_put_float(buf, 8, param_3);
    _mav_put_float(buf, 12, param_4);
    _mav_put_char_array(buf, 16, PID_NAME, 7);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PID_SET_Confirm_LEN);
#else
    mavlink_pid_set_confirm_t packet;
    packet.param_1 = param_1;
    packet.param_2 = param_2;
    packet.param_3 = param_3;
    packet.param_4 = param_4;
    mav_array_memcpy(packet.PID_NAME, PID_NAME, sizeof(char)*7);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_PID_SET_Confirm_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_PID_SET_Confirm;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_PID_SET_Confirm_MIN_LEN, MAVLINK_MSG_ID_PID_SET_Confirm_LEN, MAVLINK_MSG_ID_PID_SET_Confirm_CRC);
}

/**
 * @brief Encode a pid_set_confirm struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param pid_set_confirm C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_pid_set_confirm_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_pid_set_confirm_t* pid_set_confirm)
{
    return mavlink_msg_pid_set_confirm_pack(system_id, component_id, msg, pid_set_confirm->PID_NAME, pid_set_confirm->param_1, pid_set_confirm->param_2, pid_set_confirm->param_3, pid_set_confirm->param_4);
}

/**
 * @brief Encode a pid_set_confirm struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param pid_set_confirm C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_pid_set_confirm_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_pid_set_confirm_t* pid_set_confirm)
{
    return mavlink_msg_pid_set_confirm_pack_chan(system_id, component_id, chan, msg, pid_set_confirm->PID_NAME, pid_set_confirm->param_1, pid_set_confirm->param_2, pid_set_confirm->param_3, pid_set_confirm->param_4);
}

/**
 * @brief Send a pid_set_confirm message
 * @param chan MAVLink channel to send the message
 *
 * @param PID_NAME enum{PITCH,ROLL,YAW,X,Y,Z}
 * @param param_1 param_1
 * @param param_2 param_2
 * @param param_3 param_3
 * @param param_4 param_4
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_pid_set_confirm_send(mavlink_channel_t chan, const char *PID_NAME, float param_1, float param_2, float param_3, float param_4)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PID_SET_Confirm_LEN];
    _mav_put_float(buf, 0, param_1);
    _mav_put_float(buf, 4, param_2);
    _mav_put_float(buf, 8, param_3);
    _mav_put_float(buf, 12, param_4);
    _mav_put_char_array(buf, 16, PID_NAME, 7);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PID_SET_Confirm, buf, MAVLINK_MSG_ID_PID_SET_Confirm_MIN_LEN, MAVLINK_MSG_ID_PID_SET_Confirm_LEN, MAVLINK_MSG_ID_PID_SET_Confirm_CRC);
#else
    mavlink_pid_set_confirm_t packet;
    packet.param_1 = param_1;
    packet.param_2 = param_2;
    packet.param_3 = param_3;
    packet.param_4 = param_4;
    mav_array_memcpy(packet.PID_NAME, PID_NAME, sizeof(char)*7);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PID_SET_Confirm, (const char *)&packet, MAVLINK_MSG_ID_PID_SET_Confirm_MIN_LEN, MAVLINK_MSG_ID_PID_SET_Confirm_LEN, MAVLINK_MSG_ID_PID_SET_Confirm_CRC);
#endif
}

/**
 * @brief Send a pid_set_confirm message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_pid_set_confirm_send_struct(mavlink_channel_t chan, const mavlink_pid_set_confirm_t* pid_set_confirm)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_pid_set_confirm_send(chan, pid_set_confirm->PID_NAME, pid_set_confirm->param_1, pid_set_confirm->param_2, pid_set_confirm->param_3, pid_set_confirm->param_4);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PID_SET_Confirm, (const char *)pid_set_confirm, MAVLINK_MSG_ID_PID_SET_Confirm_MIN_LEN, MAVLINK_MSG_ID_PID_SET_Confirm_LEN, MAVLINK_MSG_ID_PID_SET_Confirm_CRC);
#endif
}

#if MAVLINK_MSG_ID_PID_SET_Confirm_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_pid_set_confirm_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  const char *PID_NAME, float param_1, float param_2, float param_3, float param_4)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, param_1);
    _mav_put_float(buf, 4, param_2);
    _mav_put_float(buf, 8, param_3);
    _mav_put_float(buf, 12, param_4);
    _mav_put_char_array(buf, 16, PID_NAME, 7);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PID_SET_Confirm, buf, MAVLINK_MSG_ID_PID_SET_Confirm_MIN_LEN, MAVLINK_MSG_ID_PID_SET_Confirm_LEN, MAVLINK_MSG_ID_PID_SET_Confirm_CRC);
#else
    mavlink_pid_set_confirm_t *packet = (mavlink_pid_set_confirm_t *)msgbuf;
    packet->param_1 = param_1;
    packet->param_2 = param_2;
    packet->param_3 = param_3;
    packet->param_4 = param_4;
    mav_array_memcpy(packet->PID_NAME, PID_NAME, sizeof(char)*7);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PID_SET_Confirm, (const char *)packet, MAVLINK_MSG_ID_PID_SET_Confirm_MIN_LEN, MAVLINK_MSG_ID_PID_SET_Confirm_LEN, MAVLINK_MSG_ID_PID_SET_Confirm_CRC);
#endif
}
#endif

#endif

// MESSAGE PID_SET_Confirm UNPACKING


/**
 * @brief Get field PID_NAME from pid_set_confirm message
 *
 * @return enum{PITCH,ROLL,YAW,X,Y,Z}
 */
static inline uint16_t mavlink_msg_pid_set_confirm_get_PID_NAME(const mavlink_message_t* msg, char *PID_NAME)
{
    return _MAV_RETURN_char_array(msg, PID_NAME, 7,  16);
}

/**
 * @brief Get field param_1 from pid_set_confirm message
 *
 * @return param_1
 */
static inline float mavlink_msg_pid_set_confirm_get_param_1(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field param_2 from pid_set_confirm message
 *
 * @return param_2
 */
static inline float mavlink_msg_pid_set_confirm_get_param_2(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field param_3 from pid_set_confirm message
 *
 * @return param_3
 */
static inline float mavlink_msg_pid_set_confirm_get_param_3(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field param_4 from pid_set_confirm message
 *
 * @return param_4
 */
static inline float mavlink_msg_pid_set_confirm_get_param_4(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Decode a pid_set_confirm message into a struct
 *
 * @param msg The message to decode
 * @param pid_set_confirm C-struct to decode the message contents into
 */
static inline void mavlink_msg_pid_set_confirm_decode(const mavlink_message_t* msg, mavlink_pid_set_confirm_t* pid_set_confirm)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    pid_set_confirm->param_1 = mavlink_msg_pid_set_confirm_get_param_1(msg);
    pid_set_confirm->param_2 = mavlink_msg_pid_set_confirm_get_param_2(msg);
    pid_set_confirm->param_3 = mavlink_msg_pid_set_confirm_get_param_3(msg);
    pid_set_confirm->param_4 = mavlink_msg_pid_set_confirm_get_param_4(msg);
    mavlink_msg_pid_set_confirm_get_PID_NAME(msg, pid_set_confirm->PID_NAME);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_PID_SET_Confirm_LEN? msg->len : MAVLINK_MSG_ID_PID_SET_Confirm_LEN;
        memset(pid_set_confirm, 0, MAVLINK_MSG_ID_PID_SET_Confirm_LEN);
    memcpy(pid_set_confirm, _MAV_PAYLOAD(msg), len);
#endif
}

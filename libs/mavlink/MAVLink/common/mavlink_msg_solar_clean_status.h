#pragma once
// MESSAGE SOLAR_CLEAN_STATUS PACKING

#define MAVLINK_MSG_ID_SOLAR_CLEAN_STATUS 180

MAVPACKED(
typedef struct __mavlink_solar_clean_status_t {
 uint32_t running_time; /*< running time boot/reboot(uint:s).*/
 uint16_t move_speed; /*< the speed of solar clean.*/
 uint16_t position; /*< Position of the solar_cleaner relative to home position(unit:cm).*/
 uint16_t voltage_battery; /*< Battery voltage, in millivolts (1 = 1 millivolt)*/
 int16_t current_battery; /*< Battery current, in 10*milliamperes (1 = 10 milliampere), -1: autopilot does not measure the current*/
 uint8_t move_mode_status; /*< status the move of solar clean,check enum SLOAR_CLEAN_STATE.*/
 uint8_t cleaner_status; /*< status of the cleaner,check enum SLOAR_CLEAN_CLEANER*/
 uint8_t working_alarm_now[2]; /*< the default working alarm after hibernate,24 format*/
 int8_t battery_remaining; /*< Remaining battery energy: (0%: 0, 100%: 100), -1: autopilot estimate the remaining battery*/
}) mavlink_solar_clean_status_t;

#define MAVLINK_MSG_ID_SOLAR_CLEAN_STATUS_LEN 17
#define MAVLINK_MSG_ID_SOLAR_CLEAN_STATUS_MIN_LEN 17
#define MAVLINK_MSG_ID_180_LEN 17
#define MAVLINK_MSG_ID_180_MIN_LEN 17

#define MAVLINK_MSG_ID_SOLAR_CLEAN_STATUS_CRC 236
#define MAVLINK_MSG_ID_180_CRC 236

#define MAVLINK_MSG_SOLAR_CLEAN_STATUS_FIELD_WORKING_ALARM_NOW_LEN 2

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SOLAR_CLEAN_STATUS { \
    180, \
    "SOLAR_CLEAN_STATUS", \
    9, \
    {  { "running_time", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_solar_clean_status_t, running_time) }, \
         { "move_speed", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_solar_clean_status_t, move_speed) }, \
         { "position", NULL, MAVLINK_TYPE_UINT16_T, 0, 6, offsetof(mavlink_solar_clean_status_t, position) }, \
         { "voltage_battery", NULL, MAVLINK_TYPE_UINT16_T, 0, 8, offsetof(mavlink_solar_clean_status_t, voltage_battery) }, \
         { "current_battery", NULL, MAVLINK_TYPE_INT16_T, 0, 10, offsetof(mavlink_solar_clean_status_t, current_battery) }, \
         { "move_mode_status", NULL, MAVLINK_TYPE_UINT8_T, 0, 12, offsetof(mavlink_solar_clean_status_t, move_mode_status) }, \
         { "cleaner_status", NULL, MAVLINK_TYPE_UINT8_T, 0, 13, offsetof(mavlink_solar_clean_status_t, cleaner_status) }, \
         { "working_alarm_now", NULL, MAVLINK_TYPE_UINT8_T, 2, 14, offsetof(mavlink_solar_clean_status_t, working_alarm_now) }, \
         { "battery_remaining", NULL, MAVLINK_TYPE_INT8_T, 0, 16, offsetof(mavlink_solar_clean_status_t, battery_remaining) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SOLAR_CLEAN_STATUS { \
    "SOLAR_CLEAN_STATUS", \
    9, \
    {  { "running_time", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_solar_clean_status_t, running_time) }, \
         { "move_speed", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_solar_clean_status_t, move_speed) }, \
         { "position", NULL, MAVLINK_TYPE_UINT16_T, 0, 6, offsetof(mavlink_solar_clean_status_t, position) }, \
         { "voltage_battery", NULL, MAVLINK_TYPE_UINT16_T, 0, 8, offsetof(mavlink_solar_clean_status_t, voltage_battery) }, \
         { "current_battery", NULL, MAVLINK_TYPE_INT16_T, 0, 10, offsetof(mavlink_solar_clean_status_t, current_battery) }, \
         { "move_mode_status", NULL, MAVLINK_TYPE_UINT8_T, 0, 12, offsetof(mavlink_solar_clean_status_t, move_mode_status) }, \
         { "cleaner_status", NULL, MAVLINK_TYPE_UINT8_T, 0, 13, offsetof(mavlink_solar_clean_status_t, cleaner_status) }, \
         { "working_alarm_now", NULL, MAVLINK_TYPE_UINT8_T, 2, 14, offsetof(mavlink_solar_clean_status_t, working_alarm_now) }, \
         { "battery_remaining", NULL, MAVLINK_TYPE_INT8_T, 0, 16, offsetof(mavlink_solar_clean_status_t, battery_remaining) }, \
         } \
}
#endif

/**
 * @brief Pack a solar_clean_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param move_mode_status status the move of solar clean,check enum SLOAR_CLEAN_STATE.
 * @param move_speed the speed of solar clean.
 * @param cleaner_status status of the cleaner,check enum SLOAR_CLEAN_CLEANER
 * @param position Position of the solar_cleaner relative to home position(unit:cm).
 * @param running_time running time boot/reboot(uint:s).
 * @param working_alarm_now the default working alarm after hibernate,24 format
 * @param voltage_battery Battery voltage, in millivolts (1 = 1 millivolt)
 * @param current_battery Battery current, in 10*milliamperes (1 = 10 milliampere), -1: autopilot does not measure the current
 * @param battery_remaining Remaining battery energy: (0%: 0, 100%: 100), -1: autopilot estimate the remaining battery
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_solar_clean_status_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t move_mode_status, uint16_t move_speed, uint8_t cleaner_status, uint16_t position, uint32_t running_time, const uint8_t *working_alarm_now, uint16_t voltage_battery, int16_t current_battery, int8_t battery_remaining)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SOLAR_CLEAN_STATUS_LEN];
    _mav_put_uint32_t(buf, 0, running_time);
    _mav_put_uint16_t(buf, 4, move_speed);
    _mav_put_uint16_t(buf, 6, position);
    _mav_put_uint16_t(buf, 8, voltage_battery);
    _mav_put_int16_t(buf, 10, current_battery);
    _mav_put_uint8_t(buf, 12, move_mode_status);
    _mav_put_uint8_t(buf, 13, cleaner_status);
    _mav_put_int8_t(buf, 16, battery_remaining);
    _mav_put_uint8_t_array(buf, 14, working_alarm_now, 2);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SOLAR_CLEAN_STATUS_LEN);
#else
    mavlink_solar_clean_status_t packet;
    packet.running_time = running_time;
    packet.move_speed = move_speed;
    packet.position = position;
    packet.voltage_battery = voltage_battery;
    packet.current_battery = current_battery;
    packet.move_mode_status = move_mode_status;
    packet.cleaner_status = cleaner_status;
    packet.battery_remaining = battery_remaining;
    mav_array_memcpy(packet.working_alarm_now, working_alarm_now, sizeof(uint8_t)*2);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SOLAR_CLEAN_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SOLAR_CLEAN_STATUS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SOLAR_CLEAN_STATUS_MIN_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_STATUS_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_STATUS_CRC);
}

/**
 * @brief Pack a solar_clean_status message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param move_mode_status status the move of solar clean,check enum SLOAR_CLEAN_STATE.
 * @param move_speed the speed of solar clean.
 * @param cleaner_status status of the cleaner,check enum SLOAR_CLEAN_CLEANER
 * @param position Position of the solar_cleaner relative to home position(unit:cm).
 * @param running_time running time boot/reboot(uint:s).
 * @param working_alarm_now the default working alarm after hibernate,24 format
 * @param voltage_battery Battery voltage, in millivolts (1 = 1 millivolt)
 * @param current_battery Battery current, in 10*milliamperes (1 = 10 milliampere), -1: autopilot does not measure the current
 * @param battery_remaining Remaining battery energy: (0%: 0, 100%: 100), -1: autopilot estimate the remaining battery
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_solar_clean_status_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t move_mode_status,uint16_t move_speed,uint8_t cleaner_status,uint16_t position,uint32_t running_time,const uint8_t *working_alarm_now,uint16_t voltage_battery,int16_t current_battery,int8_t battery_remaining)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SOLAR_CLEAN_STATUS_LEN];
    _mav_put_uint32_t(buf, 0, running_time);
    _mav_put_uint16_t(buf, 4, move_speed);
    _mav_put_uint16_t(buf, 6, position);
    _mav_put_uint16_t(buf, 8, voltage_battery);
    _mav_put_int16_t(buf, 10, current_battery);
    _mav_put_uint8_t(buf, 12, move_mode_status);
    _mav_put_uint8_t(buf, 13, cleaner_status);
    _mav_put_int8_t(buf, 16, battery_remaining);
    _mav_put_uint8_t_array(buf, 14, working_alarm_now, 2);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SOLAR_CLEAN_STATUS_LEN);
#else
    mavlink_solar_clean_status_t packet;
    packet.running_time = running_time;
    packet.move_speed = move_speed;
    packet.position = position;
    packet.voltage_battery = voltage_battery;
    packet.current_battery = current_battery;
    packet.move_mode_status = move_mode_status;
    packet.cleaner_status = cleaner_status;
    packet.battery_remaining = battery_remaining;
    mav_array_memcpy(packet.working_alarm_now, working_alarm_now, sizeof(uint8_t)*2);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SOLAR_CLEAN_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SOLAR_CLEAN_STATUS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SOLAR_CLEAN_STATUS_MIN_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_STATUS_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_STATUS_CRC);
}

/**
 * @brief Encode a solar_clean_status struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param solar_clean_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_solar_clean_status_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_solar_clean_status_t* solar_clean_status)
{
    return mavlink_msg_solar_clean_status_pack(system_id, component_id, msg, solar_clean_status->move_mode_status, solar_clean_status->move_speed, solar_clean_status->cleaner_status, solar_clean_status->position, solar_clean_status->running_time, solar_clean_status->working_alarm_now, solar_clean_status->voltage_battery, solar_clean_status->current_battery, solar_clean_status->battery_remaining);
}

/**
 * @brief Encode a solar_clean_status struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param solar_clean_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_solar_clean_status_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_solar_clean_status_t* solar_clean_status)
{
    return mavlink_msg_solar_clean_status_pack_chan(system_id, component_id, chan, msg, solar_clean_status->move_mode_status, solar_clean_status->move_speed, solar_clean_status->cleaner_status, solar_clean_status->position, solar_clean_status->running_time, solar_clean_status->working_alarm_now, solar_clean_status->voltage_battery, solar_clean_status->current_battery, solar_clean_status->battery_remaining);
}

/**
 * @brief Send a solar_clean_status message
 * @param chan MAVLink channel to send the message
 *
 * @param move_mode_status status the move of solar clean,check enum SLOAR_CLEAN_STATE.
 * @param move_speed the speed of solar clean.
 * @param cleaner_status status of the cleaner,check enum SLOAR_CLEAN_CLEANER
 * @param position Position of the solar_cleaner relative to home position(unit:cm).
 * @param running_time running time boot/reboot(uint:s).
 * @param working_alarm_now the default working alarm after hibernate,24 format
 * @param voltage_battery Battery voltage, in millivolts (1 = 1 millivolt)
 * @param current_battery Battery current, in 10*milliamperes (1 = 10 milliampere), -1: autopilot does not measure the current
 * @param battery_remaining Remaining battery energy: (0%: 0, 100%: 100), -1: autopilot estimate the remaining battery
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_solar_clean_status_send(mavlink_channel_t chan, uint8_t move_mode_status, uint16_t move_speed, uint8_t cleaner_status, uint16_t position, uint32_t running_time, const uint8_t *working_alarm_now, uint16_t voltage_battery, int16_t current_battery, int8_t battery_remaining)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SOLAR_CLEAN_STATUS_LEN];
    _mav_put_uint32_t(buf, 0, running_time);
    _mav_put_uint16_t(buf, 4, move_speed);
    _mav_put_uint16_t(buf, 6, position);
    _mav_put_uint16_t(buf, 8, voltage_battery);
    _mav_put_int16_t(buf, 10, current_battery);
    _mav_put_uint8_t(buf, 12, move_mode_status);
    _mav_put_uint8_t(buf, 13, cleaner_status);
    _mav_put_int8_t(buf, 16, battery_remaining);
    _mav_put_uint8_t_array(buf, 14, working_alarm_now, 2);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SOLAR_CLEAN_STATUS, buf, MAVLINK_MSG_ID_SOLAR_CLEAN_STATUS_MIN_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_STATUS_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_STATUS_CRC);
#else
    mavlink_solar_clean_status_t packet;
    packet.running_time = running_time;
    packet.move_speed = move_speed;
    packet.position = position;
    packet.voltage_battery = voltage_battery;
    packet.current_battery = current_battery;
    packet.move_mode_status = move_mode_status;
    packet.cleaner_status = cleaner_status;
    packet.battery_remaining = battery_remaining;
    mav_array_memcpy(packet.working_alarm_now, working_alarm_now, sizeof(uint8_t)*2);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SOLAR_CLEAN_STATUS, (const char *)&packet, MAVLINK_MSG_ID_SOLAR_CLEAN_STATUS_MIN_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_STATUS_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_STATUS_CRC);
#endif
}

/**
 * @brief Send a solar_clean_status message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_solar_clean_status_send_struct(mavlink_channel_t chan, const mavlink_solar_clean_status_t* solar_clean_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_solar_clean_status_send(chan, solar_clean_status->move_mode_status, solar_clean_status->move_speed, solar_clean_status->cleaner_status, solar_clean_status->position, solar_clean_status->running_time, solar_clean_status->working_alarm_now, solar_clean_status->voltage_battery, solar_clean_status->current_battery, solar_clean_status->battery_remaining);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SOLAR_CLEAN_STATUS, (const char *)solar_clean_status, MAVLINK_MSG_ID_SOLAR_CLEAN_STATUS_MIN_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_STATUS_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_STATUS_CRC);
#endif
}

#if MAVLINK_MSG_ID_SOLAR_CLEAN_STATUS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_solar_clean_status_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t move_mode_status, uint16_t move_speed, uint8_t cleaner_status, uint16_t position, uint32_t running_time, const uint8_t *working_alarm_now, uint16_t voltage_battery, int16_t current_battery, int8_t battery_remaining)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, running_time);
    _mav_put_uint16_t(buf, 4, move_speed);
    _mav_put_uint16_t(buf, 6, position);
    _mav_put_uint16_t(buf, 8, voltage_battery);
    _mav_put_int16_t(buf, 10, current_battery);
    _mav_put_uint8_t(buf, 12, move_mode_status);
    _mav_put_uint8_t(buf, 13, cleaner_status);
    _mav_put_int8_t(buf, 16, battery_remaining);
    _mav_put_uint8_t_array(buf, 14, working_alarm_now, 2);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SOLAR_CLEAN_STATUS, buf, MAVLINK_MSG_ID_SOLAR_CLEAN_STATUS_MIN_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_STATUS_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_STATUS_CRC);
#else
    mavlink_solar_clean_status_t *packet = (mavlink_solar_clean_status_t *)msgbuf;
    packet->running_time = running_time;
    packet->move_speed = move_speed;
    packet->position = position;
    packet->voltage_battery = voltage_battery;
    packet->current_battery = current_battery;
    packet->move_mode_status = move_mode_status;
    packet->cleaner_status = cleaner_status;
    packet->battery_remaining = battery_remaining;
    mav_array_memcpy(packet->working_alarm_now, working_alarm_now, sizeof(uint8_t)*2);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SOLAR_CLEAN_STATUS, (const char *)packet, MAVLINK_MSG_ID_SOLAR_CLEAN_STATUS_MIN_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_STATUS_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_STATUS_CRC);
#endif
}
#endif

#endif

// MESSAGE SOLAR_CLEAN_STATUS UNPACKING


/**
 * @brief Get field move_mode_status from solar_clean_status message
 *
 * @return status the move of solar clean,check enum SLOAR_CLEAN_STATE.
 */
static inline uint8_t mavlink_msg_solar_clean_status_get_move_mode_status(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  12);
}

/**
 * @brief Get field move_speed from solar_clean_status message
 *
 * @return the speed of solar clean.
 */
static inline uint16_t mavlink_msg_solar_clean_status_get_move_speed(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  4);
}

/**
 * @brief Get field cleaner_status from solar_clean_status message
 *
 * @return status of the cleaner,check enum SLOAR_CLEAN_CLEANER
 */
static inline uint8_t mavlink_msg_solar_clean_status_get_cleaner_status(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  13);
}

/**
 * @brief Get field position from solar_clean_status message
 *
 * @return Position of the solar_cleaner relative to home position(unit:cm).
 */
static inline uint16_t mavlink_msg_solar_clean_status_get_position(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  6);
}

/**
 * @brief Get field running_time from solar_clean_status message
 *
 * @return running time boot/reboot(uint:s).
 */
static inline uint32_t mavlink_msg_solar_clean_status_get_running_time(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field working_alarm_now from solar_clean_status message
 *
 * @return the default working alarm after hibernate,24 format
 */
static inline uint16_t mavlink_msg_solar_clean_status_get_working_alarm_now(const mavlink_message_t* msg, uint8_t *working_alarm_now)
{
    return _MAV_RETURN_uint8_t_array(msg, working_alarm_now, 2,  14);
}

/**
 * @brief Get field voltage_battery from solar_clean_status message
 *
 * @return Battery voltage, in millivolts (1 = 1 millivolt)
 */
static inline uint16_t mavlink_msg_solar_clean_status_get_voltage_battery(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  8);
}

/**
 * @brief Get field current_battery from solar_clean_status message
 *
 * @return Battery current, in 10*milliamperes (1 = 10 milliampere), -1: autopilot does not measure the current
 */
static inline int16_t mavlink_msg_solar_clean_status_get_current_battery(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  10);
}

/**
 * @brief Get field battery_remaining from solar_clean_status message
 *
 * @return Remaining battery energy: (0%: 0, 100%: 100), -1: autopilot estimate the remaining battery
 */
static inline int8_t mavlink_msg_solar_clean_status_get_battery_remaining(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int8_t(msg,  16);
}

/**
 * @brief Decode a solar_clean_status message into a struct
 *
 * @param msg The message to decode
 * @param solar_clean_status C-struct to decode the message contents into
 */
static inline void mavlink_msg_solar_clean_status_decode(const mavlink_message_t* msg, mavlink_solar_clean_status_t* solar_clean_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    solar_clean_status->running_time = mavlink_msg_solar_clean_status_get_running_time(msg);
    solar_clean_status->move_speed = mavlink_msg_solar_clean_status_get_move_speed(msg);
    solar_clean_status->position = mavlink_msg_solar_clean_status_get_position(msg);
    solar_clean_status->voltage_battery = mavlink_msg_solar_clean_status_get_voltage_battery(msg);
    solar_clean_status->current_battery = mavlink_msg_solar_clean_status_get_current_battery(msg);
    solar_clean_status->move_mode_status = mavlink_msg_solar_clean_status_get_move_mode_status(msg);
    solar_clean_status->cleaner_status = mavlink_msg_solar_clean_status_get_cleaner_status(msg);
    mavlink_msg_solar_clean_status_get_working_alarm_now(msg, solar_clean_status->working_alarm_now);
    solar_clean_status->battery_remaining = mavlink_msg_solar_clean_status_get_battery_remaining(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_SOLAR_CLEAN_STATUS_LEN? msg->len : MAVLINK_MSG_ID_SOLAR_CLEAN_STATUS_LEN;
        memset(solar_clean_status, 0, MAVLINK_MSG_ID_SOLAR_CLEAN_STATUS_LEN);
    memcpy(solar_clean_status, _MAV_PAYLOAD(msg), len);
#endif
}

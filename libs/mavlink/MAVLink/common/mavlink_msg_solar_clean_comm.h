#pragma once
// MESSAGE SOLAR_CLEAN_COMM PACKING

#define MAVLINK_MSG_ID_SOLAR_CLEAN_COMM 183

MAVPACKED(
typedef struct __mavlink_solar_clean_comm_t {
 char wifi_name[16]; /*< wifi spot name*/
 char wifi_passwd[16]; /*< wifi spot password*/
 char server_ip[16]; /*< server ip*/
 char server_tcp_port[16]; /*< server tcp port*/
}) mavlink_solar_clean_comm_t;

#define MAVLINK_MSG_ID_SOLAR_CLEAN_COMM_LEN 64
#define MAVLINK_MSG_ID_SOLAR_CLEAN_COMM_MIN_LEN 64
#define MAVLINK_MSG_ID_183_LEN 64
#define MAVLINK_MSG_ID_183_MIN_LEN 64

#define MAVLINK_MSG_ID_SOLAR_CLEAN_COMM_CRC 240
#define MAVLINK_MSG_ID_183_CRC 240

#define MAVLINK_MSG_SOLAR_CLEAN_COMM_FIELD_WIFI_NAME_LEN 16
#define MAVLINK_MSG_SOLAR_CLEAN_COMM_FIELD_WIFI_PASSWD_LEN 16
#define MAVLINK_MSG_SOLAR_CLEAN_COMM_FIELD_SERVER_IP_LEN 16
#define MAVLINK_MSG_SOLAR_CLEAN_COMM_FIELD_SERVER_TCP_PORT_LEN 16

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SOLAR_CLEAN_COMM { \
    183, \
    "SOLAR_CLEAN_COMM", \
    4, \
    {  { "wifi_name", NULL, MAVLINK_TYPE_CHAR, 16, 0, offsetof(mavlink_solar_clean_comm_t, wifi_name) }, \
         { "wifi_passwd", NULL, MAVLINK_TYPE_CHAR, 16, 16, offsetof(mavlink_solar_clean_comm_t, wifi_passwd) }, \
         { "server_ip", NULL, MAVLINK_TYPE_CHAR, 16, 32, offsetof(mavlink_solar_clean_comm_t, server_ip) }, \
         { "server_tcp_port", NULL, MAVLINK_TYPE_CHAR, 16, 48, offsetof(mavlink_solar_clean_comm_t, server_tcp_port) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SOLAR_CLEAN_COMM { \
    "SOLAR_CLEAN_COMM", \
    4, \
    {  { "wifi_name", NULL, MAVLINK_TYPE_CHAR, 16, 0, offsetof(mavlink_solar_clean_comm_t, wifi_name) }, \
         { "wifi_passwd", NULL, MAVLINK_TYPE_CHAR, 16, 16, offsetof(mavlink_solar_clean_comm_t, wifi_passwd) }, \
         { "server_ip", NULL, MAVLINK_TYPE_CHAR, 16, 32, offsetof(mavlink_solar_clean_comm_t, server_ip) }, \
         { "server_tcp_port", NULL, MAVLINK_TYPE_CHAR, 16, 48, offsetof(mavlink_solar_clean_comm_t, server_tcp_port) }, \
         } \
}
#endif

/**
 * @brief Pack a solar_clean_comm message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param wifi_name wifi spot name
 * @param wifi_passwd wifi spot password
 * @param server_ip server ip
 * @param server_tcp_port server tcp port
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_solar_clean_comm_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               const char *wifi_name, const char *wifi_passwd, const char *server_ip, const char *server_tcp_port)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SOLAR_CLEAN_COMM_LEN];

    _mav_put_char_array(buf, 0, wifi_name, 16);
    _mav_put_char_array(buf, 16, wifi_passwd, 16);
    _mav_put_char_array(buf, 32, server_ip, 16);
    _mav_put_char_array(buf, 48, server_tcp_port, 16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SOLAR_CLEAN_COMM_LEN);
#else
    mavlink_solar_clean_comm_t packet;

    mav_array_memcpy(packet.wifi_name, wifi_name, sizeof(char)*16);
    mav_array_memcpy(packet.wifi_passwd, wifi_passwd, sizeof(char)*16);
    mav_array_memcpy(packet.server_ip, server_ip, sizeof(char)*16);
    mav_array_memcpy(packet.server_tcp_port, server_tcp_port, sizeof(char)*16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SOLAR_CLEAN_COMM_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SOLAR_CLEAN_COMM;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SOLAR_CLEAN_COMM_MIN_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_COMM_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_COMM_CRC);
}

/**
 * @brief Pack a solar_clean_comm message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wifi_name wifi spot name
 * @param wifi_passwd wifi spot password
 * @param server_ip server ip
 * @param server_tcp_port server tcp port
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_solar_clean_comm_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   const char *wifi_name,const char *wifi_passwd,const char *server_ip,const char *server_tcp_port)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SOLAR_CLEAN_COMM_LEN];

    _mav_put_char_array(buf, 0, wifi_name, 16);
    _mav_put_char_array(buf, 16, wifi_passwd, 16);
    _mav_put_char_array(buf, 32, server_ip, 16);
    _mav_put_char_array(buf, 48, server_tcp_port, 16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SOLAR_CLEAN_COMM_LEN);
#else
    mavlink_solar_clean_comm_t packet;

    mav_array_memcpy(packet.wifi_name, wifi_name, sizeof(char)*16);
    mav_array_memcpy(packet.wifi_passwd, wifi_passwd, sizeof(char)*16);
    mav_array_memcpy(packet.server_ip, server_ip, sizeof(char)*16);
    mav_array_memcpy(packet.server_tcp_port, server_tcp_port, sizeof(char)*16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SOLAR_CLEAN_COMM_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SOLAR_CLEAN_COMM;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SOLAR_CLEAN_COMM_MIN_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_COMM_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_COMM_CRC);
}

/**
 * @brief Encode a solar_clean_comm struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param solar_clean_comm C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_solar_clean_comm_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_solar_clean_comm_t* solar_clean_comm)
{
    return mavlink_msg_solar_clean_comm_pack(system_id, component_id, msg, solar_clean_comm->wifi_name, solar_clean_comm->wifi_passwd, solar_clean_comm->server_ip, solar_clean_comm->server_tcp_port);
}

/**
 * @brief Encode a solar_clean_comm struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param solar_clean_comm C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_solar_clean_comm_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_solar_clean_comm_t* solar_clean_comm)
{
    return mavlink_msg_solar_clean_comm_pack_chan(system_id, component_id, chan, msg, solar_clean_comm->wifi_name, solar_clean_comm->wifi_passwd, solar_clean_comm->server_ip, solar_clean_comm->server_tcp_port);
}

/**
 * @brief Send a solar_clean_comm message
 * @param chan MAVLink channel to send the message
 *
 * @param wifi_name wifi spot name
 * @param wifi_passwd wifi spot password
 * @param server_ip server ip
 * @param server_tcp_port server tcp port
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_solar_clean_comm_send(mavlink_channel_t chan, const char *wifi_name, const char *wifi_passwd, const char *server_ip, const char *server_tcp_port)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SOLAR_CLEAN_COMM_LEN];

    _mav_put_char_array(buf, 0, wifi_name, 16);
    _mav_put_char_array(buf, 16, wifi_passwd, 16);
    _mav_put_char_array(buf, 32, server_ip, 16);
    _mav_put_char_array(buf, 48, server_tcp_port, 16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SOLAR_CLEAN_COMM, buf, MAVLINK_MSG_ID_SOLAR_CLEAN_COMM_MIN_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_COMM_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_COMM_CRC);
#else
    mavlink_solar_clean_comm_t packet;

    mav_array_memcpy(packet.wifi_name, wifi_name, sizeof(char)*16);
    mav_array_memcpy(packet.wifi_passwd, wifi_passwd, sizeof(char)*16);
    mav_array_memcpy(packet.server_ip, server_ip, sizeof(char)*16);
    mav_array_memcpy(packet.server_tcp_port, server_tcp_port, sizeof(char)*16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SOLAR_CLEAN_COMM, (const char *)&packet, MAVLINK_MSG_ID_SOLAR_CLEAN_COMM_MIN_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_COMM_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_COMM_CRC);
#endif
}

/**
 * @brief Send a solar_clean_comm message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_solar_clean_comm_send_struct(mavlink_channel_t chan, const mavlink_solar_clean_comm_t* solar_clean_comm)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_solar_clean_comm_send(chan, solar_clean_comm->wifi_name, solar_clean_comm->wifi_passwd, solar_clean_comm->server_ip, solar_clean_comm->server_tcp_port);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SOLAR_CLEAN_COMM, (const char *)solar_clean_comm, MAVLINK_MSG_ID_SOLAR_CLEAN_COMM_MIN_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_COMM_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_COMM_CRC);
#endif
}

#if MAVLINK_MSG_ID_SOLAR_CLEAN_COMM_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_solar_clean_comm_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  const char *wifi_name, const char *wifi_passwd, const char *server_ip, const char *server_tcp_port)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;

    _mav_put_char_array(buf, 0, wifi_name, 16);
    _mav_put_char_array(buf, 16, wifi_passwd, 16);
    _mav_put_char_array(buf, 32, server_ip, 16);
    _mav_put_char_array(buf, 48, server_tcp_port, 16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SOLAR_CLEAN_COMM, buf, MAVLINK_MSG_ID_SOLAR_CLEAN_COMM_MIN_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_COMM_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_COMM_CRC);
#else
    mavlink_solar_clean_comm_t *packet = (mavlink_solar_clean_comm_t *)msgbuf;

    mav_array_memcpy(packet->wifi_name, wifi_name, sizeof(char)*16);
    mav_array_memcpy(packet->wifi_passwd, wifi_passwd, sizeof(char)*16);
    mav_array_memcpy(packet->server_ip, server_ip, sizeof(char)*16);
    mav_array_memcpy(packet->server_tcp_port, server_tcp_port, sizeof(char)*16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SOLAR_CLEAN_COMM, (const char *)packet, MAVLINK_MSG_ID_SOLAR_CLEAN_COMM_MIN_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_COMM_LEN, MAVLINK_MSG_ID_SOLAR_CLEAN_COMM_CRC);
#endif
}
#endif

#endif

// MESSAGE SOLAR_CLEAN_COMM UNPACKING


/**
 * @brief Get field wifi_name from solar_clean_comm message
 *
 * @return wifi spot name
 */
static inline uint16_t mavlink_msg_solar_clean_comm_get_wifi_name(const mavlink_message_t* msg, char *wifi_name)
{
    return _MAV_RETURN_char_array(msg, wifi_name, 16,  0);
}

/**
 * @brief Get field wifi_passwd from solar_clean_comm message
 *
 * @return wifi spot password
 */
static inline uint16_t mavlink_msg_solar_clean_comm_get_wifi_passwd(const mavlink_message_t* msg, char *wifi_passwd)
{
    return _MAV_RETURN_char_array(msg, wifi_passwd, 16,  16);
}

/**
 * @brief Get field server_ip from solar_clean_comm message
 *
 * @return server ip
 */
static inline uint16_t mavlink_msg_solar_clean_comm_get_server_ip(const mavlink_message_t* msg, char *server_ip)
{
    return _MAV_RETURN_char_array(msg, server_ip, 16,  32);
}

/**
 * @brief Get field server_tcp_port from solar_clean_comm message
 *
 * @return server tcp port
 */
static inline uint16_t mavlink_msg_solar_clean_comm_get_server_tcp_port(const mavlink_message_t* msg, char *server_tcp_port)
{
    return _MAV_RETURN_char_array(msg, server_tcp_port, 16,  48);
}

/**
 * @brief Decode a solar_clean_comm message into a struct
 *
 * @param msg The message to decode
 * @param solar_clean_comm C-struct to decode the message contents into
 */
static inline void mavlink_msg_solar_clean_comm_decode(const mavlink_message_t* msg, mavlink_solar_clean_comm_t* solar_clean_comm)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_solar_clean_comm_get_wifi_name(msg, solar_clean_comm->wifi_name);
    mavlink_msg_solar_clean_comm_get_wifi_passwd(msg, solar_clean_comm->wifi_passwd);
    mavlink_msg_solar_clean_comm_get_server_ip(msg, solar_clean_comm->server_ip);
    mavlink_msg_solar_clean_comm_get_server_tcp_port(msg, solar_clean_comm->server_tcp_port);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_SOLAR_CLEAN_COMM_LEN? msg->len : MAVLINK_MSG_ID_SOLAR_CLEAN_COMM_LEN;
        memset(solar_clean_comm, 0, MAVLINK_MSG_ID_SOLAR_CLEAN_COMM_LEN);
    memcpy(solar_clean_comm, _MAV_PAYLOAD(msg), len);
#endif
}

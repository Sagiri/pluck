#pragma once

#define B_BUFF_STRING                   0
#define B_BUFF_MOVE                     2
#define B_BUFF_STAT                     5
#define B_BUFF_NEGATIVE_FLAVOR          8

#define B_BUFF_PLACEHOLDER_BEGIN        0xFD
#define B_BUFF_EOS                      0xFF

#define PREPARE_SIMPLE_BUFFER(buffer, variable, value) {    \
    buffer[0] = B_BUFF_PLACEHOLDER_BEGIN;                   \
    buffer[1] = variable;                                   \
    buffer[2] = value;                                      \
    buffer[3] = B_BUFF_EOS;                                 \
}

#define PREPARE_FLAVOR_BUFFER(buffer, flavor) PREPARE_SIMPLE_BUFFER(buffer, B_BUFF_NEGATIVE_FLAVOR, flavor)
#define PREPARE_STAT_BUFFER(buffer, flavor) PREPARE_SIMPLE_BUFFER(buffer, B_BUFF_STAT, flavor)

#define PREPARE_STRING_BUFFER(buffer, string) { \
    buffer[0] = B_BUFF_PLACEHOLDER_BEGIN;       \
    buffer[1] = B_BUFF_STRING;                  \
    buffer[2] = string;                         \
    buffer[3] = (string & 0xFF00) >> 8;         \
    buffer[4] = B_BUFF_EOS;                     \
}

#define PREPARE_MOVE_BUFFER(buffer, move) { \
    buffer[0] = B_BUFF_PLACEHOLDER_BEGIN;   \
    buffer[1] = B_BUFF_MOVE;                \
    buffer[2] = move;                       \
    buffer[3] = (move & 0xFF00) >> 8;       \
    buffer[4] = B_BUFF_EOS;                 \
}

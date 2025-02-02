#include "utils.h"
#include <stdint.h>

void to_le_bytes(uint32_t value, uint8_t **bytes) {
  uint8_t *buffer = (uint8_t *)malloc(sizeof(short) * 5);
  for (unsigned short i = 0; i < 4; i++) {
    buffer[i] = (value >> (8 * i)) & 0xff;
  }
  buffer[4] = 0;
  *bytes = buffer;
}

uint32_t from_le_bytes(uint8_t *bytes) {
  uint32_t val = 0;
  for (unsigned short i = 0; i < 4; i++) {
    val = (val << 8) | bytes[3 - i];
  }
  return val;
}

void to_be_bytes(uint32_t value, uint8_t **bytes) {
  uint8_t *buffer = (uint8_t *)malloc(sizeof(short) * 5);
  for (short i = 3; i > -1; i--) {
    buffer[3 - i] = (value & (0xff << (8 * i))) >> (8 * i);
  }
  buffer[4] = 0;
  *bytes = buffer;
}

uint32_t from_be_bytes(uint8_t *bytes) {
  uint32_t val = 0;
  for (unsigned short i = 0; i < 4; i++) {
    val = (val << 8) | bytes[i];
  }
  return val;
}

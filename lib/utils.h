#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void to_le_bytes(uint32_t value, uint8_t **bytes);
uint32_t from_le_bytes(uint8_t *bytes);

#include "../lib/utils.h"

int main(void) {
  uint32_t val = 234219083;
  uint8_t *le_bytes = NULL;
  uint8_t *be_bytes = NULL;

  to_le_bytes(val, &le_bytes);
  to_be_bytes(val, &be_bytes);

  printf("to le bytes\n");
  for (int i = 0; i < 4; i++)
    printf("%p : %d \n", le_bytes + i, le_bytes[i]);

  printf("to be bytes\n");
  for (int i = 0; i < 4; i++)
    printf("%p : %d \n", be_bytes + i, be_bytes[i]);

  printf("---------------- \n");
  printf(" recompositions  \n");
  printf("---------------- \n");
  uint32_t le_res = from_le_bytes(le_bytes);
  printf("le_bytes: %d \n", le_res);

  uint32_t be_res = from_be_bytes(be_bytes);
  printf("be_bytes: %d \n", be_res);

  free(le_bytes);
  free(be_bytes);

  return 0;
}

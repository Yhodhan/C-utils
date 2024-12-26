#include "../lib/utils.h"

int main(void)
{
    uint32_t val = 234219083;
    uint8_t *bytes = NULL;

    to_le_bytes(val, &bytes);

    for (int i = 0; i < 4; i++)
        printf("%p : %d \n", bytes + i, bytes[i]);

    uint32_t res = from_le_bytes(bytes);

    printf("%d \n", res);

    free(bytes);

    return 0;
}

#include "stddef.h"

#include "kernel/types.h"
#include "user/user.h"

int main() {
  for (int i = 0; i < 4; ++i) {
    printf("mu-ha-ha-ha\n");
    sleep(10);
  }
  return 0;
}

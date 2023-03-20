#include "stddef.h"

#include "kernel/types.h"
#include "user/user.h"

int main() {
  for (int i = 0; i < 4; ++i) {
    sleep(1);
    printf("i'm still sleeping!\n");
    sleep(1);
  }
  return 0;
}

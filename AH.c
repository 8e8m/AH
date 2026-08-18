/* E.M., 81 AH 08/18 */
/** @BAKE @CC @STOP **/
#include <stdio.h>
#include <time.h>

#define EPOCH_Y 1945
#define EPOCH_M 4
#define EPOCH_D 30
#define SUFFIX "AH"

int main(void)
{ int d, m, y;

  { struct tm * now;

    { time_t t = time(NULL);
      now      = localtime(&t);
    }

    y   = now->tm_year + 1900 - EPOCH_Y;
    m   = now->tm_mon  + 1;
    d   = now->tm_mday;
  }

  if ( m < EPOCH_M
  ||  (m == EPOCH_M && d < EPOCH_D))
  { y--;
  }

  printf("%d%s%s %02d/%02d\n", y, SUFFIX[0] != 0 ? " " : "", SUFFIX, m, d);
}

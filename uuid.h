#ifndef UUID_H_A1CI8QWH
#define UUID_H_A1CI8QWH


#include <stdlib.h>

#define UUID4_TEMPLATE "xxxxxxxx-xxxx-4xxx-xxxx-xxxxxxxxxxxx"
#define UUID_CHAR_SET "0123456789abcdef"

#define UUID4(ID, BUF, LEN) \
  for(int _i ## ID = 0; _i ## ID < LEN && _i ## ID < sizeof(UUID4_TEMPLATE); _i ## ID ++){ \
    (BUF)[_i ## ID] = UUID4_TEMPLATE[_i ## ID] == 'x' \
                     ? UUID_CHAR_SET[rand() % (sizeof(UUID_CHAR_SET) - 1)] \
                     : UUID4_TEMPLATE[_i ## ID]; \
  }


#define UUID4_PREDICTABLE(ID, SEED, BUF, LEN) \
  int __rand_seed ## ID = rand(); \
  srand(SEED); \
  UUID4(ID, BUF, LEN); \
  srand(__rand_seed ## ID);



// Create uuid inplace
// Usage:
//
// char arr[sizeof(UUID_TEMPLATE)];
// UUID(just_suffix, arr, sizeof(arr));


#endif /* end of include guard: UUID_H_A1CI8QWH */

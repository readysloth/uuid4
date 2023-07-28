#ifndef UUID_H_A1CI8QWH
#define UUID_H_A1CI8QWH


#define UUID4_TEMPLATE "xxxxxxxx-xxxx-4xxx-xxxx-xxxxxxxxxxxx"
#define UUID_CHAR_SET "0123456789abcdef"

// Taken  from musl

#define _RAND(X) ((6364136223846793005ULL*(X) + 1) >> 33)
#define RAND(SEED, X) ((6364136223846793005ULL*((SEED) ^ _RAND(X)) + 1) >> 33)

#define UUID4(SEED, BUF, LEN) \
  for(int _i ## ID = 0; _i ## ID < LEN && _i ## ID < sizeof(UUID4_TEMPLATE); _i ## ID ++){ \
    (BUF)[_i ## ID] = UUID4_TEMPLATE[_i ## ID] == 'x' \
                     ? UUID_CHAR_SET[RAND(SEED, _i ## ID) % (sizeof(UUID_CHAR_SET) - 1)] \
                     : UUID4_TEMPLATE[_i ## ID]; \
  }


// Create uuid inplace
// Usage:
//
// char arr[sizeof(UUID_TEMPLATE)];
// UUID4(seed, arr, sizeof(arr));


#endif /* end of include guard: UUID_H_A1CI8QWH */

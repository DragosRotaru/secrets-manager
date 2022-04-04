#ifndef EITHER_H
#define EITHER_H

/* Generic Either Type Definition */
#define TypeDefEither(LeftType, RightType, Name) \
    typedef struct { \
        LeftType left; \
        RightType right; \
    } Name;

/* Generic Either Error Type Definition */
#define TypeDefErrEither(RightType, Name) \
    typedef struct { \
        Error left; \
        RightType right; \
    } Name;

// Generic Error Data Type
typedef const struct {
    const int code;
    const char* message;
} Error;

#endif
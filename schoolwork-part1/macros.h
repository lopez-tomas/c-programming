#ifndef MACROS_H
#define MACROS_H

#define ABS(x) (x) == 0 ? 0 : ((x) > 0 ? (x) : -(x))
#define INT_PART(x) (int)(x)
#define DECIMAL_PART(x) (x) - INT_PART(x)
#define IS_NUMBER(c) ( (c) >= '0' && (c) <= '9' )
#define IS_MAYUS(c) ( (c) >= 'A' && (c) <= 'Z' )
#define IS_MINUS(c) ( (c) >= 'a' && (c) <= 'z' )

#define IS_ACCENTED_LETTER(c) ( ( INT_CAST_FOR_CHAR(c) >= 128 && INT_CAST_FOR_CHAR(c) <= 154 ) || \
                                ( INT_CAST_FOR_CHAR(c) >= 160 && INT_CAST_FOR_CHAR(c) <= 165 ) \
                              )

#define IS_GREEK_LETTER(c) ( ( INT_CAST_FOR_CHAR(c) >= 224 && INT_CAST_FOR_CHAR(c) <= 232 ) || \
                               ( INT_CAST_FOR_CHAR(c) == 234 || INT_CAST_FOR_CHAR(c) == 235 ) || \
                               ( INT_CAST_FOR_CHAR(c) == 237 || INT_CAST_FOR_CHAR(c) == 238 ) \
                           )

#define IS_LETTER(c) ( IS_MAYUS(c) || IS_MINUS(c) || IS_ACCENTED_LETTER(c) || IS_GREEK_LETTER(c) )
#define IS_WHITE(c) (c) == ' '
#define TO_MAYUS(c) ( ( (c) >= 'a' && (c) <= 'z' ) ? ( ( (c) - 'a' ) + 'A' ) : (c) )
#define TO_MINUS(c) ( ( (c) >= 'A' && (c) <= 'Z' ) ? ( ( (c) - 'A' ) + 'a' ) : (c) )

int toAbsoluteValue(int x);
int returnIntPart(float x);
float returnDecimalPart(float x);

#endif // MACROS_H

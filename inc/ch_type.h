/************************************************************************************************************
 * char_type -- character type module
 ************************************************************************************************************/
enum CHAR_TYPE {
    C_EOF,           // end of file
    C_WHITE,         // white space or control character
    C_NEWLINE,       // newline character
    C_ALPHA,         // alphabetic character(a-z, A-Z, _)
    C_DIGIT,         // digit(0-9)
    C_OPERATOR,      // Random operator
    C_SLASH,         // '/'
    C_L_PAREN,       // '('
    C_R_PAREN,       // ')'
    C_L_CURLY,       // '{'
    C_R_CURLY,       // '}'
    C_SINGLE,        // single quote
    C_DOUBLE,        // double quote
    C_HEX_DIGIT,     // hex digit(0-9, a-f, A-F)
    C_ALPHA_NUMERIC  // alpha numeric character
};

/************************************************************************************************************
 * is_char_type -- check character type
 *
 * Parameters
 *     ch -- character to check
 *     kind -- type to check for
 *
 * Returns
 *     1 if character is of the specified type, else 0
 ************************************************************************************************************/
extern int is_char_type(char ch, enum CHAR_TYPE kind);

/************************************************************************************************************
 * get_char_type -- get character type
 *
 * Warning
 *     This function returns a simple character type.
 *     It does not return a compound type such as C_ALPHA_NUMERIC.
 *
 * Parameters
 *     ch -- character to check
 *
 * Returns
 *     character type
 ************************************************************************************************************/
extern enum CHAR_TYPE get_char_type(char ch);
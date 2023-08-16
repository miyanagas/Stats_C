#include "../inc/ch_type.h"

#include <stdio.h>
#include <stdlib.h>

static enum CHAR_TYPE type_info[256];
static int ch_setup = 0;

/**********************************************************************
 * fill_range -- fill a range of the type_info array
 *
 * Parameters
 *     start, end -- the range to fill
 *     type -- the type to fill the range with
 **********************************************************************/
static void fill_range(int start, int end, enum CHAR_TYPE type) {
    int cur_ch;

    for (cur_ch = start; cur_ch <= end; ++cur_ch) {
        type_info[cur_ch] = type;
    }
}

/**********************************************************************
 * init_char_type -- initialize the type_info array
 **********************************************************************/
static void init_char_type(void) {
    fill_range(0, 255, C_WHITE);

    fill_range('A', 'Z', C_ALPHA);
    fill_range('a', 'z', C_ALPHA);
    type_info['_'] = C_ALPHA;

    fill_range('0', '9', C_DIGIT);

    type_info['!'] = C_OPERATOR;
    type_info['#'] = C_OPERATOR;
    type_info['$'] = C_OPERATOR;
    type_info['%'] = C_OPERATOR;
    type_info['^'] = C_OPERATOR;
    type_info['&'] = C_OPERATOR;
    type_info['*'] = C_OPERATOR;
    type_info['-'] = C_OPERATOR;
    type_info['+'] = C_OPERATOR;
    type_info['='] = C_OPERATOR;
    type_info['|'] = C_OPERATOR;
    type_info['~'] = C_OPERATOR;
    type_info[','] = C_OPERATOR;
    type_info[':'] = C_OPERATOR;
    type_info['?'] = C_OPERATOR;
    type_info['.'] = C_OPERATOR;
    type_info['<'] = C_OPERATOR;
    type_info['>'] = C_OPERATOR;

    type_info['/'] = C_SLASH;
    type_info['\n'] = C_NEWLINE;

    type_info['('] = C_L_PAREN;
    type_info[')'] = C_R_PAREN;

    type_info['{'] = C_L_CURLY;
    type_info['}'] = C_R_CURLY;

    type_info['"'] = C_DOUBLE;
    type_info['\''] = C_SINGLE;
}

int is_char_type(int ch, enum CHAR_TYPE kind) {
    if (!ch_setup) {
        init_char_type();
        ch_setup = 1;
    }

    if (ch == EOF) {
        return (kind == C_EOF);
    }

    if (kind == C_HEX_DIGIT) {
        if (type_info[ch] == C_DIGIT) {
            return (1);
        } else if (ch >= 'A' && ch <= 'F') {
            return (1);
        } else if (ch >= 'a' && ch <= 'f') {
            return (1);
        } else {
            return (0);
        }
    }

    if (kind == C_ALPHA_NUMERIC) {
        return (type_info[ch] == C_ALPHA || type_info[ch] == C_DIGIT);
    }

    return (type_info[ch] == kind);
}

enum CHAR_TYPE get_char_type(int ch) {
    if (!ch_setup) {
        init_char_type();
        ch_setup = 1;
    }

    if (ch == EOF) {
        return (C_EOF);
    }

    return (type_info[ch]);
}
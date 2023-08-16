/********************************************************************
 * in_open -- open a file for input
 *
 * Parameters
 *     name -- name of file to open
 *
 * Returns
 *     0 if successful, 1 if not
 ********************************************************************/
extern int in_open(const char name[]);
/********************************************************************
 * in_close -- close the input file
 ********************************************************************/
extern void in_close(void);
/********************************************************************
 * in_read_char -- read the next character from the input file
 ********************************************************************/
extern void in_read_char(void);
/********************************************************************
 * in_cur_char -- return the current character
 *
 * Returns
 *     the current character
 ********************************************************************/
extern int in_cur_char(void);
/********************************************************************
 * in_next_char -- return the next character
 *
 * Returns
 *     the next character
 ********************************************************************/
extern int in_next_char(void);
/********************************************************************
 * in_flush -- flush the input buffer to stdout
 ********************************************************************/
extern void in_flush(void);
/*
 * fcl.beacon project
 * FILE bc_logging.h
 * DATE 2014/12/04
 * AUTHOR Arden Zhao
 *
 * */

#ifndef __BC_LOGGING_H__
#define __BC_LOGGING_H__

#include <stdio.h>
#include "log4c.h"

// need to create new default category for each process.
#define BC_LOG_CATEGORY(category) LOG_NEW_DEFAULT_CATEGORY(category);


/*
 * INIT LOG
 * FILE* should be return from fopen with mode "a"
 * priority value is based on LP_* define
 * if to_stderr larger than 0, print log to stderr also.
 * */
void bc_log_init(FILE* file, int priority, int to_stderr);


/*
 * CREATE NEW SUB CATEGORY
 * */
#define BC_LOG_NEW_SUBCATEGORY(category) LOG_NEW_SUBCATEGORY(category, beacon)

/*
 * MAIN FUNCTION CALL FOR WRITE LOG
 * this may not easy to use because we have to prepar full massage before invoke it.
 * like log4c, we may need bc_log3, bc_log4 which accept format string.
 * */
void bc_log(int priority, const char* msg);


/*
 * LOG TRACE
 * */
void bc_log_trace(const char* msg);


/*
 * LOG DEBUG
 * */
void bc_log_debug(const char* msg);


/*
 * LOG INFO
 * */
void bc_log_info(const char* msg);


/*
 * LOG WARNING
 * */
void bc_log_warning(const char* msg);


/*
 * LOG ERROR
 * */
void bc_log_error(const char* msg);




/*
 * RELEASE LOG FILE
 * FOR NOW THERE IS NOTHING TO BE DONE FOR CLOSE.
 * */
void bc_log_close();

#endif /* __BC_LOGGING_H__ */

/*
 * fcl.beacon project
 * FILE bc_logging.h
 * DATE 2014/12/04
 * AUTHOR Arden Zhao
 *
 * */

#ifndef __BC_LOGGING_H__
#define __BC_LOGGING_H__

#include "log4c.h"

// make default log category for beacon, for now i didn't see any sub category needed.
LOG_NEW_DEFAULT_CATEGORY(beacon);


/*
 * INIT LOG WITH FILE NAME
 * */
void bc_log_init(const char* path);

/*
 * SET CONFIG STRING LIKE THRESHOLD LEVEL
 * */
void bc_log_set(const char* config);


/*
 * MAIN FUNCTION CALL FOR WRITE LOG
 * this may not easy to use because we have to prepar full massage before invoke it.
 * like log4c, we may need bc_log3, bc_log4 which accept format string.
 * */
void bc_log(int priority, const char* msg);


/*
 * RELEASE LOG FILE
 * */
void bc_log_close();

#endif /* __BC_LOGGING_H__ */

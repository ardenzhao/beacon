/*
 * fcl.beacon project
 * 
 * FILE test_logging.c
 * DATE 2015/12/18
 * AUTHOR Arden Zhao
 *
 * */


#include "../logging/bc_logging.h"

void test_logging(int priority)
{
    FILE* log_file = fopen("bc_test.log","a");
    bc_log_init(log_file, priority, 1);
    
    bc_log_trace("logging trace.");
    bc_log_debug("logging debug.");
    bc_log_info("logging info.");
    bc_log_warning("logging warning");
    bc_log_error("logging error");
    
    bc_log(LP_TRACE, "logging trace from bc_log");
    bc_log(LP_DEBUG, "logging debug from bc_log");
    bc_log(LP_INFO, "logging info from bc_log");
    bc_log(LP_WARNING, "logging warning from bc_log");
    bc_log(LP_ERROR, "logging error from bc_log");

    fclose(log_file);
}


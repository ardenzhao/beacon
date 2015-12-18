/*
 * fcl.beacon project 
 * FILE bc_logging.c
 * DATE 2015/12/18
 * AUTHOR Arden Zhao
 *
 * */

#include "bc_logging.h"
#include <time.h>

BC_LOG_CATEGORY(beacon);

/*
 * BEACON LOGGING APPENDER FOR LOG4C LIBRARY
 *
 */

static char* priority_names[] = {
    "NONE",
    "TRACE",
    "DEBUG",
    "INFO",
    "NOTICE",
    "WARNING",
    "ERROR",
    "CRITICAL ERROR",
    "ALERT",
    "EMERGENCY",
};

static void doAppend(struct LogAppender* this, struct LogEvent* ev);

static struct bc_log_appender {
    struct LogAppender appender;
    FILE* file;
    int to_stderr;
} bc_log_appender = { {doAppend}, NULL, 1};

struct LogAppender* log_defaultLogAppender = &bc_log_appender.appender;

// controls how beacon logging works
static void doAppend(struct LogAppender* this0, struct LogEvent* ev)
{
    // beacon log format string
    char format_buf[64];
    char format_time[32];
    time_t raw_time;
    struct tm* time_info;
    int priority = 0;

    // get default log appender
    struct bc_log_appender* this = (struct bc_log_appender*)this0;
    if(this->file == NULL) this->file = stderr;

    time(&raw_time);
    time_info =localtime(&raw_time);
    strftime(format_time, 32, "%Y-%m-%d %H:%M:%S", time_info);

    priority = ev->priority;
    if(priority < 0 ) priority =0;

    // 10 is value of sizeof(priority_names) 
    if(priority >= 10)
    {
        priority = 9;
    }

    sprintf(format_buf, "%s [%s]: ", format_time, priority_names[priority]);

    if(this->to_stderr >0 && this->file != stderr)
    {
        fprintf(stderr, "%s", format_buf);
        fprintf(stderr, "%s:%d ", ev->fileName, ev->lineNum);
        vfprintf(stderr, ev->fmt, ev->ap);
        fprintf(stderr, "\n");
    }
    
    fprintf(this->file, "%s", format_buf);
    fprintf(this->file, "%s:%d ", ev->fileName, ev->lineNum);
    vfprintf(this->file, ev->fmt, ev->ap);
    fprintf(this->file, "\n");

}

void bc_log_init(FILE* file, int priority, int to_stderr)
{
    bc_log_appender.file = file;
    bc_log_appender.to_stderr = to_stderr;
    char buf[32];
    sprintf(buf, "beacon.thresh=%d", priority);
    log_setControlString(buf);
}


void bc_log(int priority, const char* msg)
{
    switch(priority)
    {
        case LP_TRACE:
            bc_log_trace(msg);
            break;
        case LP_DEBUG:
            bc_log_debug(msg);
            break;
        case LP_INFO:
            bc_log_info(msg);
            break;
        case LP_WARNING:
            bc_log_warning(msg);
            break;
        case LP_ERROR:
            bc_log_error(msg);
            break;
        default:
            break;
    }
}

void bc_log_trace(const char* msg)
{
    TRACE1(msg);    
}

void bc_log_debug(const char* msg)
{
    DEBUG1(msg);
}

void bc_log_info(const char* msg)
{
    INFO1(msg);
}

void bc_log_warning(const char* msg)
{
    WARNING1(msg);
}

void bc_log_error(const char* msg)
{
    ERROR1(msg);
}

void bc_log_close()
{

}




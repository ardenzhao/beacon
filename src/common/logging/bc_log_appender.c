/*
 * fcl.beacon project
 * FILE bc_log_appender.c
 * DATE 2015/01/07
 * AUTHOR Arden Zhao
 * 
 * */

#include "log4c.h"
#include <stdio.h>
#include <time.h>

/*
 * beacon logging appender for log4c library
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
} bc_log_appender = { {doAppend }, NULL };

struct LogAppender* log_defaultLogAppender = &bc_log_appender.appender;

// controls how beacon logging works
static void doAppend(struct LogAppender* this0, struct LogEvent* ev) {
    
    // beacon log format string
    char format_buf[64];
    char format_time[32];
    time_t raw_time;
    struct tm* time_info;
    int priority = 0;
    
    // get default log appender
    struct bc_log_appender* this  = (struct bc_log_appender*)this0;
    if(this->file == NULL) this->file = stderr;
    
    time(&raw_time);
    time_info = localtime(&raw_time);
    strftime(format_time, 32, "%Y-%m-%d %H:%M:%S", time_info);

    priority = ev->priority;
    if(priority < 0) priority = 0;
    
    if(priority >= sizeof(priority_names)){
        priority = sizeof(priority_names)-1;
    }

    sprintf(format_buf, "%s [%s]: ", format_time, priority_names[ev->priority]); 
    
    // not sure what is the best way to handle FILE* ...
    fprintf(this->file, "%s", format_buf);
    fprintf(this->file, "%s:%d", ev->fileName, ev->lineNum);
    vfprintf(this->file, ev->fmt, ev->ap);
    fprintf(this->file, "\n");
    
}




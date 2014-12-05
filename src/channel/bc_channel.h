/*
 * fcl.beacon project
 * 
 * FILE bc_channel.h
 * DATE 2014/12/05
 * AUTHOR Arden Zhao
 *
 * */

#ifndef __BC_CHANNEL_H__
#define __BC_CHANNEL_H__

// beacon channel publisher option code

#define BCPO_ADDRESS         1
#define BCPO_PORT            2
#define BCPO_MODE            3
#define BCPO_ADAPTOR_ADDRESS 4
#define BCPO_ADAPTOR_PORT    5

#define BCP_MODE_DIRECT      1 // subscriber connect to publisher directly
#define BCP_MODE_ADAPTOR     2 // subscriber talk with publisher through adaptor 


// beacon channel publisher 
void* bc_create_publisher(void);
int   bc_set_publisher(int option, const char* value);
int   bc_start_publisher(void* channel);
int   bc_term_publisher(void* channel);

// beacon channel subscriber
void* bc_create_subscriber(void);
int   bc_set_subscriber(int option, const char* value);
int   bc_start_subscriber(void* channel);
int   bc_term_subscriber(void* channel);

// beacon channel adaptor



#endif /* __BC_CHANNEL_H__ */

#ifndef _sendermodel_H
#define _sendermodel_H
#ifndef _SENDERMODEL_H // necessary for arduino-cli, which automatically includes headers that are not used
#ifndef TOP_LEVEL_PREAMBLE_2086853935_H
#define TOP_LEVEL_PREAMBLE_2086853935_H
/*Correspondence: Range: [(3, 4), (30, 32)) -> Range: [(0, 0), (27, 32)) (verbatim=true; src=c:\Users\Amin\Desktop\RT\project\sender-receiver-LF\sender-receiver-LF\src\senderreceiver.lf)*/#include <stdlib.h>
typedef enum {
    STATE_A = 0, STATE_B = 1,
    STATE_C = 2, STATE_D = 3,
    STATE_E = 4, STATE_F = 5,
    STATE_G = 6, STATE_H = 7
} SenderModelState;

typedef enum {
    STATE_IDLE  = 0,
    STATE_LAST1 = 1,
    STATE_LAST2 = 2
} ReceiverModelState;

// queue_ss_t structure for Enq operation
typedef struct {
    int* items;
    int front;
    int rear;
    int capacity;
} queue_ss_t;

queue_ss_t* createQueue(int capacity);
void enqueue(queue_ss_t* queue, int value);
int dequeue(queue_ss_t* queue);
int get_front(queue_ss_t* queue);
void deleteQueue(queue_ss_t* queue);
int is_empty(queue_ss_t* queue);
#endif
#ifdef __cplusplus
extern "C" {
#endif
#include "../include/api/schedule.h"
#include "../include/core/reactor.h"
#ifdef __cplusplus
}
#endif
typedef struct sendermodel_self_t{
    self_base_t base; // This field is only to be used by the runtime, not the user.
    int* sequence;
    int length;
    int m;
    int x;
    int started;
    interval_t step;
    SenderModelState currState;
    queue_ss_t* queue;
    int end[0]; // placeholder; MSVC does not compile empty structs
} sendermodel_self_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    int value;
    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} sendermodel_in_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    int value;
    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} sendermodel_up_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    int value;
    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} sendermodel_down_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_action_internal_t _base;
    self_base_t* parent;
    bool has_value;
    int source_id;

    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} sendermodel_a_t;
#endif
#endif

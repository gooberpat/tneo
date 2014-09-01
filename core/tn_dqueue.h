/*******************************************************************************
 *   Description:   TODO
 *
 ******************************************************************************/

#ifndef _TN_DQUEUE_H
#define _TN_DQUEUE_H

/*******************************************************************************
 *    INCLUDED FILES
 ******************************************************************************/

#include "tn_utils.h"

/*******************************************************************************
 *    PUBLIC TYPES
 ******************************************************************************/

struct TNDQueue {
   struct TNQueueHead  wait_send_list;
   struct TNQueueHead  wait_receive_list;

   void ** data_fifo;   //-- Array of void* to store data queue entries
   int  num_entries;    //-- Capacity of data_fifo(num entries)
   int  tail_cnt;       //-- Counter to processing data queue's Array of void*
   int  header_cnt;     //-- Counter to processing data queue's Array of void*
   int  id_dque;        //-- ID for verification(is it a data queue or another object?)
   // All data queues have the same id_dque magic number (ver 2.x)
};


/*******************************************************************************
 *    GLOBAL VARIABLES
 ******************************************************************************/

/*******************************************************************************
 *    DEFINITIONS
 ******************************************************************************/

/*******************************************************************************
 *    PUBLIC FUNCTION PROTOTYPES
 ******************************************************************************/

int tn_queue_create(struct TNDQueue * dque,
      void ** data_fifo,
      int num_entries);
int tn_queue_delete(struct TNDQueue * dque);
int tn_queue_send(struct TNDQueue * dque, void * data_ptr, unsigned long timeout);
int tn_queue_send_polling(struct TNDQueue * dque, void * data_ptr);
int tn_queue_isend_polling(struct TNDQueue * dque, void * data_ptr);
int tn_queue_receive(struct TNDQueue * dque, void ** data_ptr, unsigned long timeout);
int tn_queue_receive_polling(struct TNDQueue * dque, void ** data_ptr);
int tn_queue_ireceive(struct TNDQueue * dque, void ** data_ptr);


#endif // _TN_DQUEUE_H

/*******************************************************************************
 *    end of file
 ******************************************************************************/



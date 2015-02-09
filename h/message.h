/** 
 *    @file      SmsAckResponse.h
 *    @details   This IPC Message represents the ack result of a generic SMS sending.
 *    @author    scolonna
 *    @version   1.0
 *    @phase     1.0
 *    @status    Proposed
 *    @copyright (C) Copyright Magneti Marelli
 *
 *    This file has been generated automatically by the MM Embedded CPP-Generator System
 *    Database Object = {7BF59E7A-2136-4b76-BAF9-F10959D70CEB} 
 *    Database Object Type = DataType  
 *    Wed, 22 Oct 2014 15:31:15 +0200
 */ 
 
#ifndef _MESSAGE_H_
#define _MESSAGE_H__

    /*
     * @struct SmsAckResponse
     * @brief This IPC Message represents the ack result of a generic SMS sending.
     */
    typedef struct 
    {
    	int header; /*!<  */ 
	    char[10] payload; /*!<  */ 
	template <typename Archive>
	void serialize(Archive& ar, const unsigned int version)
	{
		ar & header;
		ar & payload;
	}
} Message;
#endif 

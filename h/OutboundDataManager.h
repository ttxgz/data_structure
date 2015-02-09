/** 
 *    @file      OutboundDataManager.h
 *    @details   
 *    @author    zliao
 *    @version   1.0
 *    @phase     1.0
 *    @status    Proposed
 *    @copyright (C) Copyright Magneti Marelli
 *
 *    This file has been generated automatically by the MM Embedded CPP-Generator System
 *    Database Object = {9C998FCC-34C7-4f19-8BC2-7B0D69C324F7} 
 *    Database Object Type = Class  
 *    Tue, 21 Oct 2014 13:46:39 +0200
 */ 
 
#ifndef OUTBOUNDDATAMANAGER_
#define OUTBOUNDDATAMANAGER_


//-------- TYPES INCLUDES
#include "Application_Active_Message.h"
#include "StartCall.h"
#include "SetSMS.h"
#include "LEDManagement_Message.h"
#include "PlayVocalFeedbackMessage.h"
#include "CancelCall.h"
#include "GoToSpyMode.h"
#include "SetLEDStatus.h"
#include <mqueue.h>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/array.hpp>
#include <boost/bind.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/thread.hpp>

//-------- MESSAGES INCLUDES
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>
#include <boost/asio.hpp>
#include <string>
#include <arpa/inet.h>
using boost::asio::local::stream_protocol;

/**
 * @class OutboundDataManager
 * 
 * @brief 
 */
class OutboundDataManager 
{
public:
	OutboundDataManager();
	OutboundDataManager(std::string inputChannel, std::string outputChannel);
	void operator()();
protected:
	std::string inputChannel;
	std::string outputChannel;
};
#endif 

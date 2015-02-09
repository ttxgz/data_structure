/** 
 *    @file      InboundDataManager.h
 *    @details   
 *    @author    zliao
 *    @version   1.0
 *    @phase     1.0
 *    @status    Proposed
 *    @copyright (C) Copyright Magneti Marelli
 *
 *    This file has been generated automatically by the MM Embedded CPP-Generator System
 *    Database Object = {7A89CE29-2E49-4bf3-825C-4722B5997B16} 
 *    Database Object Type = Class  
 *    Tue, 21 Oct 2014 13:46:39 +0200
 */ 
 
#ifndef INBOUNDDATAMANAGER_
#define INBOUNDDATAMANAGER_


//-------- TYPES INCLUDES
#include "VocalFeedbackResponseMessage.h"
#include "CancelCallResponse.h"
#include "AutomaticCrashNotification_Message.h"
#include "IncomingVoiceCall.h"
#include "MsdAckResponse.h"
#include "IncomingSMS.h"
#include "CallStatusMessage.h"
#include "ButtonStatus_Message.h"
#include "GPS_FIXED_POSITION_message.h"
#include "SmsAckResponse.h"
#include <mqueue.h>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/array.hpp>
#include <boost/bind.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/thread.hpp>

//-------- MESSAGES INCLUDES

//-------- Shared Library INCLUDES
#include "ActivateOrchestrator.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>
#include <boost/asio.hpp>
#include <string>
#include <arpa/inet.h>
class InboundDataManager;



// ----- SESSION CLASS -----

using boost::asio::local::stream_protocol;

class InboundDataManagerSession: public boost::enable_shared_from_this<InboundDataManagerSession> { 

	public:
		InboundDataManagerSession(boost::asio::io_service& io_service,InboundDataManager *parent);
		stream_protocol::socket& socket();
		void start();
		void handle_read(const boost::system::error_code& error,size_t bytes_transferred);
		void handle_write(const boost::system::error_code& error);

	private:
		stream_protocol::socket socket_;
		boost::array<char, 1024> data_;
		std::string outputChannel;
		InboundDataManager *parent_class;
};

typedef boost::shared_ptr<InboundDataManagerSession> InboundDataManagerSessionPtr;


// ----- END SESSION CLASS -----


/**
 * @class InboundDataManager
 * 
 * @brief 
 */
class InboundDataManager 
{
public:
	InboundDataManager(boost::asio::io_service& io_service, const std::string& inputChannel, std::string outputChannel);
	void handle_accept(InboundDataManagerSessionPtr new_session,const boost::system::error_code& error);
	std::string getOutputChannel();
protected:
	boost::asio::io_service& io_service_;
	stream_protocol::acceptor acceptor_;
	std::string inputChannel;
	std::string outputChannel;
};
#endif 

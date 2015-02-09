/** 
 *    @file      InboundDataManager.cpp
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
 
// Inclusion of the header file of the class
#include "InboundDataManager.h"


//-------- Shared Library Namespace

// ----- SESSION SOURCE CLASS -----
InboundDataManagerSession::InboundDataManagerSession(boost::asio::io_service& io_service, InboundDataManager *parent): socket_(io_service)
{
	this->parent_class = parent;
	this->outputChannel = this->parent_class->getOutputChannel();
}
stream_protocol::socket& InboundDataManagerSession::socket()
{
	return socket_;
}
void InboundDataManagerSession::start(){
	socket_.async_read_some(boost::asio::buffer(data_), boost::bind(&InboundDataManagerSession::handle_read, shared_from_this(), boost::asio::placeholders::error,boost::asio::placeholders::bytes_transferred));
}
void InboundDataManagerSession::handle_read(const boost::system::error_code& error, size_t bytes_transferred)
{
	mqd_t mqd;
	int ret;
	uint16_t messageID_;
	// Serialization Management
	std::stringstream iss;
	std::string serialized_string(data_.begin(), data_.end());
	iss << serialized_string;
	boost::archive::text_iarchive ia(iss);
	ia >> messageID_;

	mqd = mq_open(this->outputChannel.c_str(),  O_CREAT | O_WRONLY, (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH), NULL);
	if(mqd < 0) {
		printf ("Cannnot open posix queue: %s",strerror(errno));
	} else {
		bool doSend = true;
		switch(messageID_) {
			case 9902:
			{
				VocalFeedbackResponseMessage VocalFeedbackResponseMessageData;
				ia >> VocalFeedbackResponseMessageData;
				doSend = true;
				// start protected area 4032ac37eb94966d0339b27d15f1a8d9e13506a6ece62869f052b1b09e9f1412;
				// end protected area 4032ac37eb94966d0339b27d15f1a8d9e13506a6ece62869f052b1b09e9f1412;
				if (doSend) {
					ret = mq_send(mqd, serialized_string.data(), strlen(serialized_string.c_str())+1, 5);
					if(ret<0) {
						printf ("Can't send message with id 9902: %s",strerror(errno));
					}
				}

			break;

			}
			case 7012:
			{
				CancelCallResponse CancelCallResponseData;
				ia >> CancelCallResponseData;
				doSend = true;
				// start protected area 0a1b69e7c196a82543241b033c96c14ec472dd46b985c032d7540333454c6356;
				// end protected area 0a1b69e7c196a82543241b033c96c14ec472dd46b985c032d7540333454c6356;
				if (doSend) {
					ret = mq_send(mqd, serialized_string.data(), strlen(serialized_string.c_str())+1, 5);
					if(ret<0) {
						printf ("Can't send message with id 7012: %s",strerror(errno));
					}
				}

			break;

			}
			case 10010:
			{
				AutomaticCrashNotification_Message AutomaticCrashNotification_MessageData;
				ia >> AutomaticCrashNotification_MessageData;
				doSend = true;
				// start protected area af42033fd6bd88fa40ead448095e2bdeee8f752c1de274130791160d59458028;
				// end protected area af42033fd6bd88fa40ead448095e2bdeee8f752c1de274130791160d59458028;
				if (doSend) {
					ret = mq_send(mqd, serialized_string.data(), strlen(serialized_string.c_str())+1, 10);
					if(ret<0) {
						printf ("Can't send message with id 10010: %s",strerror(errno));
					}
				}

			break;

			}
			case 7006:
			{
				IncomingVoiceCall IncomingVoiceCallData;
				ia >> IncomingVoiceCallData;
				doSend = true;
				// start protected area 541d9f7a333d5470f7478010bbd1e81d10a70357aec0760fdb54db5e276c3317;
				// end protected area 541d9f7a333d5470f7478010bbd1e81d10a70357aec0760fdb54db5e276c3317;
				if (doSend) {
					ret = mq_send(mqd, serialized_string.data(), strlen(serialized_string.c_str())+1, 5);
					if(ret<0) {
						printf ("Can't send message with id 7006: %s",strerror(errno));
					}
				}

			break;

			}
			case 7019:
			{
				MsdAckResponse MsdAckResponseData;
				ia >> MsdAckResponseData;
				doSend = true;
				// start protected area 562c0259617296d034dc400a99abe29e0441108cf256c728a7af0e7a9a00cdf7;
				// end protected area 562c0259617296d034dc400a99abe29e0441108cf256c728a7af0e7a9a00cdf7;
				if (doSend) {
					ret = mq_send(mqd, serialized_string.data(), strlen(serialized_string.c_str())+1, 5);
					if(ret<0) {
						printf ("Can't send message with id 7019: %s",strerror(errno));
					}
				}

			break;

			}
			case 7003:
			{
				IncomingSMS IncomingSMSData;
				ia >> IncomingSMSData;
				doSend = true;
				// start protected area 867f6873f6e83ae504c36b814023b33973b484631b83f868050bef8f1a8d906a;
				// end protected area 867f6873f6e83ae504c36b814023b33973b484631b83f868050bef8f1a8d906a;
				if (doSend) {
					ret = mq_send(mqd, serialized_string.data(), strlen(serialized_string.c_str())+1, 5);
					if(ret<0) {
						printf ("Can't send message with id 7003: %s",strerror(errno));
					}
				}

			break;

			}
			case 7007:
			{
				CallStatusMessage CallStatusMessageData;
				ia >> CallStatusMessageData;
				doSend = true;
				// start protected area a9961ff6dc0701cb15a0f4dba86bbe4a9047fbd1c9a7ed014e17c89979fae86c;
				std::cout << "CallStatusMessageData.payload.status: " << CallStatusMessageData.payload.status << "  @Zita:" << __FILE__ << ":" << __LINE__ << ":" << __func__ << std::endl;
				// end protected area a9961ff6dc0701cb15a0f4dba86bbe4a9047fbd1c9a7ed014e17c89979fae86c;
				if (doSend) {
					ret = mq_send(mqd, serialized_string.data(), strlen(serialized_string.c_str())+1, 5);
					if(ret<0) {
						printf ("Can't send message with id 7007: %s",strerror(errno));
					}
				}

			break;

			}
			case 10001:
			{
				ButtonStatus_Message ButtonStatus_MessageData;
				ia >> ButtonStatus_MessageData;
				doSend = true;
				// start protected area 1d57dd83c7cf512f7da7a3f845c7dfe397f6b97e92974eaf7911ddf44f87c3f7;
				std::cout << "receive IPC ButtonStatus_Message" << "\tBY zita debug: " << __FILE__ << " : " << __LINE__ << " : " << __func__ << std::endl;
				// end protected area 1d57dd83c7cf512f7da7a3f845c7dfe397f6b97e92974eaf7911ddf44f87c3f7;
				if (doSend) {
					ret = mq_send(mqd, serialized_string.data(), strlen(serialized_string.c_str())+1, 15);
					if(ret<0) {
						printf ("Can't send message with id 10001: %s",strerror(errno));
					}
				}

			break;

			}
			case 15002:
			{
				GPS_FIXED_POSITION_message GPS_FIXED_POSITION_messageData;
				ia >> GPS_FIXED_POSITION_messageData;
				doSend = true;
				// start protected area 65b3e4a98589f74c5c3b7fbe70e012450645d16254047108bde8a1afda592b9b;
				// end protected area 65b3e4a98589f74c5c3b7fbe70e012450645d16254047108bde8a1afda592b9b;
				if (doSend) {
					ret = mq_send(mqd, serialized_string.data(), strlen(serialized_string.c_str())+1, 5);
					if(ret<0) {
						printf ("Can't send message with id 15002: %s",strerror(errno));
					}
				}

			break;

			}
			case 7002:
			{
				SmsAckResponse SmsAckResponseData;
				ia >> SmsAckResponseData;
				doSend = true;
				// start protected area 7777fd19f120548db85dcb8da39f39360a04ebe8fa967a45ebd9d81d5d61bc78;
				// end protected area 7777fd19f120548db85dcb8da39f39360a04ebe8fa967a45ebd9d81d5d61bc78;
				if (doSend) {
					ret = mq_send(mqd, serialized_string.data(), strlen(serialized_string.c_str())+1, 5);
					if(ret<0) {
						printf ("Can't send message with id 7002: %s",strerror(errno));
					}
				}

			break;

			}
			default:
			{
				// start protected area acd36a9abbf8891d4e264b9d47e9b7a84e22e547f5b47091dd1d9b5609cc8692;
				std::cout << "receive undetailed IPC in InboundMngr ( " << messageID_ << " ), send to STM anyway" << std::endl;
				ret = mq_send(mqd, serialized_string.data(), strlen(serialized_string.c_str())+1, 5);
				if(ret<0) {
					printf ("Can't send message with id 7002: %s",strerror(errno));
				}
				// end protected area acd36a9abbf8891d4e264b9d47e9b7a84e22e547f5b47091dd1d9b5609cc8692;
			break;
			}
		}
		serialized_string.clear();
		serialized_string.resize(1024);
		iss.str(std::string());
	}
	ret = mq_close(mqd);
	if (!error)
	{
		boost::asio::async_write(socket_,boost::asio::buffer(data_, bytes_transferred), boost::bind(&InboundDataManagerSession::handle_write, shared_from_this(), boost::asio::placeholders::error));
	}
}
void InboundDataManagerSession:: handle_write(const boost::system::error_code& error)
{
}


// ----- END SESSION CLASS -----

std::string InboundDataManager::getOutputChannel()
{
	return this->outputChannel;
}
void InboundDataManager::handle_accept(InboundDataManagerSessionPtr new_session,const boost::system::error_code& error)
{
	std::cout << "HANDLE ACCEPT";
	if (!error)
	{
		new_session->start();
	}
	new_session.reset(new InboundDataManagerSession(io_service_, this));
	acceptor_.async_accept(new_session->socket(),boost::bind(&InboundDataManager::handle_accept, this, new_session, boost::asio::placeholders::error));
}
InboundDataManager::InboundDataManager(boost::asio::io_service& io_service, const std::string& inputChannel = "/ecall_in", std::string outputChannel = "/ecall_stm"): io_service_(io_service), acceptor_(io_service, stream_protocol::endpoint(inputChannel))
{
	this->inputChannel = inputChannel;
	this->outputChannel = outputChannel;
	InboundDataManagerSessionPtr new_session(new InboundDataManagerSession(io_service_, this));
	acceptor_.async_accept(new_session->socket(),boost::bind(&InboundDataManager::handle_accept, this, new_session,boost::asio::placeholders::error));
	// start protected area 26dd57fd0f13593e4f1755ba92df4c16031bfa2fa0db24b72bf49cf446b7c0c1;
	std::cout << "inputChannel is : " << inputChannel << "@Zita" << __FILE__ << ":" << __LINE__ << ":" << __func__ << std::endl;
	std::cout << "outputChannel is : " << outputChannel << "@Zita" << __FILE__ << ":" << __LINE__ << ":" << __func__ << std::endl;
	std::cout << "send ActivateOrchestrator to STM" << "@Zita" << __FILE__ << ":" << __LINE__ << ":" << __func__ << std::endl;
	mqd_t mqd;
	mqd = mq_open(this->outputChannel.c_str(),  O_CREAT | O_WRONLY, (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH), NULL);
	std::stringstream oss;
   	boost::archive::text_oarchive oa(oss);
	uint16_t message_ID = 11104;
	ActivateOrchestrator ActivateOrchestratorData;
    oa << message_ID;
    oa << ActivateOrchestratorData;
    std::string serialized_string(oss.str());
	
	mq_send(mqd, serialized_string.data(), strlen(serialized_string.c_str())+1, 5);
	
	mq_close(mqd);

	// end protected area 26dd57fd0f13593e4f1755ba92df4c16031bfa2fa0db24b72bf49cf446b7c0c1;
}

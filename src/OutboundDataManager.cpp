/** 
 *    @file      OutboundDataManager.cpp
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
 
// Inclusion of the header file of the class
#include "OutboundDataManager.h"

void OutboundDataManager::operator()() {
	mqd_t mqd;
	struct mq_attr attr;
	int ret;
	std::stringstream iss;
	std::string serialized_string;
	serialized_string.resize(1024);

	// start protected area a82248ed6903df0bd9a008bc309015a1cc5792df8efe4e56f043d86ce6fe7f97;
	std::cout << "outputChannel is : " << this->outputChannel << "  @Zita: " << __FILE__ << ":" << __LINE__ << ":" << __func__ << std::endl;
	// Socket Client Management
/*
	boost::asio::io_service io_service;
	stream_protocol::socket s(io_service);
	s.connect(stream_protocol::endpoint(this->outputChannel));
*/
	//std::cout << "  not connecting to outbound socket !!@Zita: " << __FILE__ << ":" << __LINE__ << ":" << __func__ << std::endl;

	// end protected area a82248ed6903df0bd9a008bc309015a1cc5792df8efe4e56f043d86ce6fe7f97;
	/* Form the queue attributes */
	attr.mq_flags = 0; /* i.e mq_send will be block if message queue is full */
	attr.mq_maxmsg = 10;
	attr.mq_msgsize = 1024;
	attr.mq_curmsgs = 0; /* mq_curmsgs is dont care */
	/* Open/Create message queue */
	mqd = mq_open(this->inputChannel.c_str(), O_RDONLY | O_CREAT, (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH), &attr);
	if( mqd != (mqd_t)-1 )
	{
		uint16_t messageID_;
		bool doLoop = true;
		bool doSend = true;
		while( doLoop )
		{
			mq_receive(mqd, &serialized_string[0], 1024, NULL);
			iss << serialized_string;
			boost::archive::text_iarchive ia(iss);
			// De-serialize messageID
			ia >> messageID_;
			switch(messageID_) {
				case 1:
				{
					Application_Active_Message Application_Active_MessageData;
					// De-serialize the message
					ia >> Application_Active_MessageData;
					// Forward the message in the socket
					doSend = true;
					// start protected area 740ca1c2b9580f85df2226b4dd3a7d8b62b456847379eeb73bfc0369b0bd5f9d;

					// end protected area 740ca1c2b9580f85df2226b4dd3a7d8b62b456847379eeb73bfc0369b0bd5f9d;
					if (doSend) {
						// Socket Client Management
						boost::asio::io_service io_service;
						stream_protocol::socket s(io_service);
						s.connect(stream_protocol::endpoint(this->outputChannel));

						boost::asio::write(s, boost::asio::buffer(serialized_string.data(),serialized_string.size()));
					}
				break;
				}
				case 7004:
				{
					StartCall StartCallData;
					// De-serialize the message
					ia >> StartCallData;
					// Forward the message in the socket
					doSend = true;
					// start protected area 57f86df032ffab960a687ba063524e52a8584fa8d42f09d78416537b7bfb76d7;

					// end protected area 57f86df032ffab960a687ba063524e52a8584fa8d42f09d78416537b7bfb76d7;
					if (doSend) {
						// Socket Client Management
						boost::asio::io_service io_service;
						stream_protocol::socket s(io_service);
						s.connect(stream_protocol::endpoint(this->outputChannel));

						boost::asio::write(s, boost::asio::buffer(serialized_string.data(),serialized_string.size()));
					}
				break;
				}
				case 7001:
				{
					SetSMS SetSMSData;
					// De-serialize the message
					ia >> SetSMSData;
					// Forward the message in the socket
					doSend = true;
					// start protected area 8654c9d8831045162251ceb385f5f61958819e8f1250f3584a4f445bb7b06b51;

					// end protected area 8654c9d8831045162251ceb385f5f61958819e8f1250f3584a4f445bb7b06b51;
					if (doSend) {
						// Socket Client Management
						boost::asio::io_service io_service;
						stream_protocol::socket s(io_service);
						s.connect(stream_protocol::endpoint(this->outputChannel));

						boost::asio::write(s, boost::asio::buffer(serialized_string.data(),serialized_string.size()));
					}
				break;
				}
				case 11001:
				{
					LEDManagement_Message LEDManagement_MessageData;
					// De-serialize the message
					ia >> LEDManagement_MessageData;
					// Forward the message in the socket
					doSend = true;
					// start protected area ca15b1f434b9b1c81957bff8a5181bc1f4625f9662a083c25eea5c5de12de32e;

					// end protected area ca15b1f434b9b1c81957bff8a5181bc1f4625f9662a083c25eea5c5de12de32e;
					if (doSend) {
						// Socket Client Management
						boost::asio::io_service io_service;
						stream_protocol::socket s(io_service);
						s.connect(stream_protocol::endpoint(this->outputChannel));

						boost::asio::write(s, boost::asio::buffer(serialized_string.data(),serialized_string.size()));
					}
				break;
				}
				case 9901:
				{
					PlayVocalFeedbackMessage PlayVocalFeedbackMessageData;
					// De-serialize the message
					ia >> PlayVocalFeedbackMessageData;
					// Forward the message in the socket
					doSend = true;
					// start protected area 6c090ecbd03370374f513b6ec9e4f89b207ef4c8a5432b47530ba0031bc9779b;

					// end protected area 6c090ecbd03370374f513b6ec9e4f89b207ef4c8a5432b47530ba0031bc9779b;
					if (doSend) {
						// Socket Client Management
						boost::asio::io_service io_service;
						stream_protocol::socket s(io_service);
						s.connect(stream_protocol::endpoint(this->outputChannel));

						boost::asio::write(s, boost::asio::buffer(serialized_string.data(),serialized_string.size()));
					}
				break;
				}
				case 7005:
				{
					CancelCall CancelCallData;
					// De-serialize the message
					ia >> CancelCallData;
					// Forward the message in the socket
					doSend = true;
					// start protected area 4f62cda31f7e725abf774c79611ed4a7041787f28391bd49b122aef3ee990276;

					// end protected area 4f62cda31f7e725abf774c79611ed4a7041787f28391bd49b122aef3ee990276;
					if (doSend) {
						// Socket Client Management
						boost::asio::io_service io_service;
						stream_protocol::socket s(io_service);
						s.connect(stream_protocol::endpoint(this->outputChannel));

						boost::asio::write(s, boost::asio::buffer(serialized_string.data(),serialized_string.size()));
					}
				break;
				}
				case 7014:
				{
					GoToSpyMode GoToSpyModeData;
					// De-serialize the message
					ia >> GoToSpyModeData;
					// Forward the message in the socket
					doSend = true;
					// start protected area 6f307ded14d9718e4902fb60c95b2f230c413caafdc67de27d9b7f2d42f56237;

					// end protected area 6f307ded14d9718e4902fb60c95b2f230c413caafdc67de27d9b7f2d42f56237;
					if (doSend) {
						// Socket Client Management
						boost::asio::io_service io_service;
						stream_protocol::socket s(io_service);
						s.connect(stream_protocol::endpoint(this->outputChannel));

						boost::asio::write(s, boost::asio::buffer(serialized_string.data(),serialized_string.size()));
					}
				break;
				}
				case 4002:
				{
					SetLEDStatus SetLEDStatusData;
					// De-serialize the message
					ia >> SetLEDStatusData;
					// Forward the message in the socket
					doSend = true;
					// start protected area 56b2b14882742991c01c5be63cfcc326ab8b764d48944e0821c5b5ed9b57cced;

					// end protected area 56b2b14882742991c01c5be63cfcc326ab8b764d48944e0821c5b5ed9b57cced;
					if (doSend) {
						// Socket Client Management
						boost::asio::io_service io_service;
						stream_protocol::socket s(io_service);
						s.connect(stream_protocol::endpoint(this->outputChannel));

						boost::asio::write(s, boost::asio::buffer(serialized_string.data(),serialized_string.size()));
					}
				break;
				}
				default:
				{
					// start protected area 8e54a51b329dad3e4d2d56120bbfb18fb587fb7a193ad98a3a692590efd4a8e8;
					std::cout << "receive undetailed msq (messageID_ : " << messageID_ << ") in Outbound send it to IPC anyway" << std::endl;
					// Socket Client Management
						boost::asio::io_service io_service;
						stream_protocol::socket s(io_service);
						s.connect(stream_protocol::endpoint(this->outputChannel));
						boost::asio::write(s, boost::asio::buffer(serialized_string.data(),serialized_string.size()));
					// end protected area 8e54a51b329dad3e4d2d56120bbfb18fb587fb7a193ad98a3a692590efd4a8e8;
				break;
				}
			}
			serialized_string.clear();
			serialized_string.resize(1024);
			iss.str(std::string());
		}
	}
	else
	{

		perror(" Message queue open failed ");
	}
	/* Close the message queue */
	ret = mq_close(mqd);
	if(ret)
		perror(" Message queue close failed");
	else
		printf(" Message Queue Closed");

	ret = mq_unlink(this->inputChannel.c_str());
	if(ret)
		perror(" Message queue unlink failed");
	else
		printf(" Message Queue unlinked");
}
OutboundDataManager::OutboundDataManager(std::string inputChannel, std::string outputChannel)
{
	this->inputChannel = inputChannel;
	this->outputChannel = outputChannel;
}
OutboundDataManager::OutboundDataManager()
{
	this->inputChannel = "/ecall_internal";
	this->outputChannel = "/ecall_out";
}

//==============================================================================
// Brief   : Command Service
// Authors : Simao Reis <sreis@av.it.pt>
//           Carlos Guimarães <cguimaraes@av.it.pt>
//------------------------------------------------------------------------------
// ODTONE - Open Dot Twenty One
//
// Copyright (C) 2009-2011 Universidade Aveiro
// Copyright (C) 2009-2011 Instituto de Telecomunicações - Pólo Aveiro
//
// This software is distributed under a license. The full license
// agreement can be found in the file LICENSE in this distribution.
// This software may not be copied, modified, sold or distributed
// other than expressed in the named license agreement.
//
// This software is distributed without any warranty.
//==============================================================================

#ifndef ODTONE_MIHF_COMMAND_SERVICE_HPP
#define ODTONE_MIHF_COMMAND_SERVICE_HPP

///////////////////////////////////////////////////////////////////////////////
#include "link_response_pool.hpp"
#include "local_transaction_pool.hpp"
#include "transmit.hpp"
#include "meta_message.hpp"
#include "link_book.hpp"

#include <boost/date_time/posix_time/posix_time.hpp>
///////////////////////////////////////////////////////////////////////////////

namespace odtone { namespace mihf {

/**
 * This class is responsible for handling the commands messages types.
 */
class command_service
	: boost::noncopyable
{
public:
	/**
	 * Command service constructor.
	 *
	 * @param io io_service.
	 * @param lpool local transction pool.
	 * @param t transmit module.
	 * @param link_abook link book.
	 * @param user_abook user book.
	 * @param link_response_pool link response pool.
	 */
	command_service(io_service &io,
	                local_transaction_pool &lpool,
	                transmit &t,
	                link_book &link_abook,
	                user_book &user_abook,
			link_response_pool &lrpool);

	/**
	 * Link Get Parameters Request message handler.
	 *
	 * @param in input message.
	 * @param out output message.
	 * @return true if the response is sent immediately or false otherwise.
	 */
	bool link_get_parameters_request(meta_message_ptr &in, meta_message_ptr &out);

	/**
	 * Link Get Parameters Response message handler.
	 *
	 * @param in input message.
	 * @param out output message.
	 * @return true if the response is sent immediately or false otherwise.
	 */
	bool link_get_parameters_response(meta_message_ptr &in, meta_message_ptr &out);

	/**
	 * Link Get Parameters Confirm message handler.
	 *
	 * @param in input message.
	 * @param out output message.
	 * @return true if the response is sent immediately or false otherwise.
	 */
	bool link_get_parameters_confirm(meta_message_ptr &in, meta_message_ptr &out);

	/**
	 * Link Configure Thresholds Request message handler.
	 *
	 * @param in input message.
	 * @param out output message.
	 * @return true if the response is sent immediately or false otherwise.
	 */
	bool link_configure_thresholds_request(meta_message_ptr &in, meta_message_ptr &out);

	/**
	 * Link Configure Thresholds Response message handler.
	 *
	 * @param in input message.
	 * @param out output message.
	 * @return true if the response is sent immediately or false otherwise.
	 */
	bool link_configure_thresholds_response(meta_message_ptr &in, meta_message_ptr &out);

	/**
	 * Link Configure Thresholds Confirm message handler.
	 *
	 * @param in input message.
	 * @param out output message.
	 * @return true if the response is sent immediately or false otherwise.
	 */
	bool link_configure_thresholds_confirm(meta_message_ptr &in, meta_message_ptr &out);

	/**
	 * Link Actions Request message handler.
	 *
	 * @param in input message.
	 * @param out output message.
	 * @return true if the response is sent immediately or false otherwise.
	 */
	bool link_actions_request(meta_message_ptr &in, meta_message_ptr &out);

	/**
	 * Link Actions Response message handler.
	 *
	 * @param in input message.
	 * @param out output message.
	 * @return true if the response is sent immediately or false otherwise.
	 */
	bool link_actions_response(meta_message_ptr &in, meta_message_ptr &out);

	/**
	 * Link Actions Confirm message handler.
	 *
	 * @param in input message.
	 * @param out output message.
	 * @return true if the response is sent immediately or false otherwise.
	 */
	bool link_actions_confirm(meta_message_ptr &in, meta_message_ptr &out);

	/**
	 * Net Handover Candidate Query Request message handler.
	 *
	 * @param in input message.
	 * @param out output message.
	 * @return true if the response is sent immediately or false otherwise.
	 */
	bool net_ho_candidate_query_request(meta_message_ptr &in, meta_message_ptr &out);

	/**
	 * Net Handover Candidate Query Response message handler.
	 *
	 * @param in input message.
	 * @param out output message.
	 * @return true if the response is sent immediately or false otherwise.
	 */
	bool net_ho_candidate_query_response(meta_message_ptr &in, meta_message_ptr &out);

	/**
	 * MN Handover Query Request message handler.
	 *
	 * @param in input message.
	 * @param out output message.
	 * @return true if the response is sent immediately or false otherwise.
	 */
	bool mn_ho_candidate_query_request(meta_message_ptr &in, meta_message_ptr &out);

	/**
	 * MN Handover Query Response message handler.
	 *
	 * @param in input message.
	 * @param out output message.
	 * @return true if the response is sent immediately or false otherwise.
	 */
	bool mn_ho_candidate_query_response(meta_message_ptr &in, meta_message_ptr &out);

	/**
	 * N2N Handover Query Resources Request message handler.
	 *
	 * @param in input message.
	 * @param out output message.
	 * @return true if the response is sent immediately or false otherwise.
	 */
	bool n2n_ho_query_resources_request(meta_message_ptr &in, meta_message_ptr &out);

	/**
	 * N2N Handover Query Resources Response message handler.
	 *
	 * @param in input message.
	 * @param out output message.
	 * @return true if the response is sent immediately or false otherwise.
	 */
	bool n2n_ho_query_resources_response(meta_message_ptr &in, meta_message_ptr &out);

	/**
	 * MN Handover Commit Request message handler.
	 *
	 * @param in input message.
	 * @param out output message.
	 * @return true if the response is sent immediately or false otherwise.
	 */
	bool mn_ho_commit_request(meta_message_ptr &in, meta_message_ptr &out);

	/**
	 * MN Handover Commit Response message handler.
	 *
	 * @param in input message.
	 * @param out output message.
	 * @return true if the response is sent immediately or false otherwise.
	 */
	bool mn_ho_commit_response(meta_message_ptr &in, meta_message_ptr &out);

	/**
	 * Net Handover Commit Request message handler.
	 *
	 * @param in input message.
	 * @param out output message.
	 * @return true if the response is sent immediately or false otherwise.
	 */
	bool net_ho_commit_request(meta_message_ptr &in, meta_message_ptr &out);

	/**
	 * Net Handover Commit Response message handler.
	 *
	 * @param in input message.
	 * @param out output message.
	 * @return true if the response is sent immediately or false otherwise.
	 */
	bool net_ho_commit_response(meta_message_ptr &in, meta_message_ptr &out);

	/**
	 * N2N Handover Commit Request message handler.
	 *
	 * @param in input message.
	 * @param out output message.
	 * @return true if the response is sent immediately or false otherwise.
	 */
	bool n2n_ho_commit_request(meta_message_ptr &in, meta_message_ptr &out);

	/**
	 * N2N Handover Commit Response message handler.
	 *
	 * @param in input message.
	 * @param out output message.
	 * @return true if the response is sent immediately or false otherwise.
	 */
	bool n2n_ho_commit_response(meta_message_ptr &in, meta_message_ptr &out);

	/**
	 * MN Handover Complete Request message handler.
	 *
	 * @param in input message.
	 * @param out output message.
	 * @return true if the response is sent immediately or false otherwise.
	 */
	bool mn_ho_complete_request(meta_message_ptr &in, meta_message_ptr &out);

	/**
	 * MN Handover Complete Response message handler.
	 *
	 * @param in input message.
	 * @param out output message.
	 * @return true if the response is sent immediately or false otherwise.
	 */
	bool mn_ho_complete_response(meta_message_ptr &in, meta_message_ptr &out);

	/**
	 * N2N Handover Complete Request message handler.
	 *
	 * @param in input message.
	 * @param out output message.
	 * @return true if the response is sent immediately or false otherwise.
	 */
	bool n2n_ho_complete_request(meta_message_ptr &in, meta_message_ptr &out);

	/**
	 * N2N Handover Complete Response message handler.
	 *
	 * @param in input message.
	 * @param out output message.
	 * @return true if the response is sent immediately or false otherwise.
	 */
	bool n2n_ho_complete_response(meta_message_ptr &in, meta_message_ptr &out);

private:
	/**
	 * Handler responsible for asking informations to known local Link SAPs,
	 * process those informations and answer with a Get Information
	 * message to the requestor.
	 *
	 * @param in input message.
	 */
	void link_get_parameters_response_handler(meta_message_ptr &in);

	/**
	 * Handler responsible for asking informations to known local Link SAPs,
	 * process those informations and answer with a Link Actions
	 * message to the requestor.
	 *
	 * @param in input message.
	 */
	void link_actions_response_handler(meta_message_ptr &in);

protected:
	/**
	 * Currently Command_Service messages are handled by a default local
	 * user. If this MIHF is the destination of the message, forward it to
	 * the default user. Add a local transaction indicating where to send
	 * the response.
	 *
	 * @param recv_msg recv message.
	 * @param send_msg send message.
	 * @param in input message.
	 * @param out output message.
	 * @return true if the response is sent immediately or false otherwise.
	 */
	bool generic_command_request(const char *recv_msg,
				     const char *send_msg,
				     meta_message_ptr &in,
				     meta_message_ptr &out);

	/**
	 * Currently Command_Service messages are handled by a default local
	 * user. If this MIHF is the destination of the message, check for a
	 * pending transaction and forward the message.
	 *
	 * @param recv_msg recv message.
	 * @param send_msg send message.
	 * @param in input message.
	 * @param out output message.
	 * @return true if the response is sent immediately or false otherwise.
	 */
	bool generic_command_response(const char *recv_msg,
				      const char *send_msg,
				      meta_message_ptr &in,
				      meta_message_ptr &out);

	local_transaction_pool	&_lpool;
	transmit		&_transmit;
	link_book               &_link_abook;
	user_book               &_user_abook;
	link_response_pool      &_lrpool;

	boost::asio::deadline_timer _timer;
};

///////////////////////////////////////////////////////////////////////////////
} /* namespace mihf */ } /* namespace odtone */

#endif

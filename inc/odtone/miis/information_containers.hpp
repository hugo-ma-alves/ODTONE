//
// Copyright (c) 2007-2009 2009 Universidade Aveiro - Instituto de
// Telecomunicacoes Polo Aveiro
// This file is part of ODTONE - Open Dot Twenty One.
//
// This software is distributed under a license. The full license
// agreement can be found in the file LICENSE in this distribution.
// This software may not be copied, modified, sold or distributed
// other than expressed in the named license agreement.
//
// This software is distributed without any warranty.
//
// Author:     Simao Reis <sreis@av.it.pt>
//

#ifndef ODTONE_IES_CONTAINERS_HPP
#define ODTONE_IES_CONTAINERS_HPP

#include <odtone/base.hpp>
#include <odtone/mih/tlv.hpp>
#include <odtone/miis/information_elements.hpp>

#include <vector>

namespace odtone { namespace miis {

struct ie_container_poa
{
	boost::variant<mih::null, ie_poa_link_addr > poa_link_addr;
	boost::variant<mih::null, ie_poa_location > poa_location;
	boost::variant<mih::null, ie_poa_channel_range > poa_channel_range;
	boost::variant<mih::null, std::vector<ie_poa_subnet_info> > poa_subnet_info;
	boost::variant<mih::null, std::vector<ie_poa_ip_addr> > poa_ip_addr;

	ie_container_poa() :
		poa_link_addr(mih::null()),
		poa_location(mih::null()),
		poa_channel_range(mih::null()),
		poa_subnet_info(mih::null()),
		poa_ip_addr(mih::null())
	{}

	template<class ArchiveT>
	void serialize(ArchiveT& ar)
	{
		ar & poa_link_addr;
		ar & poa_location;
		ar & poa_channel_range;
		ar & poa_subnet_info;
		ar & poa_ip_addr;
	}
};

struct ie_container_network
{
	ie_network_type network_type;
	ie_operator_id operator_id;

	boost::variant<mih::null, ie_service_provider_id > service_provider_id;
	boost::variant<mih::null, ie_country_code > country_code;
	boost::variant<mih::null, ie_network_id > network_id;
	boost::variant<mih::null, ie_network_aux_id > network_aux_id;
	boost::variant<mih::null, ie_roaming_partners > roaming_partners;
	boost::variant<mih::null, ie_cost > cost;
	boost::variant<mih::null, ie_network_qos > network_qos;
	boost::variant<mih::null, ie_network_data_rate > network_data_rate;
	boost::variant<mih::null, ie_net_regulat_domain > net_regulat_domain;
	boost::variant<mih::null, ie_net_frequency_bands > net_frequency_bands;
	boost::variant<mih::null, ie_net_ip_cfg_methods > net_ip_cfg_methods;
	boost::variant<mih::null, ie_net_capabilities > net_capabilities;
	boost::variant<mih::null, ie_net_supported_lcp > net_supported_lcp;
	boost::variant<mih::null, ie_net_mob_mgmt_prot > net_mob_mgmt_prot;
	boost::variant<mih::null, ie_net_emserv_proxy > net_emserv_proxy;
	boost::variant<mih::null, ie_net_ims_proxy_cscf > net_ims_proxy_cscf;
	boost::variant<mih::null, ie_net_mobile_network > net_mobile_network;

	template<class ArchiveT>
	void serialize(ArchiveT& ar)
	{
		ar & network_type;
		ar & operator_id;

		ar & service_provider_id;
		ar & country_code;
		ar & network_id;
		ar & network_aux_id;
		ar & roaming_partners;
		ar & cost;
		ar & network_qos;
		ar & network_data_rate;
		ar & net_regulat_domain;
		ar & net_frequency_bands;
		ar & net_ip_cfg_methods;
		ar & net_capabilities;
		ar & net_supported_lcp;
		ar & net_mob_mgmt_prot;
		ar & net_emserv_proxy;
		ar & net_ims_proxy_cscf;
		ar & net_mobile_network;
	}

};

typedef std::vector< ie_container_network > ie_container_list_of_networks;

typedef mih::tlv_fwd<ie_network_type, mih::tlv_<0x10000000> > tlv_ie_network_type;
typedef mih::tlv_fwd<ie_operator_id, mih::tlv_<0x10000001> > tlv_ie_operator_id;
typedef mih::tlv_fwd<ie_service_provider_id, mih::tlv_<0x10000002> > tlv_ie_service_provider_id;
typedef mih::tlv_fwd<ie_country_code, mih::tlv_<0x10000003> > tlv_ie_country_code;
typedef mih::tlv_fwd<ie_network_id, mih::tlv_<0x10000100> > tlv_ie_network_id;
typedef mih::tlv_fwd<ie_network_aux_id, mih::tlv_<0x10000101> > tlv_ie_network_aux_id;
typedef mih::tlv_fwd<ie_roaming_partners, mih::tlv_<0x1000002> > tlv_ie_roaming_partners;
typedef mih::tlv_fwd<ie_cost, mih::tlv_<0x10000103> > tlv_ie_cost;
typedef mih::tlv_fwd<ie_network_qos, mih::tlv_<0x10000105> > tlv_ie_network_qos;
typedef mih::tlv_fwd<ie_network_data_rate, mih::tlv_<0x10000106> > tlv_ie_network_data_rate;
typedef mih::tlv_fwd<ie_net_regulat_domain, mih::tlv_<0x10000107> > tlv_ie_net_regulat_domain;
typedef mih::tlv_fwd<ie_net_frequency_bands, mih::tlv_<0x10000108> > tlv_ie_net_frequency_bands;
typedef mih::tlv_fwd<ie_net_ip_cfg_methods, mih::tlv_<0x10000109> > tlv_ie_net_ip_cfg_methods;
typedef mih::tlv_fwd<ie_net_capabilities, mih::tlv_<0x1000010A> > tlv_ie_net_capabilities;
typedef mih::tlv_fwd<ie_net_supported_lcp, mih::tlv_<0x1000010B> > tlv_ie_net_supported_lcp;
typedef mih::tlv_fwd<ie_net_mob_mgmt_prot, mih::tlv_<0x1000010C> > tlv_ie_net_mob_mgmt_prot;
typedef mih::tlv_fwd<ie_net_emserv_proxy, mih::tlv_<0x1000010D> > tlv_ie_net_emserv_proxy;
typedef mih::tlv_fwd<ie_net_ims_proxy_cscf, mih::tlv_<0x1000010E> > tlv_ie_net_ims_proxy_cscf;
typedef mih::tlv_fwd<ie_net_mobile_network, mih::tlv_<0x1000010F> > tlv_ie_net_mobile_network;
typedef mih::tlv_fwd<ie_poa_link_addr, mih::tlv_<0x10000200> > tlv_ie_poa_link_addr;
typedef mih::tlv_fwd<ie_poa_location, mih::tlv_<0x10000201> > tlv_ie_poa_location;
typedef mih::tlv_fwd<ie_poa_channel_range, mih::tlv_<0x10000202> > tlv_ie_poa_channel_range;
typedef mih::tlv_fwd<ie_poa_system_info, mih::tlv_<0x10000203> > tlv_ie_poa_system_info;
typedef mih::tlv_fwd<ie_poa_subnet_info, mih::tlv_<0x10000204> > tlv_ie_poa_subnet_info;
typedef mih::tlv_fwd<ie_poa_ip_addr, mih::tlv_<0x10000205> > tlv_ie_poa_ip_addr;

typedef mih::tlv_fwd<ie_container_list_of_networks, mih::tlv_<0x10000300> > tlv_ie_container_list_of_networks;
typedef mih::tlv_fwd<ie_container_network, mih::tlv_<0x10000302> > tlv_ie_container_networks;
typedef mih::tlv_fwd<ie_container_poa, mih::tlv_<0x10000303> > tlv_ie_container_poa;

} /* namespace miis */  }  /* namespace odtone */

#endif
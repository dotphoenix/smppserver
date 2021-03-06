/*
 * SMPP Encoder/Decoder
 * Copyright (C) 2006 redtaza@users.sourceforge.net
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * 
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */
#ifndef __SMPP_ENQUIRE_LINK_HPP__
#define __SMPP_ENQUIRE_LINK_HPP__

/// @file enquire_link.hpp
/// @brief An SMPP enquire_link PDU.

#include "aux_types.hpp"
#include "header.hpp"

namespace Smpp {

    /// @class EnquireLink
    /// @brief Definition of an SMPP enquire_link, derived from a Response.
    class EnquireLink : public Request {
        Smpp::Buffer buff_;

      public:
        /// enquire_link minimum length in octets.
        const static int MinLength = 16;
        
        /// @brief Default constructor.
        EnquireLink();
        
        /// @brief Constructor requiring all mandatory parameters.
        EnquireLink(const SequenceNumber& sequenceNumber);
       
        /// @brief Construct from a buffer.
        EnquireLink(const Smpp::Uint8* b);

        /// @brief Destructor - does nothing.
        ~EnquireLink();
        
        /// @brief Serialize the PDU.
        /// @note The length is taken from the command_length().
        /// @return The PDU as an octet array, suitable for outputting.
        const Smpp::Uint8* encode();

        /// @brief Populates the PDU from an array of octets.
        /// @param buff containing PDU as octet array.
        void decode(const Smpp::Uint8* buff);
    };

} // namespace Smpp

#endif


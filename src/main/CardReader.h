/**************************************************************************************************
 * Copyright (c) 2021 Calypso Networks Association                                                *
 * https://www.calypsonet-asso.org/                                                               *
 *                                                                                                *
 * See the NOTICE file(s) distributed with this work for additional information regarding         *
 * copyright ownership.                                                                           *
 *                                                                                                *
 * This program and the accompanying materials are made available under the terms of the Eclipse  *
 * Public License 2.0 which is available at http://www.eclipse.org/legal/epl-2.0                  *
 *                                                                                                *
 * SPDX-License-Identifier: EPL-2.0                                                               *
 **************************************************************************************************/

#pragma once

#include <string>

namespace calypsonet {
namespace terminal {
namespace reader {

/**
 * Card reader driving the underlying hardware to manage the card detection.
 *
 * @since 1.0
 */
class CardReader {
public:
    /**
     * Gets the name of the reader.
     *
     * @return A not empty string.
     * @since 1.0
     */
    virtual const std::string& getName() const = 0;

    /**
     * Tells if the card communication mode is contactless.
     *
     * @return True if the communication is contactless.
     * @since 1.0
     */
    virtual bool isContactless() const = 0;

    /**
     * Checks if is the card present.
     *
     * @return True if a card is inserted in the reader.
     * @throws ReaderCommunicationException If the communication with the reader has failed.
     * @since 1.0
     */
    virtual bool isCardPresent() = 0;

    /**
     * Activates the reader protocol having the provided reader protocol name and associates it with
     * the protocol name defined by the application.
     *
     * <ul>
     *   <li>Activates the detection of cards using the provided reader protocol.
     *   <li>Asks the reader to accept any card using this protocol during the selection phase.
     *   <li>Internally associates the two strings provided as arguments.
     * </ul>
     *
     * <p>The association between the protocol name known by the reader and the protocol name known
     * by the application is intended to allow a unique protocol name to be set when constructing a
     * card selector as defined by the <b>Terminal Card API</b> regardless of the type of reader
     * that will be used.
     *
     * @param readerProtocol The name of the protocol as known by the reader.
     * @param cardProtocol The name of the protocol as known by the application.
     * @throw IllegalArgumentException If one of the provided protocol is null or empty.
     * @throw ReaderProtocolNotSupportedException If the protocol is not supported.
     * @since 1.0
     */
    virtual void activateProtocol(const std::string& readerProtocol,
                                  const std::string& cardProtocol) = 0;

    /**
     * Deactivates the provided card protocol.
     *
     * <ul>
     *   <li>Inhibits the detection of cards using this protocol.
     *   <li>Ask the reader to ignore this protocol if a card using this protocol is identified
     *       during the selection phase.
     * </ul>
     *
     * @param readerProtocol The name of the protocol as known by the reader.
     * @throw IllegalArgumentException If the provided protocol is null or empty.
     * @throw ReaderProtocolNotSupportedException If the protocol is not supported.
     * @since 1.0
     */
    virtual void deactivateProtocol(const std::string& readerProtocol) = 0;
};

}
}
}
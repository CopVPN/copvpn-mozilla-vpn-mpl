/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef IPUTILSMACOS_H
#define IPUTILSMACOS_H

#include <arpa/inet.h>

#include "iputils.h"
#include "vpnconfig.h"

class IPUtilsMacos final : public IPUtils {
public:
    IPUtilsMacos(QObject* parent);
    ~IPUtilsMacos();
    bool addInterfaceIPs(const VpnConfig& config) override;
    bool setMTUAndUp(const VpnConfig& config) override;
    void setIfname(const QString& ifname) { m_ifname = ifname; }

private:
    bool addIP4AddressToDevice(const VpnConfig& config);
    bool addIP6AddressToDevice(const VpnConfig& config);

private:
    QString m_ifname;
};

#endif  // IPUTILSMACOS_H

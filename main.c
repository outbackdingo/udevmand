/*
 * Copyright (C) 2020 John Crispin <john@phrozen.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License version 2.1
 * as published by the Free Software Foundation
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include "udevmand.h"

int main(int argc, char **argv)
{
	ulog_open(ULOG_STDIO | ULOG_SYSLOG, LOG_DAEMON, "udevmand");

	uloop_init();
	ubus_init();
	ethers_init();
	neigh_init();
	bridge_init();
	nl80211_init();
	neigh_enum();
	dhcp_init();
	uloop_run();
	uloop_done();
	ubus_uninit();

	return 0;
}

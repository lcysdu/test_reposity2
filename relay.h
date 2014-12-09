/***************************************************************************
 *
 * Copyright (c) 2014 www.sdboon.com, Inc. All Rights Reserved
 * $Project BoonTrain ,v 1.0 2014/03/08 11:22:00
 * sunxiwei @ Machine Learning Technology Center.
 *
 **************************************************************************/

/**
 * @file relay.h
 * @author sxw@sdboon.com)
 * @date 2014/09/10 08:53:00
 * @version $Revision: 1.0 $
 * @implementation of FpsCounter
 *
 **/
#ifndef RELAY_H
#define RELAY_H

#include <stdio.h>
#include <stdlib.h>
#include <hidapi/hidapi.h>

class Relay
{
public:
	/** Constructor. */
	Relay();

	/** Destructor. */
	virtual ~Relay();

	bool init();

	void open();

	void open(int channel);

	void close();

	void close(int channel);

protected:
	struct hid_device_info * p_usb_relay;
	hid_device * p_hid_device;

};

#endif

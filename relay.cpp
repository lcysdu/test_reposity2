#include "relay.h"

Relay::Relay()
{
	p_usb_relay = NULL;
	p_hid_device = NULL;
}

Relay::~Relay()
{

}

bool Relay::init()
{
	bool ret = false;
	p_usb_relay = hid_enumerate(0xc216, 0);
	if (p_usb_relay){
		printf("[USB-Relay]0x%x\n", p_usb_relay->product_id);
		printf("[USB-Relay]%s\n", p_usb_relay->path);
		p_hid_device = hid_open(p_usb_relay->vendor_id, p_usb_relay->product_id,
		NULL);
		if (p_hid_device){
			ret = true;
		}
		else{
			printf("[USB-Relay][ERROR]hid_open fail\n");
			ret = false;
		}
	}
	else{
		printf("[USB-Relay][ERROR]No usb-relay\n");
		ret = false;
	}
	return ret;
}

void Relay::open()
{
	unsigned char p_buf[256] =
	{ 0 };
	unsigned char p_rx[256] =
	{ 0 };
	p_buf[0] = 0;
	p_buf[1] = 1;
	p_buf[2] = 0;
	p_buf[3] = 0;
	p_buf[4] = 4;
	p_buf[5] = 0;
	p_buf[6] = 1;
	p_buf[7] = 1;
	p_buf[8] = 0;
	int ret = hid_send_feature_report(p_hid_device, p_buf, 65);

	if (ret > 0){
		ret = hid_get_feature_report(p_hid_device, p_rx, sizeof(p_rx));
	}
}

void Relay::open(int channel)
{
	unsigned char p_buf[256] =
	{ 0 };
	unsigned char p_rx[256] =
	{ 0 };
	p_buf[0] = 0;
	p_buf[1] = 1;
	p_buf[2] = 0;
	p_buf[3] = 0;
	p_buf[4] = 4;
	p_buf[5] = 0;
	p_buf[6] = channel;
	p_buf[7] = 1;
	p_buf[8] = 0;
	int ret = hid_send_feature_report(p_hid_device, p_buf, 65);

	if (ret > 0){
		ret = hid_get_feature_report(p_hid_device, p_rx, sizeof(p_rx));
	}
}

void Relay::close()
{
	unsigned char p_buf[256] ={ 0 };
	unsigned char p_rx[256] ={ 0 };
	p_buf[0] = 0;
	p_buf[1] = 1;
	p_buf[2] = 0;
	p_buf[3] = 0;
	p_buf[4] = 4;
	p_buf[5] = 0;
	p_buf[6] = 1;
	p_buf[7] = 1;
	p_buf[8] = 1;
	int ret = hid_send_feature_report(p_hid_device, p_buf, 65);

	if (ret > 0){
		ret = hid_get_feature_report(p_hid_device, p_rx, sizeof(p_rx));
	}
}

void Relay::close(int channel)
{
	unsigned char p_buf[256] ={ 0 };
	unsigned char p_rx[256] ={ 0 };
	p_buf[0] = 0;
	p_buf[1] = 1;
	p_buf[2] = 0;
	p_buf[3] = 0;
	p_buf[4] = 4;
	p_buf[5] = 0;
	p_buf[6] = channel;
	p_buf[7] = 1;
	p_buf[8] = 1;
	int ret = hid_send_feature_report(p_hid_device, p_buf, 65);

	if (ret > 0){
		ret = hid_get_feature_report(p_hid_device, p_rx, sizeof(p_rx));
	}
}


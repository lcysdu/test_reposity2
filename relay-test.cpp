#include "relay.h"
#include <unistd.h>

int main()
{
	Relay relay;
	relay.init();
	relay.open(2);
	sleep(1);
	relay.close(2);
}

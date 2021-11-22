#include <gclib_errors.h>
#include <gclib.h>
#include <gclibo.h>
#include <gclib_record.h>
#include "Galil.h"

using namespace System;
using namespace System::IO;
using namespace System::Threading::Tasks;
using namespace System::Collections::Generic;

GCon g = 0;

int main()
{
	char buf[1024]; //traffic buffer
	char Command[128] = "";
	GOpen("192.168.0.120 -d", &g);

	sprintf_s(Command, "AO0,0;"); 

	GCommand(g, Command, buf, sizeof(buf), 0);

	if (g)

		GClose(g); //Don't forget to close!

	Console::WriteLine("Terminating!");

	Console::ReadKey();

	return G_NO_ERROR;


}
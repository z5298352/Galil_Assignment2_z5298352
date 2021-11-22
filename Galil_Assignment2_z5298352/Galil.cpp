#include <iostream>
#using <System.dll>
#include <EmbeddedFunctions.h>
#include <Galil.h>
#include <bitset>
#include <string>
// Default constructor. Initialize variables, open Galil connection and allocate memory. NOT AUTOMARKED


// Constructor with EmbeddedFunciton initialization
Galil::Galil(EmbeddedFunctions* Funcs, GCStringIn address)
{
	Functions = Funcs;
	g = 0;
	Functions->GOpen(address, &g);
};

// Default destructor. Deallocate memory and close Galil connection. NOT AUTOMARKED
Galil::~Galil()
{
	if (g)
	{
		GClose(g);
	}
	delete Functions;

};

// DIGITAL OUTPUTS
// Write to all 16 bits of digital output, 1 command to the Galil
void Galil::DigitalOutput(uint16_t value)
{
	return;
};

// Write to one byte, either high or low byte, as specified by user in 'bank'; 0 = low, 1 = high
void Galil::DigitalByteOutput(bool bank, uint8_t value)
{
	return;
};

// Write single bit to digital outputs. 'bit' specifies which bit
void Galil::DigitalBitOutput(bool val, uint8_t bit)
{
	return;
};

// DIGITAL INPUTS
// Return the 16 bits of input data
// Query the digital inputs of the GALIL, See Galil command library @IN
uint16_t Galil::DigitalInput()
{
	return 1;
};

// Read either high or low byte, as specified by user in 'bank'
// 0 = low, 1 = high
uint8_t Galil::DigitalByteInput(bool bank)
{
	return 1;
};

// Read single bit from current digital inputs. Above functions
// may use this function
bool Galil::DigitalBitInput(uint8_t bit)
{
	return false;
};

// Check the string response from the Galil to check that the last 
// command executed correctly. 1 = succesful. NOT AUTOMARKED 
bool Galil::CheckSuccessfulWrite()
{	
	return Bytes_returned;
};

// ANALOG FUNCITONS
// Read Analog channel and return voltage
float Galil::AnalogInput(uint8_t channel)
{
	sprintf_s(Command, "MG @AO[%u];", channel);
	Functions->GCommand(g, Command, ReadBuffer, sizeof(ReadBuffer), &Bytes_returned);
	return strtof(ReadBuffer, NULL);
};

// Write to any channel of the Galil, send voltages as
// 2 decimal place in the command string
void Galil::AnalogOutput(uint8_t channel, double voltage)
{
	return;
};

// Configure the range of the input channel with
// the desired range code
void Galil::AnalogInputRange(uint8_t channel, uint8_t range)
{
	return;
};

// ENCODER / CONTROL FUNCTIONS
// Manually Set the encoder value to zero
void Galil::WriteEncoder()
{
	return;
};

// Read from Encoder
int Galil::ReadEncoder()
{
	return 0;
};

// Set the desired setpoint for control loops, counts or counts/sec
void Galil::setSetPoint(int s)
{
	setPoint = s;
};

// Set the proportional gain of the controller used in controlLoop()
void Galil::setKp(double gain)
{
	ControlParameters[0] = gain;
};

// Set the integral gain of the controller used in controlLoop()
void Galil::setKi(double gain)
{
	ControlParameters[1] = gain;
};

// Set the derivative gain of the controller used in controlLoop()
void Galil::setKd(double gain)
{
	ControlParameters[2] = gain;
};

//// Run the control loop. ReadEncoder() is the input to the loop. The motor is the output
//// The loop will run using the PID values specified in the data of this object, and has an
//// automatic timeout of 10s. You do not need to implement this function, it is defined in
//// GalilControl.lib
//void Galil::PositionControl(bool debug, int Motorchannel)
//{
//	std::cout << "Hello" << std::endl;
//	return;
//};
//
//// same as above. Setpoint interpreted as counts per second
//void Galil::SpeedControl(bool debug, int Motorchannel)
//{
//	std::cout << "Hello" << std::endl;
//	return;
//};


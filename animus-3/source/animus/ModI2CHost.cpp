#include "ModI2CHost.h"
CModI2CHost::CModI2CHost(void)
{
  // nothing
}

void CModI2CHost::Begin(void)
{
  CModTemplate::Begin();
  ModGUID = 8; // GUID of this sspecific mod

  if (Global.HasUSB) // i2c host only activates if this device is plugged into the PC
  {
    Wire.begin();
  }
}


void CModI2CHost::LoadData(void)
{
  CModTemplate::LoadData();

  if (Global.HasUSB)
  {

  }
}

void CModI2CHost::Loop(void)
{
  CModTemplate::Loop();

  if (Animus.Async1MSDelay())
  {

    if (Global.HasUSB)
    {

    }
  }
}

void CModI2CHost::PrePress(byte val, byte type)
{
  CModTemplate::PrePress(val, type);
  if (Global.HasUSB)
  {

  }
}
void CModI2CHost::PressKey(byte val, byte type)
{
  CModTemplate::PressKey(val, type);

  if (Global.HasUSB)
  {

  }
}
void CModI2CHost::ReleaseKey(byte val, byte type)
{
  CModTemplate::ReleaseKey(val, type);

  if (Global.HasUSB)
  {

  }
}

void CModI2CHost::SerialComms(byte mode) // holy shit this is complicated
{
  CModTemplate::SerialComms(mode);
}


// first byte is the type of the packet
// second byte always sends the templayer
// third byte forward is the data of the packet
/*
type 0 does nothing
type 1 sends templayer (templayer)
type 2 is a full reflash type that writes sub eeprom from 0 to 1024 (byte0, byte1, byte2, ...)
type 3 writes sub eeprom starting from 900 (byte0, byte1, byte2, ...)
type 4 changes the LED setting (brightness)
type 5 changes the refresh rate (refresh)
*/

void CModI2CHost::SetTempLayer()
{
  Wire.beginTransmission(8);
  Wire.write(1);
  Wire.write(Global.TempLayer);
  Wire.endTransmission();
}

void CModI2CHost::SetSubEEPROM(void)
{
  Wire.beginTransmission(8);
  Wire.write(2);
  Wire.write(EEPROMPacketIndex);
  Wire.write(EEPROMPacket, EEPROMPacketIndex);
  Wire.endTransmission();
}

void CModI2CHost::SetSubBoardSettings(void)
{
  Wire.beginTransmission(8);
  Wire.write(3);
  Wire.write(EEPROMPacketIndex);
  Wire.write(EEPROMPacket, EEPROMPacketIndex);
  Wire.endTransmission();
}



void CModI2CHost::SetSubLEDBrightness(void)
{
  Wire.beginTransmission(8);
  Wire.write(4);
  Wire.write(Global.TempLayer);
  Wire.write(Global.LEDBrightness);
  Wire.endTransmission();
}

void CModI2CHost::SetSubRefreshRate(void)
{
  Wire.beginTransmission(8);
  Wire.write(5);
  Wire.write(Global.TempLayer);
  Wire.write(Global.RefreshDelay);
  Wire.endTransmission();
}




CModI2CHost ModI2CHost;

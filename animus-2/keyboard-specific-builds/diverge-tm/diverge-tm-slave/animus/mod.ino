#define builder_mstartup I2CSlaveStartup(); mediaStartup(); tapDanceStartup(); stickyKeysStartup();
#define builder_mloop I2CSlaveLoop(); mediaLoop(); tapDanceLoop(); stickyKeysLoop();
#define builder_mpresscoord I2CSlavePressCoord(x, y); mediaPressCoord(x, y); tapDancePressCoord(x, y); stickyKeysPressCoord(x, y);
#define builder_mprepress I2CSlavePrePress(val, type); mediaPrePress(val, type); tapDancePrePress(val, type); stickyKeysPrePress(val, type);
#define builder_mkeydown I2CSlaveKeyDown(val, type); mediaKeyDown(val, type); tapDanceKeyDown(val, type); stickyKeysKeyDown(val, type);
#define builder_mkeyup I2CSlaveKeyUp(val, type); mediaKeyUp(val, type); tapDanceKeyUp(val, type); stickyKeysKeyUp(val, type);
#define builder_mserial I2CSlaveSerial(input); mediaSerial(input); tapDanceSerial(input); stickyKeysSerial(input);

void ModStartup()
{
  builder_mstartup
}

void ModLoop()
{
  if (CheckMillis())
  {
  }
  builder_mloop
}


void ModPressCoord(byte x, byte y)
{
  builder_mpresscoord
}

void ModPrePress(char val, byte type)
{
  builder_mprepress
}

void ModKeyDown(char val, byte type)
{
  builder_mkeydown
}

void ModKeyUp(char val, byte type)
{
  builder_mkeyup
}

void ModSerial(String input)
{
  if (input == "uniquekgetmods")
  {
    Serial.print("get mods(");
  }
  builder_mserial
  if (input == "uniquekgetmods")
  {
    Serial.print("\r\n");
  }
}

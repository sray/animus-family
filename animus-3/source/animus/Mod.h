#ifndef ANIMUS_MOD
#define ANIMUS_MOD

#define builder_mod_begin ModDualRoles.Begin(); ModModifier.Begin();
#define builder_mod_loop ModDualRoles.Loop(); ModModifier.Loop();
#define builder_mod_loaddata ModDualRoles.LoadData(); ModModifier.LoadData();
#define builder_mod_prepress ModDualRoles.PrePress(val, type); ModModifier.PrePress(val, type);
#define builder_mod_press ModDualRoles.PressKey(val, type); ModModifier.PressKey(val, type);
#define builder_mod_release ModDualRoles.ReleaseKey(val, type); ModModifier.ReleaseKey(val, type);
#define builder_mod_print ModDualRoles.PrintMods(); ModModifier.PrintMods();


// mod dependencies below
#include "ModModifier.h"
#include "ModDualRoles.h"

// mod dependencies above


#include "Comms.h"



class CMod
{
private:
public:
  CMod(void);
  void Begin(void);
  void Loop(void);
  void LoadData(void);
  void PrePress(byte val, byte type);
  void PressKey(byte val, byte type);
  void ReleaseKey(byte val, byte type);
  void PrintMods();
  void End(void);
};
extern CMod Mod;

#endif

#pragma once

#include <utils/hook.hpp>
#include <utils/string.hpp>
#include "game/game.hpp"
#include "component/command.hpp"
#include "component/scheduler.hpp"

#include "structs.hpp"
#include "functions.hpp"
#include "variables.hpp"

#include "utils/utils.hpp"

#include "assets/clut.hpp"
#include "assets/addonmapents.hpp"
#include "assets/dopplerpreset.hpp"
#include "assets/fxeffectdef.hpp"
#include "assets/fxparticlesimanimation.hpp"
#include "assets/gfximage.hpp"
#include "assets/gfxlightdef.hpp"
#include "assets/loadedsound.hpp"
#include "assets/localize.hpp"
#include "assets/lpfcurve.hpp"
#include "assets/luafile.hpp"
#include "assets/mapents.hpp"
#include "assets/material.hpp"
#include "assets/rawfile.hpp"
#include "assets/netconststrings.hpp"
#include "assets/physcollmap.hpp"
#include "assets/physconstraint.hpp"
#include "assets/physpreset.hpp"
#include "assets/physwaterpreset.hpp"
#include "assets/physworld.hpp"
#include "assets/rawfile.hpp"
#include "assets/reverbcurve.hpp"
#include "assets/scriptabledef.hpp"
#include "assets/scriptfile.hpp"
#include "assets/skeletonscript.hpp"
#include "assets/sound.hpp"
#include "assets/soundcontext.hpp"
#include "assets/soundcurve.hpp"
#include "assets/stringtable.hpp"
#include "assets/structureddatadefset.hpp"
#include "assets/techset.hpp"
#include "assets/tracerdef.hpp"
#include "assets/ttf.hpp"
#include "assets/weaponattachment.hpp"
#include "assets/weapondef.hpp"
#include "assets/vehicledef.hpp"
#include "assets/xanim.hpp"
#include "assets/xmodel.hpp"
#include "assets/xsurface.hpp"

#include "assets/computeshader.hpp"
#include "assets/domainshader.hpp"
#include "assets/hullshader.hpp"
#include "assets/pixelshader.hpp"
#include "assets/vertexdecl.hpp"
#include "assets/vertexshader.hpp"

#include "assets/aipaths.hpp"
#include "assets/clipmap.hpp"
#include "assets/comworld.hpp"
#include "assets/fxworld.hpp"
#include "assets/gfxworld.hpp"
#include "assets/glassworld.hpp"

#include "zone.hpp"


#define TECHSET_POSTFIX "_h2"s // avoid collisions with h1 techsets/shaders
#define TECHSET_POSTFIX_H1 "_h1"s 


namespace zonetool
{
	template <typename T>
	XAssetHeader DB_FindXAssetHeader_Copy(XAssetType type, const std::string& name, ZoneMemory* mem)
	{
		auto header = DB_FindXAssetHeader_Safe(type, name);
		if (header.data)
		{
			T* newData = mem->Alloc<T>();
			memcpy(newData, header.data, sizeof(T));
			header.data = reinterpret_cast<void*>(newData);
		}
		return header;
	}

	std::string add_postfix(const std::string& str);

	void initialize();
	void start();

	extern bool dump_to_zonetool;
}



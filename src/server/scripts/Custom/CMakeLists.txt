# Copyright (C) 2013-2015 DeathCore <http://www.noffearrdeathproject.net/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

set(scripts_STAT_SRCS
  ${scripts_STAT_SRCS}
# This scripts are not yet added. Need sql for each one of them
	Custom/anti_divulgador.cpp
	Custom/anti_farm.cpp
	Custom/duelReset.cpp
	Custom/ler_spell_level.cpp
	Custom/morphs_npc.cpp
	Custom/npc_visualweapon.cpp
	Custom/Reforge.cpp
	Custom/vanilla_title_npc.cpp
	

   
)
message("  -> Prepared: Custom")

/*
 * Copyright (C) 2013-2015 DeathCore <http://www.noffearrdeathproject.net/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "ScriptMgr.h"
#include "ObjectMgr.h"
#include "MapManager.h"
#include "Chat.h"
#include "Common.h"
#include "Language.h"


uint32 aurasVip[] = {15366, 16609, 48162, 48074, 48170, 43223, 36880, 467, 69994, 33081, 24705, 26035, 48469}; // Buff Vips

class vipcommands : public CommandScript
{
public:
    vipcommands() : CommandScript("vipcommands") { }

    ChatCommand* GetCommands() const
    {
        static ChatCommand vipCommandTable[] =

        { 
	    {"Buff", SEC_VIP, true, &HandleVipBuffCommand, "", NULL},
		{ "Shop",	    SEC_VIP,     true, &HandleVipMallCommand,         "", NULL },
        { "Mudar-Raça",    SEC_VIP,  false, &HandleChangeRaceCommand,             "", NULL },
	    { "Mudar-Facção",	SEC_VIP,  false, &HandleChangeFactionCommand,		"", NULL },
	    { "Mudar-Visual",	SEC_VIP,  false, &HandleCustomizeCommand,		"", NULL },
 
            { NULL,             0,                     false, NULL,                                           "", NULL }
        };
        static ChatCommand commandTable[] =
        {
            { "Vip",	    SEC_VIP,   true, NULL,      "",  vipCommandTable},
	       { NULL,             0,                  false, NULL,                               "", NULL }
        };
        return commandTable;
    }



		static bool HandleVipBuffCommand(ChatHandler * handler, const char * args)
    {
        Player * pl = handler->GetSession()->GetPlayer();
                if(pl->InArena())
                {
                        pl->GetSession()->SendNotification("Você não pode usar este comando em arena!");
                        return false;
                }
       
                pl->RemoveAurasByType(SPELL_AURA_MOUNTED);
                for(int i = 0; i < 40; i++)
                    pl->AddAura(aurasVip[i], pl);
                handler->PSendSysMessage("|cffFFFFFF[|cffFFA500Buff Vip|cffFFFFFF] |cffFF0000Você está quase imortal!");
                return true;
 
    }

static bool HandlevipCommand(ChatHandler* handler, const char* args)
    {

        Player* me = handler->GetSession()->GetPlayer();

            me->Say("Comandos V.I.P?", LANG_UNIVERSAL);
            return true;
    }

static bool HandleChangeRaceCommand(ChatHandler* handler, const char* args)
    {

        Player* me = handler->GetSession()->GetPlayer();
		me->SetAtLoginFlag(AT_LOGIN_CHANGE_RACE);
		handler->PSendSysMessage("Relogue para mudar sua raça.");
        return true;
    }

static bool HandleChangeFactionCommand(ChatHandler* handler, const char* args)
    {

        Player* me = handler->GetSession()->GetPlayer();
		me->SetAtLoginFlag(AT_LOGIN_CHANGE_FACTION);
		handler->PSendSysMessage("Relogue para mudar sua facção.");
        return true;
    }


static bool HandleCustomizeCommand(ChatHandler* handler, const char* args)
    {

        Player* me = handler->GetSession()->GetPlayer();
		me->SetAtLoginFlag(AT_LOGIN_CUSTOMIZE);
		handler->PSendSysMessage("Relogue para mudar o seu visual.");
        return true;
    }
	
	static bool HandleVipMallCommand(ChatHandler* handler, const char* args)
    {

        Player* me = handler->GetSession()->GetPlayer();

        if (me->IsInCombat())
        {
            handler->SendSysMessage(LANG_YOU_IN_COMBAT);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // stop flight if need
        if (me->IsInFlight())
        {
            me->GetMotionMaster()->MovementExpired();
            me->CleanupAfterTaxiFlight();
        }
        // save only in non-flight case
        else
            me->SaveRecallPosition();

		me->TeleportTo(1, 4847.365234f, -2811.368408f, 1444.530029f, 6.261538f); // MapId, X, Y, Z, O
                return true;
    }

};

void AddSC_vipcommands()
{
    new vipcommands();
}
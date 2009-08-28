/*
    ------------------------------------------------------------------------------------
    LICENSE:
    ------------------------------------------------------------------------------------
    This file is part of EVEmu: EVE Online Server Emulator
    Copyright 2006 - 2008 The EVEmu Team
    For the latest information visit http://evemu.mmoforge.org
    ------------------------------------------------------------------------------------
    This program is free software; you can redistribute it and/or modify it under
    the terms of the GNU Lesser General Public License as published by the Free Software
    Foundation; either version 2 of the License, or (at your option) any later
    version.

    This program is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
    FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License along with
    this program; if not, write to the Free Software Foundation, Inc., 59 Temple
    Place - Suite 330, Boston, MA 02111-1307, USA, or go to
    http://www.gnu.org/copyleft/lesser.txt.
    ------------------------------------------------------------------------------------
    Author:     Zhur
*/

#ifndef __EVEUTILS_H__
#define __EVEUTILS_H__

#include <string>
#include <vector>
#include <map>

#include "packet_types.h"
#include "PyRep.h"

class UserError;

/*
 *
SEC = 10000000L
MIN = (SEC * 60L)
HOUR = (MIN * 60L)
DAY = (HOUR * 24L)
MONTH = (30 * DAY)
YEAR = (12 * MONTH)
*/
extern uint64 UnixTimeToWin32Time( time_t sec, uint32 nsec );
extern uint64 Win32TimeNow();
extern void Win32TimeToUnixTime( uint64 win32t, time_t &unix_time, uint32 &nsec );
extern std::string Win32TimeToString(uint64 win32t);

extern const uint64 Win32Time_Second;
extern const uint64 Win32Time_Minute;
extern const uint64 Win32Time_Hour;
extern const uint64 Win32Time_Day;
extern const uint64 Win32Time_Month;
extern const uint64 Win32Time_Year;


//makes ccp_exceptions.UserError exception
//this function is deprecated; use directly UserError class instead.
extern UserError *MakeUserError(const char *exceptionType, const std::map<std::string, PyRep *> &args = std::map<std::string, PyRep *>());
//makes UserError with type "CustomError"
extern UserError *MakeCustomError(const char *fmt, ...);

/**
 * Returns length of field of given type.
 *
 * @param[in] type Type of fields.
 * @return Length of field (in bits).
 */
extern uint8 DBTYPE_SizeOf(DBTYPE type);

/**
 * Returns length of field of given type.
 *
 * @param[in] type Type of fields.
 * @return Length of field (in bytes).
 */
extern uint8 DBTYPE_GetSize(DBTYPE type);

/**
 * Checks compatibility between DBTYPE and PyRep.
 *
 * @param[in] type DBTYPE to check.
 * @param[in] rep PyRep to check.
 * @return True if arguments are compatible, false if not.
 */
extern bool DBTYPE_IsCompatible(DBTYPE type, const PyRep &rep);

#endif




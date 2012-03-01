//
// This software is copyright by Sourcey <mail@sourcey.com> and is distributed under a dual license:
// Copyright (C) 2005 Sourcey
//
// Non-Commercial Use:
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
// 
// Commercial Use:
// Please contact mail@sourcey.com
//


#include "Sourcey/Symple/Event.h"
#include "Sourcey/Util.h"
//#include "Poco/DateTimeFormatter.h"
//#include "Poco/DateTimeFormat.h"


using namespace std;
using namespace Poco;


namespace Sourcey {
namespace Symple {


Event::Event() 
{
	setType("event");
	setTime(::time(0));
}


Event::Event(const Event& root) :
	Message(root)
{
	if (!isMember("type"))
		setType("event");
	if (!isMember("time"))
		setTime(::time(0));
}


Event::Event(const JSON::Value& root) :
	Message(root)
{
	if (!isMember("type"))
		setType("event");
	if (!isMember("time"))
		setTime(::time(0));
}


Event::~Event() 
{
}


bool Event::valid() const
{
	return Message::valid()
		&& isMember("name");
}


string Event::name() const 
{
	return get("name", "").asString();
}


/*
string Event::message() const 
{
	return get("message", "").asString();
}
*/


time_t Event::time() const 
{
	return static_cast<time_t>(get("time", 0).asDouble());
}


void Event::setName(const std::string& name)
{
	(*this)["name"] = name;
}


/*
void Event::setMessage(const string& message) 
{
	(*this)["message"] = message;
}
*/

	
void Event::setTime(time_t time) 
{
	(*this)["time"] = (double)time;
	//Poco::DateTimeFormatter::format(
	//	Poco::Timestamp::fromEpochTime(time), 
	//	Poco::DateTimeFormat::ISO8601_FORMAT);
}

	
/*
void Event::setTime(const string& time) 
{
	// no checking done
	(*this)["time"] = time;
}
*/


} // namespace Symple 
} // namespace Sourcey
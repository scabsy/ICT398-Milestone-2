#ifndef INPUTRECEIVER_H
#define INPUTRECEIVER_H

#include <irrlicht.h>
#include "driverChoice.h"

using namespace irr;
using namespace core;

class InputReceiver : public IEventReceiver
{
public:
	struct SMouseState
	{
		position2di Position;
		bool LeftButtonDown;
		bool RightButtonDown;
		SMouseState() : LeftButtonDown(false), RightButtonDown(false){}
	} MouseState;

	virtual bool OnEvent(const SEvent& event)
	{
		if(event.EventType==EET_KEY_INPUT_EVENT)
		{
			KeyIsDown[event.KeyInput.Key]=event.KeyInput.PressedDown;
		}

		if(event.EventType==EET_MOUSE_INPUT_EVENT)
		{
			switch(event.MouseInput.Event)
			{
			case EMIE_LMOUSE_PRESSED_DOWN:
				MouseState.LeftButtonDown=true;
				break;
			case EMIE_LMOUSE_LEFT_UP:
				MouseState.LeftButtonDown=false;
				break;
			case EMIE_RMOUSE_PRESSED_DOWN:
				MouseState.RightButtonDown=true;
				break;
			case EMIE_RMOUSE_LEFT_UP:
				MouseState.RightButtonDown=false;
				break;
			default:
				break;
			}
		}

		return false;
	}

	const SMouseState& GetMouseState() const
	{
		return MouseState;
	}

	virtual bool IsKeyDown(EKEY_CODE keyCode) const
	{
		return KeyIsDown[keyCode];
	}

	InputReceiver()
	{
		for (u32 i=0;i<KEY_KEY_CODES_COUNT;i++)
		{
			KeyIsDown[i]=false;
		}
	}

private:
	bool KeyIsDown[KEY_KEY_CODES_COUNT];
};

#endif
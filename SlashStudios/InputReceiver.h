#ifndef INPUTRECEIVER_H
#define INPUTRECEIVER_H

#include <irrlicht.h>
#include "driverChoice.h"

using namespace irr;
using namespace core;

/**
* @class InputReceiver
* @brief Defines the interface to define user input
* 
* @author Samuel Brownley 31691379
* @version 1.0
* @date 03/11/2017
*/

class InputReceiver : public IEventReceiver
{
public:
	/**
	* @brief Defines the MouseState struct
	*/
	struct SMouseState
	{
		position2di Position;
		bool LeftButtonDown;
		bool RightButtonDown;
		SMouseState() : LeftButtonDown(false), RightButtonDown(false){}
	} MouseState;

	/**
	* @brief On an Input event, the key state and mouse state are updated
	* @return false
	*/
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

	/**
	* @brief Returns the state of the mouse
	* @return mouse state
	*/
	const SMouseState& GetMouseState() const
	{
		return MouseState;
	}

	/**
	* @brief Returns whether the key is being pressed
	* @param keyCode - key to be checked
	* @return true is key is down
	*/
	virtual bool IsKeyDown(EKEY_CODE keyCode) const
	{
		return KeyIsDown[keyCode];
	}

	/**
	* @brief Creates default InputReceiver
	* Fills KeyIsDown with each of the possible keys in a default "up" state
	*/
	InputReceiver()
	{
		for (u32 i=0;i<KEY_KEY_CODES_COUNT;i++)
		{
			KeyIsDown[i]=false;
		}
	}

private:
	///Holds whether is key is currently pressed
	bool KeyIsDown[KEY_KEY_CODES_COUNT];
};

#endif
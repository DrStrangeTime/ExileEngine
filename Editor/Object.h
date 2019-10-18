#ifndef __OBJECT_H__
#define __OBJECT_H__

#include "Headers.h"

/* The object header contains the native macro definitions of each object type,
   and an interface for deriving objects. */

#define O_ACTOR				0
#define O_SPRITE			1
#define O_STATIC_MESH		2
#define O_SKELETAL_MESH		3
#define O_LIGHT				4
#define O_RIGID_BODY		5
#define O_CAMERA			6
#define O_CLIP				7
#define O_PARTICLE			8
#define O_PARTICLE_SYSTEM	9
#define O_EVENT				10
#define O_ANIM_SEQUENCE		11
#define O_DELAY				12
#define O_TRIGGER_VOLUME	13
#define O_BLOCK_VOLUME		14
#define O_POST_FX_VOLUME	15
#define O_PAWN				16
#define O_CONTROLLER		17
#define O_PLAYER			18
#define O_PATH_NODE			19
#define O_PATH_NODE_SYSTEM	20
#define O_ANIM_CONTROLER	21


   // Object interface
class Object
{
protected:
	uint8_t			_type;	// Object type
	bool			_active;	// Is object active?
	std::string		_name;	// Object name

public:
	Object();
	
	uint8_t&		GetType();
	bool&			GetActive();
	std::string&	GetName();

	void			SetType(uint8_t x);
	void			SetActive(bool x);
	void			SetName(std::string x);

	operator uint8_t() const
	{
		return _type;
	}

	operator bool() const
	{
		return _active;
	}

	operator std::string() const
	{
		return _name;
	}
};

#endif
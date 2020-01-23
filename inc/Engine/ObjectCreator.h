
#ifndef J2AE_OBJECTCREATOR_H
#define J2AE_OBJECTCREATOR_H

namespace J2AE
{
	class GameObject;

	class ObjectCreator
	{
	public:
		virtual ~ObjectCreator() = default;
		virtual GameObject* create() const = 0;
	protected:
		ObjectCreator() = default;
	};
}

#endif

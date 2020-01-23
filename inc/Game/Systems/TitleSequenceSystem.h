
#ifndef J2AE_TITLESEQUENCE_H
#define J2AE_TITLESEQUENCE_H

#include <Engine/Systems/System.h>
#include <Engine/Components/Component.h>

namespace J2AE
{
    class TitleSequenceSystem : public System
    {
    public:
        TitleSequenceSystem() = default;
        ~TitleSequenceSystem() override = default;

        void init() override;
        void destroy() override;
        void update() override;

        size_t getComponentLock() override
        {
            return (1 << (size_t) Component::Type::Sprite);
        }

    };
}


#endif

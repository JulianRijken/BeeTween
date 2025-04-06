#ifndef TWEENENGINE_H
#define TWEENENGINE_H

#include <memory>
#include <vector>

#include "tween.h"
#include "tween_instance.h"

// Hevaly inspried by "unity-tweens" from Jeffery Lanters
// https://github.com/jeffreylanters/unity-tweens

namespace beetween
{
    class TweenEngine final
    {
        friend class Core;

    public:
        static void Start(Tween&& tween, Node& target);
        static void Start(const Tween& tween, Node& target);

    private:
        static void Update();
        std::vector<std::unique_ptr<TweenInstance>> m_TweenInstances;
    };

}  // namespace beetween
#endif // TWEENENGINE_H

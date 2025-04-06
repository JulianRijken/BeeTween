#ifndef TWEEN_H
#define TWEEN_H

#include <functional>

#include "ease_function.h"

namespace beetween
{
    struct Tween final
    {
        double delay = 0.0;
        double from = 0.0;
        double to = 1.0;
        double duration = 1.0;
        bool ignoreTimeScale = false;
        bool invokeWhenDestroyed = false;
        EaseType easeType = EaseType::Linear;

        std::function<void()> onStart;
        std::function<void(double)> onUpdate;
        std::function<void()> onEnd;
    };
}  // namespace beetween

#endif  // TWEEN_H

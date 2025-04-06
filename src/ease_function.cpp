#include "ease_function.h"

#include <cmath>
#include <numbers>

double beetween::easeFunction::Linear(double time) { return time; }

double beetween::easeFunction::SineIn(double time) { return 1.0 - std::cos(time * std::numbers::pi / 2.0); }

double beetween::easeFunction::SineOut(double time) { return std::sin(time * std::numbers::pi / 2.0); }

double beetween::easeFunction::SineInOut(double time) { return -(std::cos(std::numbers::pi * time) - 1.0) / 2.0; }

double beetween::easeFunction::BounceOut(double time)
{
    if(time < 1.0 / CONSTANT_G)
        return CONSTANT_F * time * time;

    if(time < 2.0 / CONSTANT_G)
    {
        time -= 1.5 / CONSTANT_G;
        return (CONSTANT_F * time * time) + 0.75;
    }

    if(time < 2.5 / CONSTANT_G)
    {
        time -= 2.25 / CONSTANT_G;
        return (CONSTANT_F * time * time) + 0.9375;
    }

    time -= 2.625 / CONSTANT_G;
    return (CONSTANT_F * time * time) + 0.984375;
}

double beetween::easeFunction::BounceInOutLerp(double time)
{
    return time < 0.5 ? (1 - BounceOut(1 - (2 * time))) / 2 : (1 + BounceOut(2 * time - 1)) / 2;
}

double beetween::easeFunction::BounceInLerp(double time) { return 1 - BounceOut(1 - time); }

double beetween::easeFunction::ElasticIn(double time)
{
    return time == 0.0 ? 0.0
         : time == 1.0 ? 1.0
                       : -std::pow(2.0, 10.0 * time - 10.0) * std::sin((time * 10.0 - 10.75) * CONSTANT_D);
}

double beetween::easeFunction::ElasticOut(double time)
{
    return time == 0.0 ? 0.0
         : time == 1.0 ? 1.0
                       : std::pow(2.0, -10.0 * time) * std::sin((time * 10 - 0.75) * CONSTANT_D) + 1.0;
}

double beetween::easeFunction::ElasticInOut(double time)
{
    return time == 0.0 ? 0.0
         : time == 1.0 ? 1.0
         : time < 0.5  ? -(std::pow(2.0, 20.0 * time - 10.0) * std::sin((20.0 * time - 11.125) * CONSTANT_E)) / 2.0
                       : std::pow(2.0, -20.0 * time + 10.0) * std::sin((20.0 * time - 11.125) * CONSTANT_E) / 2.0 + 1.0;
}

double beetween::easeFunction::Evaluate(double time, EaseType type)
{
    switch(type)
    {
        case EaseType::Linear:
            return Linear(time);
        case EaseType::SineIn:
            return SineIn(time);
        case EaseType::SineOut:
            return SineOut(time);
        case EaseType::SineInOut:
            return SineInOut(time);
        case EaseType::BounceIn:
            return BounceInLerp(time);
        case EaseType::BounceOut:
            return BounceOut(time);
        case EaseType::BounceInOut:
            return BounceInOutLerp(time);
        case EaseType::ElasticIn:
            return ElasticIn(time);
        case EaseType::ElasticInOut:
            return ElasticInOut(time);
        case EaseType::ElasticOut:
            return ElasticOut(time);
    }

    return 0.0;
}

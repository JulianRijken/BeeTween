#ifndef EASEFINCTION_H
#define EASEFINCTION_H

#include <numbers>

namespace beetween
{
    enum class EaseType
    {
        Linear,
        SineIn,
        SineOut,
        SineInOut,
        BounceIn,
        BounceOut,
        BounceInOut,
        ElasticIn,
        ElasticOut,
        ElasticInOut
    };

    namespace easeFunction
    {
        static constexpr double CONSTANT_F = 7.5625;
        static constexpr double CONSTANT_G = 2.75;
        static constexpr double CONSTANT_D = 2.0 * std::numbers::pi / 3.0;
        static constexpr double CONSTANT_E = 2.0 * std::numbers::pi / 4.5;

        double Linear(double time);

        double SineIn(double time);

        double SineOut(double time);

        double SineInOut(double time);

        double BounceOut(double time);

        double BounceInLerp(double time);

        double BounceInOutLerp(double time);

        double ElasticIn(double time);

        double ElasticOut(double time);

        double ElasticInOut(double time);


        double Evaluate(double time, EaseType type);
    }  // namespace easeFunction

}  // namespace bin
#endif  // EASEFINCTION_H

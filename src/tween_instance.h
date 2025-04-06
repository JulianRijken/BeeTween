#ifndef TWEENINSTANCE_H
#define TWEENINSTANCE_H
#include "event.h"
#include "tween.h"

namespace beetween
{
    class Node;

    class TweenInstance final : public beetween::IEventListener
    {
        friend class TweenEngine;

    private:
        TweenInstance(Tween&& tween, Node& target);

        void Update();
        void Cancel();
        void OnTargetDestroyed(Node& object);

        [[nodiscard]] bool IsDecommissioned() const { return m_IsDecommissioned; }

        bool m_IsHalting{ false };
        bool m_IsDecommissioned{ false };
        bool m_HasReachedEnd{ false };
        double m_Time{ 0 };

        Node* m_Target{ nullptr };
        Tween m_Tween;
    };
}  // namespace bin
#endif // TWEENINSTANCE_H

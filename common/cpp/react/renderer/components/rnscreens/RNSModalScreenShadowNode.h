#pragma once

#include <jsi/jsi.h>
#include <react/renderer/components/rnscreens/EventEmitters.h>
#include <react/renderer/components/rnscreens/Props.h>
#include <react/renderer/components/view/ConcreteViewShadowNode.h>
#include "RNSScreenState.h"

namespace facebook {
namespace react {

JSI_EXPORT extern const char RNSModalScreenComponentName[];

using RNSModalScreenShadowNodeBase = ConcreteViewShadowNode<
    RNSModalScreenComponentName,
    RNSScreenProps,
    RNSScreenEventEmitter,
    RNSScreenState>;

class JSI_EXPORT RNSModalScreenShadowNode final
    : public RNSModalScreenShadowNodeBase {
 public:
  using RNSModalScreenShadowNodeBase::RNSModalScreenShadowNodeBase;

  Transform getTransform() const override;
  Point getContentOriginOffset(bool includeTransform) const override;
  static ShadowNodeTraits BaseTraits() {
    auto traits = RNSModalScreenShadowNodeBase::BaseTraits();
    traits.set(ShadowNodeTraits::Trait::RootNodeKind);
    return traits;
  }
};

} // namespace react
} // namespace facebook

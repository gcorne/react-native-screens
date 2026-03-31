#include "RNSModalScreenShadowNode.h"

namespace facebook {
namespace react {

extern const char RNSModalScreenComponentName[] = "RNSModalScreen";

Transform RNSModalScreenShadowNode::getTransform() const {
  auto transform = RNSModalScreenShadowNodeBase::getTransform();
  auto viewportOffset = getStateData().viewportOffset;

  if (viewportOffset.x == 0 && viewportOffset.y == 0) {
    return transform;
  }

  // Root node transforms participate in `measureInWindow` when viewport offsets
  // are requested. We append the native modal origin here to keep layout intact
  // while reporting device-window-relative coordinates.
  return transform * Transform::Translate(viewportOffset.x, viewportOffset.y, 0);
}

Point RNSModalScreenShadowNode::getContentOriginOffset(
    bool /*includeTransform*/) const {
  return getStateData().contentOffset;
}

} // namespace react
} // namespace facebook

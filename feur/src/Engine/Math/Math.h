#pragma once

namespace Mathf {

inline float lerp(float lerpValue, float minValue, float maxValue) {
    return (1-lerpValue) * minValue + lerpValue * maxValue;
}

}

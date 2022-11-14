//
// Created by Anthony Luo on 2022-10-13.
//

#ifndef ZPSW3_AM_DATATYPES_HPP
#define ZPSW3_AM_DATATYPES_HPP

#include <cassert>
#include <stdint.h>
#include <vector>

namespace AM {

template <typename T>
static constexpr T constrain(const T input, const T max, const T min) {
    assert(max > min);
    return (input > max ? max : (input < min ? min : input));
}

class StateMix {
   public:
    const float velocity_x, velocity_y, velocity_z, pitch, roll, yaw;
    StateMix(float velocity_x, float velocity_y, float velocity_z, float pitch,
             float roll, float yaw)
        : velocity_x(constrain<float>(velocity_x, 1, -1)),
          velocity_y(constrain<float>(velocity_y, 1, -1)),
          velocity_z(constrain<float>(velocity_z, 1, -1)),
          pitch(constrain<float>(pitch, 1, -1)),
          roll(constrain<float>(roll, 1, -1)),
          yaw(constrain<float>(yaw, 1, -1)) {}
};

class ActuatorConfig {
   public:
    uint8_t channel = UINT8_MAX;
    StateMix stateMix;
};

class ActuatorOutput {
   public:
    uint8_t channel;
    float percent;
};

class AttitudeManagerInput {
   public:
    const float x_dir = 0, y_dir = 0, z_dir = 0, magnitude = 0, heading = 0,
                speed = 0;
};  // TODO: What is the correct name?

}  // namespace AM

#endif  // ZPSW3_AM_DATATYPES_HPP

/**
 * @file  modules/algorithm/utils/utils.hpp
 * @brief 通用工具函数
 */

#ifndef EC_LIB_MODULES_ALGORITHM_UTILS_UTILS_HPP
#define EC_LIB_MODULES_ALGORITHM_UTILS_UTILS_HPP

#include <cmath>

#include "modules/typedefs.h"

namespace irobot_ec::modules::algorithm::utils {

/**
 * @brief  符号函数
 * @tparam T 输入值类型
 * @param  value 输入值
 * @return 正数返回1，负数返回-1，0返回0
 */
template <typename T>
int sign(const T value) {
  if (value > 0) {
    return 1;
  } else if (value < 0) {
    return -1;
  } else {
    return 0;
  }
}

/**
 * @brief  deadband函数
 * @param  value 输入值
 * @param  min_value 下限
 * @param  max_value 上限
 * @return 若输入值在规定的范围内，就返回输入值，否则返回0
 */
f32 deadline(f32 value, f32 min_value, f32 max_value);

/**
 * @brief  限幅函数
 * @param  input 输入值
 * @param  min_value 下限
 * @param  max_value 上限
 * @return 若输入值超出规定的范围，就返回最近的边界值，否则返回原值
 */
f32 constrain(f32 input, f32 min_value, f32 max_value);

/**
 * @brief   把输入值限制在一个规定的周期内
 * @note    例如输入值为370，周期为360，则输出是10
 * @param   input       输入值
 * @param   min_value   周期开始
 * @param   max_value   周期结束
 * @return              限制到一个周期内的值
 */
f32 loopConstrain(f32 input, f32 min_value, f32 max_value);

/**
 * @brief   限制输入值的绝对值
 * @tparam  T           输入值的类型
 * @param   input       输入值
 * @param   max_value   限制的最大绝对值
 * @return              限制后的值
 */
template <typename T>
T absConstrain(T input, T max_value) {
  if (input > max_value) {
    return max_value;
  } else if (input < -max_value) {
    return -max_value;
  } else {
    return input;
  }
}

/**
 * @brief 角度转弧度
 * @param deg   角度
 * @return      弧度
 */
f32 degToRad(f32 deg);

/**
 * @brief 四元数转欧拉角
 * @param q         四元数
 * @param euler     欧拉角
 */
void quatToEuler(const f32 q[4], f32 euler[3]);

}  // namespace irobot_ec::modules::algorithm::utils

#endif  // EC_LIB_MODULES_ALGORITHM_UTILS_UTILS_HPP

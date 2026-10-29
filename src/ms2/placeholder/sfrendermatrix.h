// sfrendermatrix.h - Scaleform::Render::Matrix2x4 / Matrix3x4 / Matrix4x4 for game units, from the recovered render headers
// (src/ms2/scaleform/include/render; Matrix3x4 lives in render_matrix4x4.h), not the Scaleform SDK.
//
// The Identity statics: the sfr lib units only declare them (static member in the class); the exe defines them in the game's
// static-init units, whose .text$di runs start with one dynamic initializer per matrix (unit_140105110 at 0x140105110 /
// 0x140105130 / 0x140105150, unit_140135c50 at 0x140135c50 / ...). So the template definitions live here, on the game side.
// Every other game unit has no such initializer, hence the extern template declarations; the static-init units follow them
// with their explicit instantiation definitions.
#pragma once

#include "ms2/scaleform/include/render/render_matrix2x4.h"
#include "ms2/scaleform/include/render/render_matrix4x4.h"

namespace Scaleform { namespace Render {
template<class T> Matrix2x4<T> Matrix2x4<T>::Identity;
template<class T> Matrix3x4<T> Matrix3x4<T>::Identity;
template<class T> Matrix4x4<T> Matrix4x4<T>::Identity;
extern template Matrix2x4<float> Matrix2x4<float>::Identity;
extern template Matrix3x4<float> Matrix3x4<float>::Identity;
extern template Matrix4x4<float> Matrix4x4<float>::Identity;
}}

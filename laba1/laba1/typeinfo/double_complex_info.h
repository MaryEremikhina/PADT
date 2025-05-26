#pragma once
#include "complex_info.h"
#include "double_info.h"

static ComplexTypeInfo ComplexTypeInfoDouble = {
    .mult_scalar = double_mult_scalar,
    .add = double_add,
    .subtraction = double_subtraction,
    .mult = double_mult,
    .create = double_create,
    .create_zero = double_create_zero,
    .compare = double_compare
};

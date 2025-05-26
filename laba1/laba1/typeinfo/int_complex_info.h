#pragma once
#include "complex_info.h"
#include "int_info.h"

static ComplexTypeInfo ComplexTypeInfoInt = {
    .mult_scalar = int_mult_scalar,
    .add = int_add,
    .subtraction = int_subtraction,
    .mult = int_mult,
    .create = int_create,
    .create_zero = int_create_zero,
    .compare = int_compare
};

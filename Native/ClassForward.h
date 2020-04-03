#pragma once

#include <memory>

#define CLASS_FORWARD(C)                                                                                          \
    class C;                                                                                                           \
    using C##Ptr = std::shared_ptr<C>

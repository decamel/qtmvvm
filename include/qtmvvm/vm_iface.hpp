#pragma once

#if !defined(QTMVVM_VM_IFACE_H)
#define QTMVVM_VM_IFACE_H

#include "view.hpp"

namespace qtmvvm
{
  class IViewModel
  {
  public:
    virtual ~IViewModel() = default;

    virtual setView(IView *) = 0;
  };
} // namespace 

#endif // QTMVVM_VM_IFACE_H

#pragma once

#if !defined(QTMVVM_VM_IFACE_H)
#define QTMVVM_VM_IFACE_H

namespace qtmvvm
{
  class IViewModel
  {
  public:
    virtual ~IViewModel() = default;
  };
} // namespace 

#endif // QTMVVM_VM_IFACE_H

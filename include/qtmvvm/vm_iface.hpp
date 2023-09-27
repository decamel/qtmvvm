#pragma once

#if !defined(QTMVVM_VM_IFACE_H)
#define QTMVVM_VM_IFACE_H

namespace qtmvvm
{
  template<View>
  class IViewModel
  {
  public:
    virtual ~IViewModel() = default;

    virtual setView(View *) = 0;
  };
} // namespace 

#endif // QTMVVM_VM_IFACE_H

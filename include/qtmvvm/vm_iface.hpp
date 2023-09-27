#pragma once

#if !defined(QTMVVM_VM_IFACE_H)
#define QTMVVM_VM_IFACE_H

#include <QWidget>

namespace qtmvvm
{
  class IViewModel
  {
  public:
    virtual ~IViewModel() = default;

    virtual void setView(QWidget *) = 0;
  };
} // namespace 

#endif // QTMVVM_VM_IFACE_H

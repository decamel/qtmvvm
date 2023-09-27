#pragma once

#if !defined(QTMVVM_VM_HPP)
#define QTMVVM_VM_HPP

#include <stdexcept>
#include <type_traits>
#include <memory>
/* ----------------------------------- Qt ----------------------------------- */
#include <QCoreApplication>
#include <QObject>

#include "vm_iface.hpp"
/* -------------------------------------------------------------------------- */
/*                                Widget model                                */
/* -------------------------------------------------------------------------- */
namespace qtmvvm
{
  template <class Model>
  class ViewModel
  {
  public:
    using ModelPtr = std::shared_ptr<Model>;

    ModelPtr model_;

  public:
    ViewModel(ModelPtr a_model) : model_(a_model) {}
  };
} // namespace qtmvvm

#endif // QTMVVM_VM_HPP

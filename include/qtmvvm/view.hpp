#pragma once

#if !defined(QTMVVM_VIEW_H)
#define QTMVVM_VIEW_H

#include <functional>
#include <memory>

namespace qtmvvm
{
  template <class VM>
  class IView
  {
  public:
    using VmFactory = std::function<std::unique_ptr<VM>()>;

  public:
    /**
     *  @brief Default view constructor
     *  Accepts <WidgetModel> factory function which accepts no arguments
     *  @param pfactory Pointer to a related <WidgetModel> factory
     */
    IView(VmFactory pfactory) : p_vm(pfactory())
    {
      assert(p_vm != nullptr);
    }
    virtual ~IView() = default;

  protected:
    /// @brief Pointer to the parent widget model
    std::unique_ptr<VM> p_vm;
  };
} // namespace qtmvvm

#endif // QTMVVM_VIEW_H

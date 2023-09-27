#pragma once

#if !defined(QTMVVM_VM_IFACE_H)
#define QTMVVM_VM_IFACE_H

namespace qtmvvm
{
  template <class View>
  class IViewModel
  {
  protected:
    View *view_;

  public:
    virtual ~IViewModel() = default;

    void setView(View *view)
    {
      View *viewObj = dynamic_cast<View *>(view);
      if (viewObj == 0)
      {
        throw std::runtime_error("Invalid type of view passed into WidgetModel.setView method");
      }

      view_ = viewObj;
    }
  };
} // namespace

#endif // QTMVVM_VM_IFACE_H

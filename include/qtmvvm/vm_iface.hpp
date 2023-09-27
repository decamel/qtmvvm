#pragma once

#if !defined(QTMVVM_VM_IFACE_H)
#define QTMVVM_VM_IFACE_H

namespace qtmvvm
{
  template <class View>
  class IViewModel
  {
  protected:
    IView *view_;

  public:
    virtual ~IViewModel() = default;

    void setView(IView *view) override
    {
      IView *viewObj = dynamic_cast<IView *>(view);
      if (viewObj == 0)
      {
        throw std::runtime_error("Invalid type of view passed into WidgetModel.setView method");
      }

      view_ = viewObj;
      connectView();
      refreshView();
    }
  };
} // namespace

#endif // QTMVVM_VM_IFACE_H
